#include "Location.h"

Location::Location(std::string new_name, std::string new_description, std::array<std::string, 4> new_exits):
    name(new_name),
    description(new_description),
    exits(new_exits) {
}