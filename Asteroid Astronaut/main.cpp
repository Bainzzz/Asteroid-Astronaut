#include <iostream>
#include <vector>
#include <cctype> // for toupper
#include <conio.h> // for kbhit and getch (Windows)
#include <windows.h> // for Sleep and GetTickCount
#include <algorithm> // for remove_if

class Entity {
public:
    int x, y; // Position
    char symbol; // ASCII symbol

    Entity(int startX, int startY, char sym) : x(startX), y(startY), symbol(sym) {}

    virtual void update() = 0; // Pure virtual for polymorphism
    virtual ~Entity() = default; // Virtual destructor for safe inheritance
};

class Player : public Entity {
public:
    float speed = 1.0f; 

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

int main() {
    const int SCREEN_WIDTH = 35;      //terminal screen size
    const int SCREEN_HEIGHT = 10;

    Player player(SCREEN_WIDTH / 2, SCREEN_HEIGHT - 1); //start at center bottom
    std::vector<Bullet> bullets;
    bool running = true;

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

        for (auto& bullet : bullets) {   //update bullets
            bullet.update();
        }

        bullets.erase(std::remove_if(bullets.begin(), bullets.end(), [SCREEN_WIDTH](const Bullet& b) {   //remove bullets that have left the screen 
            return b.x >= SCREEN_WIDTH;
            }), bullets.end());

        std::vector<std::string> screen(SCREEN_HEIGHT, std::string(SCREEN_WIDTH, '.'));
        screen[player.y][player.x] = player.symbol;

        for (const auto& bullet : bullets) {      //draw bullets
            if (bullet.x >= 0 && bullet.x < SCREEN_WIDTH && bullet.y >= 0 && bullet.y < SCREEN_HEIGHT) {
                screen[bullet.y][bullet.x] = bullet.symbol;
            }
        }

        for (const auto& line : screen) {
            std::cout << line << '\n';
        }

        //frame delay to reduce flashing 
        Sleep(150); 
    }

    std::cout << "Game ended!\n";

    return 0;
}