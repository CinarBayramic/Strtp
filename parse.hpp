#include <string>
#include <vector>



bool cinstr(char c, std::string s) {
    for(char p:s) {
        if(p == c) {
            return true;
        }
    }
    return false;
}

std::vector<std::string> tokenise(std::string in, std::string d) {
    std::vector<std::string> words;
    std::string word = "";
    for(char c:in) {
        if(!cinstr(c,d)) {
            word.push_back(c);
        } else {
            words.push_back(word);
            word = "";
        }
    }
    if(word.size() > 0)
    words.push_back(word);
    return words;
}

std::vector<int> searchforall(std::vector<std::string> str, std::string word) {
    std::vector<int> indecies = {};
    for(int i = 0; i < str.size();i++) {
        if(str[i] == word) {
            indecies.push_back(i);
        }
    }
    return indecies;
}
int searchfor(std::vector<std::string> str, std::string word) {
    std::vector<int> indecies = searchforall(str,word);
    if(indecies.size() == 0) {
    throw "notfound";
    return -1;
    } else {
    return indecies[0];
    }
}
