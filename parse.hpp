#include <string>
#include <vector>

int min(int x, int y) {
    return (x>y) ? y : x;
}

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
std::vector<int> searchforall(std::string str, std::string word) {
    std::vector<int> indecies = {};
    for(int i = 0; i < str.size();i++) {
        if(str[i] == word[0]) {
            for(int j= 0; j < word.size();j++) {
                if(str[i+j] != word[j]) {
                    break;
                } else if (j+1  == word.size() && str[i+j] == word[j]) {//eğer ömer bu kodu okuyor ise bunun gereksiz olduğunun farkındayım
                    indecies.push_back(i);
                    break;
                }
            }
        }
    }
    return indecies;
} 
int searchfor(std::string str, std::string word) {
    std::vector<int> indecies = searchforall(str,word);
    if(indecies.size() == 0) {
    throw "notfound";
    return -1;
    } else {
    return indecies[0];
    }
}

std::string replaceall(std::string str, std::string from, std::string to) {
    std::string newstr = str;
    std::vector<int> indecies = searchforall(str,from);
    for(int a : indecies) {
        for(int b = 0; b < from.size();b++) {
            newstr.erase(a);
        }
        for(int b = 0; b < to.size();b++) {
            char Q[] = {to[b]};
            newstr.insert(a+b,Q);
        }
    }
    return  newstr;
}