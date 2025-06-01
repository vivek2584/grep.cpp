#include "include/grep.hpp"

int main(int argc, char** argv){

    std::string file_name = argv[1];

    std::ifstream file(file_name);
    std::string extracted_line;

    std::unordered_map<size_t, std::string> lines;
    size_t line_count{0};

    while(std::getline(file, extracted_line, '\n')){
        line_count++;
        lines.insert({line_count, extracted_line});
    }

    while(true){

        std::cout << "grep > ";

        std::string pattern;
        std::cin >> pattern;

        if(pattern == ".exit") break;

        std::string postfix_expr = regex_to_postfix(pattern);
        State* regex_nfa_start = postfix_to_nfa(postfix_expr);

        std::vector<State*> l1;
        std::vector<State*> l2;

        for(auto& line : lines){
            l1.clear();
            l2.clear();

            if(match(regex_nfa_start, line.second, l1, l2)){
                std::cout << "[line " << line.first << "] " << line.second << "\n";
            }
        }
        
        //print_nfa(regex_nfa_start, visited);
        std::unordered_set<State*> visited_states;
        delete_state_objects(regex_nfa_start, visited_states);
    }

    return 0;
}