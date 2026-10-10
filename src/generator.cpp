#include "generator.hpp"
#include <cassert>
#include <random>
#include <cmath>


std::vector<Request> generateRequests(uint32_t seed, const GeneratorParams& params, const BuildingParams& buildingParams){
    assert(buildingParams.floors >= 2);
    assert(params.peoplePerMinute > 0);
    std::mt19937 rng(seed);
    std::exponential_distribution<double> gapDist(params.peoplePerMinute / 60'000.0);
    std::uniform_int_distribution<int> startFloorDist(0, buildingParams.floors - 1);
    std::uniform_int_distribution<int> endFloorDist(0, buildingParams.floors - 2);

    std::vector<Request> requests;
    TimeMs currTime = 0;
    int currId = 0;
    while(true){
        double gapDouble = gapDist(rng);
        TimeMs gapMs = static_cast<TimeMs>(std::lround(gapDouble));
        TimeMs nextPersonTime = gapMs + currTime;
        if(nextPersonTime > params.simulationLength) break;

        int startFloor = startFloorDist(rng);
        int endFloor = endFloorDist(rng);
        if(endFloor >= startFloor) endFloor++;

        Request request{.id = currId, .showUpTime = nextPersonTime, .startFloor = startFloor, .endFloor = endFloor};
        requests.push_back(request);
        currTime = nextPersonTime;
        currId++;
    }
    return requests;
}
