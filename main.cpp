#include <iostream>
#include "parse.hpp"
#include <string>
int main() {
    std::string S;
    std::string d;
    std::string N;
    std::getline(std::cin,S);
    std::getline(std::cin,d);
    std::getline(std::cin,N);
    std::vector<std::string> T = tokenise(S," ");
    for(std::string c: T) {
        std::cout << c << "  " << c.size() <<"\n";
    }
    std::vector<int> indecies = searchforall(S,d);
    for(int i : indecies) {
        std::cout << i << "\n";
    }
    std::string replaced = replaceall(S,d,N);
    std::cout << replaced << "\n";
}