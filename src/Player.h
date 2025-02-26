#pragma once

#include <string>
#include <vector>
#include <cstdint>

#include "Item.h"

// This is a class for our player character
// This class has:
// - Name;
// - HP;
// - Inventory;
// - Current location;

class Player {
    public:
        Player();
        ~Player();
        std::string name;
        uint32_t hp;
        uint32_t max_hp;
        std::vector<Item*> inventory;
        std::string current_location = "Forest";
};