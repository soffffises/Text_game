#include "Utils.h"

// "show my inventory" => ["show", "my", "inventory"]
std::vector<std::string> split(const std::string& command) {
    std::stringstream ss(command);
    std::vector<std::string> result;
    std::string word;

    while(ss >> word) {
        result.push_back(word);
    }
        
    return result;
}

// ["show", "my", "inventory"], " " => "show my inventory"
std::string join(const std::vector<std::string>& strings, const std::string& delim) {
    std::stringstream ss;

    for(int i = 0; i < strings.size(); i++) {
        ss << strings[i];
        if(i != strings.size() - 1) {
            ss << delim;
        }
    }

    return ss.str();
}