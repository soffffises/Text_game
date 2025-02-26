#include "World.h"

std::vector<Location> init_places() {
    std::vector<Location> result;

    result.push_back(Location("Forest", "A beatiful forest with sunshine filtering through the trees.", {"Cave", "", "Square", "Trading Outpost"}));
    result.push_back(Location("Square", "A square bustling with people and traders.", {"Forest", "", "", ""}));
    result.push_back(Location("Trading Outpost", "An outpost of traveling merchants. You can buy new supplies here.", {"", "Forest", "Cave", ""}));
    result.push_back(Location("Cave", "An ominous cave with howls and echoes heard from time to time.", {"Trading Outpost", "", "Forest", ""}));

    return result;
}

Location& World::get_current_location() {
    for(auto& loc : this->places) {
        if(loc.name == this->p.current_location) {
            return loc;
        }
    }

    throw "ERROR: unreachable code: World::get_current_location(): current_location is a place that does not exist?!";
}