#pragma once

#include "Player.h"
#include "Location.h"

#include <vector>

std::vector<Location> init_places();

struct World {
    Location& get_current_location();

    Player p;
    std::vector<Location> places = init_places();
};