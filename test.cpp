// Copyright 2023
// By Vasu Patel
// Editted by Vasu Patel
// test.cpp for PS3
// updated 10/13/2023


#include <boost/test/unit_test.hpp>
#include "Universe.hpp"
#include "CelestialBody.hpp"

BOOST_AUTO_TEST_SUITE(TestNBodySimulation)

BOOST_AUTO_TEST_CASE(NumPlanets)
{
    Universe universe(2);
    universe.LoadFromFile("universe.txt");
    BOOST_CHECK_EQUAL(universe.GetNumPlanets(), 2);
}

BOOST_AUTO_TEST_CASE(UniverseSize)
{
    Universe universe(2);
    universe.LoadFromFile("universe.txt");
    BOOST_CHECK_EQUAL(universe.GetUniverseSize(), 200.0f);
}

BOOST_AUTO_TEST_CASE(FirstPlanetProperties)
{
    Universe universe(2);
    universe.LoadFromFile("universe.txt");
    BOOST_CHECK_EQUAL(universe.GetPlanet(0)->GetMass(), 100.0f);
    BOOST_CHECK_EQUAL(universe.GetPlanet(0)->GetPositionX(), 10.0f);
    BOOST_CHECK_EQUAL(universe.GetPlanet(0)->GetPositionY(), 20.0f);
    BOOST_CHECK_EQUAL(universe.GetPlanet(0)->GetVelocityX(), 30.0f);
    BOOST_CHECK_EQUAL(universe.GetPlanet(0)->GetVelocityY(), 40.0f);
}

BOOST_AUTO_TEST_CASE(SecondPlanetProperties)
{
    Universe universe(2);
    universe.LoadFromFile("universe.txt");
    BOOST_CHECK_EQUAL(universe.GetPlanet(1)->GetMass(), 100.0f);
    BOOST_CHECK_EQUAL(universe.GetPlanet(1)->GetPositionX(), 30.0f);
    BOOST_CHECK_EQUAL(universe.GetPlanet(1)->GetPositionY(), 40.0f);
    BOOST_CHECK_EQUAL(universe.GetPlanet(1)->GetVelocityX(), 50.0f);
    BOOST_CHECK_EQUAL(universe.GetPlanet(1)->GetVelocityY(), 60.0f);
}

BOOST_AUTO_TEST_SUITE_END()
