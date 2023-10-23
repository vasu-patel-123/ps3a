#ifndef UNIVERSE_HPP
#define UNIVERSE_HPP
// Copyright 2023
// By Vasu Patel
// Editted by Vasu Patel
// Universe.hpp for PS3
// updated 10/13/2023

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <vector>
#include "CelestialBody.hpp"

class Universe
{
public:
    Universe();
    virtual ~Universe();

    void LoadFromFile(const std::string& filename);
    void Update();
    void Draw(sf::RenderWindow& window);

private:
    std::vector<CelestialBody*> bodies_;
    sf::Texture texture_;
    float dt;
};

#endif
