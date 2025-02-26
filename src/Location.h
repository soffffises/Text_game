#pragma once

#include <string>
#include <array>

struct Location {
    Location(std::string new_name, std::string new_description, std::array<std::string, 4> new_exits);

    std::string name;
    std::string description;
    std::array<std::string, 4> exits;
};