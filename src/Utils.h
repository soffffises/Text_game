#ifndef _UTILS_H_
#define _UTILS_H_

#include <sstream>
#include <vector>
#include <string>

// "show my inventory" => ["show", "my", "inventory"]
std::vector<std::string> split(const std::string& command);

// ["show", "my", "inventory"], " " => "show my inventory"
std::string join(const std::vector<std::string>& strings, const std::string& delim = " ");

#endif