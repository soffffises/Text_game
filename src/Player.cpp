#include "Player.h"

Player::Player() {
    this->name = "Nameless";
    this->hp = 25;
    this->max_hp = 100;
    this->inventory = std::vector<Item*> {
        new HealingPotion(30),
        new HealingPotion(50),
        new WandOfRenaming,
    };
    this->current_location = "Forest";
}

Player::~Player() {
    for(auto& item : this->inventory) {
        delete item;
    }
}