#include "generator.hpp"
#include <iomanip>
#include <iostream>


// 83456 -> "01:23.456"
void printTime(TimeMs t){
    std::cout << std::setfill('0')
              << std::setw(2) << t / 60'000 << ':'
              << std::setw(2) << t / 1000 % 60 << '.'
              << std::setw(3) << t % 1000
              << std::setfill(' ');
}

int main(){
    GeneratorParams params{.floors = 5, .peoplePerMinute = 5, .simulationLength = 120000};
    std::vector<Request> requests = generateRequests(1, params);

    std::cout << "    id      time    from -> to\n";
    for(const Request& r : requests){
        std::cout << std::setw(6) << r.id << "  ";
        printTime(r.showUpTime);
        std::cout << std::setw(8) << r.startFloor << " -> " << r.endFloor << '\n';
    }
    std::cout << "\nTotal requests: " << requests.size() << '\n';
}