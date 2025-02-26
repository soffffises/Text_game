#include "Item.h"
#include "World.h"
#include "Utils.h"

#include <sstream>
#include <iostream>
#include <fmt/core.h>

Item::Item(std::string new_name, std::string new_description): name(new_name), description(new_description) {}


HealingPotion::HealingPotion(uint32_t new_power): healing_power(new_power), Item("Healing Potion", "A potent potion that heals its user.") {}

void HealingPotion::use(World& world) {
    uint32_t heal = ((world.p.hp + this->healing_power <= world.p.max_hp) ? this->healing_power : (world.p.max_hp - world.p.hp));
    world.p.hp += heal;

    fmt::print("{}", this->use_message({ (std::stringstream() << heal).str() }));
}

std::string HealingPotion::to_string() {
    std::stringstream ss;
    ss << this->name << "(" << this->healing_power << ")";

    return ss.str();
}

std::string HealingPotion::use_message(std::vector<std::string> args) {
    if(args.size() < 1) {
        throw "HealingPotion::use_message(): expected at least 1 argument, the restored HP count!";
    }

    std::stringstream ss;
    ss << "You drink a healing potion. It restores " << args[0] << " HP!";

    return ss.str();
}

bool HealingPotion::is_consumable() { return true; }


// void RenameCommand::execute(std::vector<std::string>& args, World& world) {
//     if(args.size() == 1) {
//         fmt::print("Rename player to what?");
//     } else if(args.size() > 2) {
//         fmt::print("You can only name yourself one thing, not multiple!");
//     }

//     world.p.name = args[1];
//     fmt::print("Your name is now {}!", world.p.name);
// }

WandOfRenaming::WandOfRenaming(): Item("Wand of Renaming", "A wand that can grant the user a new name.") {}

bool WandOfRenaming::is_consumable() {
    return false;
}

std::string WandOfRenaming::to_string() {
    return this->name;
}

// TODO: Sanitize the string, removing whitespaces before and after the name
// TODO: Make sure that the user actually inputs the name
void WandOfRenaming::use(World& world) {
    std::string new_name;
    fmt::print("You've just used Wand of Renaming. What name would you like to have? => ");
    std::getline(std::cin, new_name);

    new_name = join(split(new_name));
    if(!new_name.empty()) {
        world.p.name = new_name;
    }
    fmt::print("{}", this->use_message({new_name}));
}

std::string WandOfRenaming::use_message(std::vector<std::string> args) {
    if(args.size() == 0 || args[0].empty()) {
        return "You haven't been granted a new name as you didn't give a name to change your old one to! Please give the wand your desired name.";
    }

    return (std::stringstream() << "You have been granted a new name! You are known as " << args[0] << " now!").str();
}