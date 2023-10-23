// Copyright 2023
// By Vasu Patel
// Editted by Vasu Patel
// main.cpp for PS3
// updated 10/13/2023

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Network.hpp>
#include "Universe.hpp"

int main()
{
    // Create a new SFML window
    sf::RenderWindow window(sf::VideoMode(800, 600), "N-Body Simulation");

    // Load the universe from a file
    Universe universe;
    universe.LoadFromFile("universe.txt");

    // Setup the main draw loop
    while (window.isOpen())
    {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // Update the universe
        universe.Update();

        // Draw the universe
        window.clear(sf::Color::Black);
        universe.Draw(window);
        window.display();
    }

    return 0;
}
