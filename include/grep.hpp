#ifndef GREP_HPP
#define GREP_HPP

#include "regex.hpp"
#include <string>
#include <fstream>
#include <sstream>

State* get_regex_nfa(std::string& pattern);

#endif