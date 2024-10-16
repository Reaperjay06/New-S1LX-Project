#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>

// Constants for Pip-Boy colors
const sf::Color PIPBOY_BG_COLOR(3, 53, 0);      // Dark green
const sf::Color PIPBOY_TEXT_COLOR(10, 255, 0);  // Bright green
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

int main() {
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Pip-Boy Interface");

    // Set up the font
    sf::Font font;
    if (!font.loadFromFile("pipboy_font.ttf")) {
        std::cerr << "Error loading font!" << std::endl;
        return -1;
    }

    // Title Text
    sf::Text titleText;
    titleText.setFont(font);
    titleText.setString("Pip-Boy 3000");
    titleText.setCharacterSize(48);  // Large title
    titleText.setFillColor(PIPBOY_TEXT_COLOR);
    titleText.setPosition(200, 50);

    // Status Button
    sf::Text statusText;
    statusText.setFont(font);
    statusText.setString("Status");
    statusText.setCharacterSize(32);
    statusText.setFillColor(PIPBOY_TEXT_COLOR);
    statusText.setPosition(100, 200);

    // Add a rectangle shape for the button background
    sf::RectangleShape statusButton(sf::Vector2f(200, 50));
    statusButton.setFillColor(sf::Color::Transparent);
    statusButton.setPosition(100, 200);

    // ... Repeat the above steps for other buttons ...

    // Main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // Check if the user clicked on a button
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::FloatRect statusButtonRect = statusButton.getGlobalBounds();

                if (statusButtonRect.contains(mousePos.x, mousePos.y)) {
                    // Handle the status button click
                    std::cout << "Status button clicked!" << std::endl;
                }

                // ... Repeat the above steps for other buttons ...
            }
        }

        // Clear the window with the Pip-Boy background color
        window.clear(PIPBOY_BG_COLOR);

        // Draw UI elements
        window.draw(titleText);
        window.draw(statusButton);
        window.draw(statusText);
        // ... Repeat the above steps for other buttons ...

        // Display the content
        window.display();
    }

    return 0;
}