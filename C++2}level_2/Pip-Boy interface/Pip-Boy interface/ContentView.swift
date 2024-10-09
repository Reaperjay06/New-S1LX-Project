//
//  ContentView.swift
//  Pip-Boy interface
//
//  Created by SA47 on 10/7/24.
//

import SwiftUI

struct ContentView: View {
    @Binding var document: Pip_Boy_interfaceDocument

    var body: some View {
        TextEditor(text: $document.text)
    }
}

#Preview {
    ContentView(document: .constant(Pip_Boy_interfaceDocument()))
}
#include; <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>

// Constants for Pip-Boy colors
const; sf;::Color PIPBOY_BG_COLOR(3, 53, 0);      // Dark green
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

    // Inventory Button
    sf::Text inventoryText;
    inventoryText.setFont(font);
    inventoryText.setString("Inventory");
    inventoryText.setCharacterSize(32);
    inventoryText.setFillColor(PIPBOY_TEXT_COLOR);
    inventoryText.setPosition(100, 250);

    // Data Button
    sf::Text dataText;
    dataText.setFont(font);
    dataText.setString("Data");
    dataText.setCharacterSize(32);
    dataText.setFillColor(PIPBOY_TEXT_COLOR);
    dataText.setPosition(100, 300);

    // Radio Button
    sf::Text radioText;
    radioText.setFont(font);
    radioText.setString("Radio");
    radioText.setCharacterSize(32);
    radioText.setFillColor(PIPBOY_TEXT_COLOR);
    radioText.setPosition(100, 350);

    // Main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear the window with the Pip-Boy background color
        window.clear(PIPBOY_BG_COLOR);

        // Draw UI elements
        window.draw(titleText);
        window.draw(statusText);
        window.draw(inventoryText);
        window.draw(dataText);
        window.draw(radioText);

        // Display the content
        window.display();
    }

    return 0;
}
