#pragma once
#include <vector>
#include <cstdint>
#include "request.hpp"
#include "buildingParams.hpp"


struct GeneratorParams{
    double peoplePerMinute = 4;
    TimeMs simulationLength = 120000;
};


std::vector<Request> generateRequests(uint32_t seed, const GeneratorParams& params, const BuildingParams& buildingParams);
