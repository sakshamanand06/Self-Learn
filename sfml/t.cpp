#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

// Global variables
std::vector<std::string> menuOptions = {"Start Game", "Instructions", "Settings", "Exit"};
int activeMenuIndex = 0;
sf::Font font;

// Function declarations
void drawMenu(sf::RenderWindow& window);
void moveUp();
void moveDown();

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Ultimate Tic Tac Toe Menu");
    font.loadFromFile("Purisa-Bold.ttf");
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up) moveUp();
                if (event.key.code == sf::Keyboard::Down) moveDown();
                if (event.key.code == sf::Keyboard::Enter) {
                    // Handle selection
                }
            }
        }

        window.clear();
        drawMenu(window);
        window.display();
    }
    return 0;
}

void drawMenu(sf::RenderWindow& window) {
    for (size_t i = 0; i < menuOptions.size(); ++i) {
        sf::Text text;
        text.setFont(font);
        text.setString(menuOptions[i]);
        text.setPosition(100, 100 + i * 50);
        text.setFillColor(i == activeMenuIndex ? sf::Color::Red : sf::Color::White);
        window.draw(text);
    }
}

void moveUp() {
    if (activeMenuIndex > 0) activeMenuIndex--;
}

void moveDown() {
    if (activeMenuIndex < menuOptions.size() - 1) activeMenuIndex++;
}
