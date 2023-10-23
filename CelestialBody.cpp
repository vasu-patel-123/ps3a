// Copyright 2023
// By Vasu Patel
// Editted by Vasu Patel
// CelestialBody.cpp for PS3
// updated 10/13/2023

#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "CelestialBody.hpp"

CelestialBody::CelestialBody() : x(0.0f), y(0.0f), vx(0.0f), vy(0.0f), mass(0.0f) {}

CelestialBody::CelestialBody(float _x, float _y, float _vx, float _vy, float _mass, std::string _imageFile) {
    x = _x;
    y = _y;
    vx = _vx;
    vy = _vy;
    mass = _mass;
    imageFile = _imageFile;
}

CelestialBody::~CelestialBody() {}

void CelestialBody::update(float dt) {
    // Update position and velocity based on the rules of motion
    vx += ax * dt;
    vy += ay * dt;
    vx += (ax * mass / (x * x + y * y)) * dt;
    vy += (ay * mass / (x * x + y * y)) * dt;
}

void CelestialBody::draw(sf::RenderWindow& window, sf::Texture& texture, float dt) {
    // Create a sprite and set its position, velocity, and image texture
    x += vx * dt;
    y += vy * dt;
    sf::Sprite sprite;
    sprite.setScale(0.5f, 0.5f);
    sprite.setPosition(x + vx, y + vy);
    sprite.setTexture(texture);

    // Draw the sprite on the window
    window.draw(sprite);
}
