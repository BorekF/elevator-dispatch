#pragma once
#include "types.hpp"


struct BuildingParams{
    int floors = 10;
    int elevators = 2;
    int capacity = 6;
    TimeMs floorTime = 1500; // time to go from one floor to the next one
    TimeMs openDoorsTime = 5000;
};
