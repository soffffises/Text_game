#include <iostream>
#include <vector>
#include <sstream>
#include <cctype>

#include <fmt/core.h>
#include <fmt/color.h>
#include <nlohmann/json.hpp>

#include "Command.h"
#include "World.h"


int main() {
    std::string user_input;
    std::vector<std::string> words;
    World w;
    CommandExecutor exec;
    fmt::print("Player stats:\n- Name: {}\n- HP: {}\n- Current Location: {}\n\n", w.p.name, w.p.hp, w.p.current_location);
    do {
        fmt::print("=> ");

        std::getline(std::cin, user_input);
        for(char& ch: user_input) {
            ch = std::tolower(ch);
        }
        words = split(user_input);

        exec.execute(words, w);
        
        if(words.size() != 0) {
            fmt::print("\n\n");
        }
    } while(true);

    return 0;
}
