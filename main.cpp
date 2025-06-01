#include "include/grep.hpp"

int main(int argc, char** argv){
    std::string pattern = argv[1];
    //std::string file_name = argv[2];
    std::string temp_string = argv[2];
    State* regex_nfa_start = get_regex_nfa(pattern);

    std::vector<State*> l1;
    std::vector<State*> l2;
    
    bool matched = match(regex_nfa_start, temp_string, l1, l2);
    std::cout << "matched\n";

    std::unordered_set<State*> visited_states;
    delete_state_objects(regex_nfa_start, visited_states);
    return 0;
}