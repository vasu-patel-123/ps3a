// Copyright 2023
// By Vasu Patel
// Editted by Vasu Patel
// Universe.cpp for PS3
// updated 10/13/2023
#include "Universe.hpp"
#include "CelestialBody.hpp"
#include <cstdio>
#include <cstdlib>
#include <cstring>

Universe::Universe() {
    // Initialize the texture
    texture_.loadFromFile("texture.png");
}

Universe::~Universe() {
    for (size_t i = 0; i < bodies_.size(); ++i) {
        delete bodies_[i];
    }
}
void Universe::LoadFromFile(const std::string& filename)
{
    // Open the file
    FILE* file = fopen(filename.c_str(), "r");
    if (!file) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename.c_str());
        return;
    }

    // Read the number of planets
    int numPlanets;
    fscanf(file, "%d", &numPlanets);

    // Read the radius of the universe
    float radius;
    fscanf(file, "%f", &radius);

    // Clear any previous bodies
    bodies_.clear();

    // Iterate over the planets
    for (int i = 0; i < numPlanets; ++i) {
        // Read the planet data
        float x, y, vx, vy, mass;
        char name[64];
        fscanf(file, "%f %f %f %f %f %64s", &x, &y, &vx, &vy, &mass, name);

        // Create a new CelestialBody and add it to the universe
        CelestialBody* body = new CelestialBody(x, y, vx, vy, mass, name);
        bodies_.push_back(body);
    }
    

    fclose(file);
}

void Universe::Update()
{
    // TODO: Implement gravity and motion
}

void Universe::Draw(sf::RenderWindow& window)
{
    // Draw each CelestialBody in the universe
    for (size_t i = 0; i < bodies_.size(); ++i)
    {
        bodies_[i]->draw(window, texture_, dt);
    }
}
