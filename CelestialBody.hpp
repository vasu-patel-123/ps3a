#ifndef CELESTIAL_BODY_HPP
#define CELESTIAL_BODY_HPP
// Copyright 2023
// By Vasu Patel
// Editted by Vasu Patel
// CelestialBody.hpp for PS3
// updated 10/13/2023
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics.hpp>
#include <tuple>
#include <vector>
#include <string>
#include <iostream>

class CelestialBody {
public:
    CelestialBody();
    CelestialBody(float x, float y, float vx, float vy, float mass, std::string imageFile);
    ~CelestialBody();

    void update(float dt);
    void draw(sf::RenderWindow& window, sf::Texture& texture, float dt);
    float ax; 
    float ay;
    float x, y;
    float vx, vy;
    float mass;
    std::string imageFile;
};

#endif
