#include "../include/grep.hpp"

State* get_regex_nfa(std::string& pattern){
    std::string postfix_expr = regex_to_postfix(pattern);
    State* nfa_start = postfix_to_nfa(postfix_expr);
    return nfa_start;
}