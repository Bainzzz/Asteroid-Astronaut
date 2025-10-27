#include <iostream>
#include <vector>
#include <cctype> 
#include <conio.h> 
#include <windows.h> 
#include <algorithm> 
#include <iomanip>
#include <fstream>

class Entity {
public:
    int x, y; // Position
    char symbol; // ASCII symbol

    Entity(int startX, int startY, char sym) : x(startX), y(startY), symbol(sym) {}

    virtual void update() = 0; //pure virtual for polymorphism
    virtual ~Entity() = default; // virtual destructor for safe inheritance
};

class Player : public Entity {
public:
    float speed = 1.0f;
    int lives = 3;  //gives player 3 lives 

    Player(int startX, int startY) : Entity(startX, startY, '>') {}

    void update() override {

    }


    void move(char input, int screenWidth, int screenHeight) {
        int newX = x, newY = y;

        switch (std::toupper(input)) {
        case 'W': newY -= static_cast<int>(speed); break;      //player movement
        case 'A': newX -= static_cast<int>(speed); break;
        case 'S': newY += static_cast<int>(speed); break;
        case 'D': newX += static_cast<int>(speed); break;
        default: return;        //no movement for invalid input
        }

        if (newX >= 0 && newX < screenWidth) x = newX;    //boundary checks
        if (newY >= 0 && newY < screenHeight) y = newY;

    }
};

class Bullet : public Entity {
public:
    Bullet(int startX, int startY) : Entity(startX, startY, 'O') {}

    void update() override {
        x += 1; //move bullets right across the screen
    }
};

class Asteroid : public Entity {
public:
    bool moveThisFrame = false; 

    Asteroid(int startX, int startY) : Entity(startX, startY, '@') {}

    void update() override {
        moveThisFrame = !moveThisFrame; //alternate frames
        if (moveThisFrame) {
            x -= 1; //move asteroids left toward the player
        }
    }
};

void loadHighScores(std::vector<int>& highScores) {         //loads high scores from file
    std::ifstream inFile("highscores.txt");
    highScores.assign(5, 0);         //reset to 0 in case file is missing or incomplete
    if (inFile.is_open()) {
        for (int i = 0; i < 5 && inFile >> highScores[i]; ++i) {}
        inFile.close();
    }
}

void saveHighScores(const std::vector<int>& highScores) {       //saves high scores to file
    std::ofstream outFile("highscores.txt");
    if (outFile.is_open()) {
        for (int i = 0; i < 5; ++i) {
            outFile << highScores[i];
            if (i < 4) outFile << " ";
        }
        outFile.close();
    }
}

int main() {
    const int SCREEN_WIDTH = 35;      //terminal screen size
    const int SCREEN_HEIGHT = 10;

    Player player(SCREEN_WIDTH / 2, SCREEN_HEIGHT - 1); //start at center bottom
    std::vector<Bullet> bullets;
    std::vector<Asteroid> asteroids;
    bool running = true;
    int score = 0; //player score 0
    std::vector<int> highScores(5, 0);
    loadHighScores(highScores);    //loads high scores at start 


    // shooting cooldown variables
    const int SHOOT_DELAY_MS = 500; // 500ms (0.5 seconds) delay between shots
    DWORD lastShotTime = 0;

    while (running) {
        //clear terminal
        std::system("cls");

        if (_kbhit()) {
            char input = _getch();
            if (std::toupper(input) == 'Q') {
                running = false; // quit game
            }
            else if (input == ' ') {
                //check if enough time has passed since the last shot
                DWORD currentTime = GetTickCount64();
                if (currentTime - lastShotTime >= SHOOT_DELAY_MS) {
                    bullets.emplace_back(player.x + 1, player.y); //shoot bullet from player's position
                    lastShotTime = currentTime; //update the last shot time
                }
            }
            else {
                player.move(input, SCREEN_WIDTH, SCREEN_HEIGHT);
            }
        }

        //spawn asteroids randomly
        if (rand() % 10 == 0) { //random chance to spawn an asteroid, increased frequency
            int startY = rand() % SCREEN_HEIGHT; //random y position
            asteroids.emplace_back(SCREEN_WIDTH - 1, startY); //spawn at right edge
        }

        for (auto& bullet : bullets) {   //update bullets
            bullet.update();
        }

        for (auto& asteroid : asteroids) {   //update asteroids
            asteroid.update();
        }

        //check for bullet-asteroid collisions
        for (auto itBullet = bullets.begin(); itBullet != bullets.end();) {
            bool bulletHit = false;
            for (auto itAsteroid = asteroids.begin(); itAsteroid != asteroids.end();) {
                if (itBullet->x == itAsteroid->x && itBullet->y == itAsteroid->y) {
                    itAsteroid = asteroids.erase(itAsteroid); //remove asteroid on hit
                    bulletHit = true; //mark bullet for removal
                    score += 10;  //increase score 
                    break;
                }
                else {
                    ++itAsteroid;
                }
            }
            if (bulletHit) {
                itBullet = bullets.erase(itBullet); //remove bullet after hitting asteroid
            }
            else {
                ++itBullet;
            }
        }

        for (auto asteroidCheck = asteroids.begin(); asteroidCheck != asteroids.end();) {
            if (player.x == asteroidCheck->x && player.y == asteroidCheck->y) {
                player.lives -= 1; //reduce player lives on hit
                asteroidCheck = asteroids.erase(asteroidCheck);
            }
            else {
                ++asteroidCheck;
            }
        }
            

        bullets.erase(std::remove_if(bullets.begin(), bullets.end(), [SCREEN_WIDTH](const Bullet& b) {   //remove bullets that have left the screen 
            return b.x >= SCREEN_WIDTH;
            }), bullets.end());

        asteroids.erase(std::remove_if(asteroids.begin(), asteroids.end(), [SCREEN_WIDTH](const Asteroid& a) {   //remove asteroids that have left the screen 
            return a.x < 0;
            }), asteroids.end());

        std::cout << "Lives: " << player.lives;  //displays lives
        std::cout << std::setw(SCREEN_WIDTH - 10) << std::right << "Score: " << score << "\n";  //displays score

        std::cout << "High Scores: ";
        for (int i = 0; i < 5; ++i) {
            std::cout << highScores[i];
            if (i < 4) std::cout << ", ";
        }
        std::cout << "\n";

        std::vector<std::string> screen(SCREEN_HEIGHT, std::string(SCREEN_WIDTH, '.'));
        screen[player.y][player.x] = player.symbol;

        for (const auto& bullet : bullets) {      //draw bullets
            if (bullet.x >= 0 && bullet.x < SCREEN_WIDTH && bullet.y >= 0 && bullet.y < SCREEN_HEIGHT) {
                screen[bullet.y][bullet.x] = bullet.symbol;
            }
        }

        for (const auto& asteroid : asteroids) {      //draw asteroids
            if (asteroid.x >= 0 && asteroid.x < SCREEN_WIDTH && asteroid.y >= 0 && asteroid.y < SCREEN_HEIGHT) {
                screen[asteroid.y][asteroid.x] = asteroid.symbol;
            }
        }

        for (const auto& line : screen) {
            std::cout << line << '\n';
        }

        if (player.lives <= 0) {
            running = false; //endg game at 0 lives 
        }

        //frame delay to reduce flashing 
        Sleep(150);
    }

    if (score > *std::min_element(highScores.begin(), highScores.end())) {
        if (std::find(highScores.begin(), highScores.end(), score) == highScores.end()) {
            highScores.push_back(score);
            std::sort(highScores.begin(), highScores.end(), std::greater<int>());
            highScores.resize(5);
            saveHighScores(highScores); //saves updated high scores
        }
    }

    std::cout << "Game ended!\n";

    return 0;
}