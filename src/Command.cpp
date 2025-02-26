#include "Command.h"
#include "fmt/core.h"

#include <cstdlib>
#include <sstream>
#include <algorithm>
#include <vector>
#include <iostream>

CommandExecutor::CommandExecutor(): command_mapping({
    {"show", new ShowCommand()},
    {"exit", new ExitCommand()},
    {"where", new WhereCommand()},
    {"describe", new DescribeCommand()},
    {"go", new GoCommand()},
    {"use", new UseCommand()},
    {"", new UnknownCommand()},
}) {

}

CommandExecutor::~CommandExecutor() {
    for(auto& pair : this->command_mapping) {
        delete pair.second;
    }
}

void CommandExecutor::execute(std::vector<std::string>& args, World& world) {
    if(args.size() == 0) {
        return;
    }

    this->command_mapping[(this->command_mapping.contains(args[0]) ? args[0] : "")]->execute(args, world);
}

// This function can be used instead of the lambda in the show inventory section of the ShowCommand.
// We're using lambda in this case because it doesn't require declaring any additional functions, it just works.
// std::string process_item(Item* item) {
//     return item->name;
// }

// show hp
// show inventory
// show name
void ShowCommand::execute(std::vector<std::string>& args, World& world) {
    if(args.size() == 1) {
        fmt::print("Show what exactly?..");
    } else if(args.size() == 2) {
        if(args[1] == "hp") {
            fmt::print("Player's HP: {}/{}", world.p.hp, world.p.max_hp);
        } else if(args[1] == "name") {
            fmt::print("Player's name: {}", world.p.name);
        } else if(args[1] == "inventory") {
            std::vector<std::string> names;
            names.resize(world.p.inventory.size());
            names.reserve(world.p.inventory.size());
            std::transform(world.p.inventory.begin(), world.p.inventory.end(), names.begin(), [](auto& item){
                return item->to_string();
            });

            std::stringstream ss;
            ss << "\n";
            for(uint32_t i = 0; i < world.p.inventory.size(); i++) {
                ss << i + 1 << ": " << names[i] << ";\n";
            }

            fmt::print("You have {} in your inventory.", ((!world.p.inventory.empty()) ? ss.str() : "nothing"));

        } else if(args[1] == "exits") {
            std::stringstream ss;
            auto& exits = world.get_current_location().exits;
            std::vector<std::string> exit_names = {"North", "East", "South", "West"};
            bool all_empty = true;
            for(int i = 0; i < 4; i++) {
                if(!exits[i].empty()) {
                    ss << exit_names[i] << ": " << exits[i] << ";\n";
                    all_empty = false;
                }
            }

            fmt::print("{}", ss.str());
            if(all_empty) {
                throw "ERROR: ShowCommand::execute(): exits: NO EXITS EXIST FOR LOCATION?!";
            }
        } else {
            fmt::print("Don't know how to show '{}'!", args[1]);
        }
    } else {
        fmt::print("Can only show one thing at a time!");
    }
}

void ExitCommand::execute(std::vector<std::string>& args, World& world) {
    fmt::print("Thanks for playing, see you later!\n\n");

    std::exit(0);
}

void WhereCommand::execute(std::vector<std::string>& args, World& world) {
    if(args.size() == 3 && args[1] == "am" && args[2] == "i") {
        fmt::print("You are in the {} now.", world.p.current_location);
    } else {
        fmt::print("Where what? (you may have meant `where am i`)");
    }
}

void DescribeCommand::execute(std::vector<std::string>& args, World& world) {
    if(args.size() == 2 && args[1] == "area") {
        auto& loc = world.get_current_location();
        fmt::print("You are in {}. {}", loc.name, loc.description);
    } else {
        fmt::print("Describe what? (you may have meant `describe area`)");
    }
}


// TODO: solve the corner case where you could get a non-existant location in the exits array.
void GoCommand::execute(std::vector<std::string>& args, World& world) {
    if(args.size() != 2) {
        fmt::print("Can only go to one place at a time!");
        return;
    }

    auto& exits = world.get_current_location().exits;
    if(args[1] == "north") {
        if(!exits[0].empty()) {
            world.p.current_location = exits[0];
            fmt::print("You went North, to {}.", world.p.current_location);
        } else {
            fmt::print("There's no exit to the North!");
        }
    } else if(args[1] == "east") {
        if(!exits[1].empty()) {
            world.p.current_location = exits[1];
            fmt::print("You went East, to {}.", world.p.current_location);
        } else {
            fmt::print("There's no exit to the East!");
        }
    } else if (args[1] == "south") {
        if(!exits[2].empty()) {
            world.p.current_location = exits[2];
            fmt::print("You went South, to {}.", world.p.current_location);
        } else {
            fmt::print("There's no exit to the South!");
        }
    } else if (args[1] == "west") {
        if(!exits[3].empty()) {
            world.p.current_location = exits[3];
            fmt::print("You went West, to {}.", world.p.current_location);
        } else {
            fmt::print("There's no exit to the West!");
        }
    } else {
        fmt::print("Can only go north, south, east or west!");
        return;
    }
}

// TODO: develop 1-2 more types of items so that they influence the world in different ways.
// TODO: develop the possibility of locations randomly having an item to pick up in them.
void UseCommand::execute(std::vector<std::string>& args, World& world) {
    if(args.size() != 2) {
        fmt::print("Please use one item and one only: one of the numbers shown in the `show inventory` command!");
        return;
    }
    int inventory_index = -1;
    try {
        inventory_index = std::stoi(args[1]);
        if(inventory_index < 1 || inventory_index > world.p.inventory.size()) {
            fmt::print("Sorry, `{}` is out of range! (Please see `show inventory` and choose a valid item from there!)", inventory_index);
            return;
        }
        world.p.inventory[inventory_index - 1]->use(world);
        if(world.p.inventory[inventory_index - 1]->is_consumable()) {
            auto it = world.p.inventory.begin() + (inventory_index - 1);
            world.p.inventory.erase(it);
        }
    } catch(...) {
        fmt::print("Sorry, `{}` is not a valid item index! (Please use `show inventory` command)", inventory_index);
        return;
    }
}

void UnknownCommand::execute(std::vector<std::string>& args, World& world) {
    fmt::print("ERROR: Don't know how to '{}'!", args[0]);
}