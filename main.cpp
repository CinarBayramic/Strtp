#include <iostream>
#include "parse.hpp"
#include <string>
int main() {
    std::string S;
    std::getline(std::cin,S);
    std::vector<std::string> T = tokenise(S," ");
    for(std::string c: T) {
        std::cout << c << "\n";
    }
}