#include <iostream>
#include <fstream>
#include "PrefixTree.hpp"
#include "Dict.hpp"

int main() {
    PrefixTree words_store;
    Dict<std::string, std::string> letter_finder;
    std::ifstream file("./words.txt");

    if(!file.is_open()){
        std::cout<<"Error with opening a file with words!";
    }

    std::string line;

    while(getline(file, line))
        words_store.insert(line);    
    file.close();

    // // std::cout<<words_store.search_one("april");
    // List<std::string> foundedwords = words_store.search("cat");
    // auto it = foundedwords.begin();
    // while(it != nullptr){
    //     std::cout<<it->value<<std::endl;
    //     it++;
    // }

    char albet[26];

    for (int ch = 'a'; ch <= 'z'; ch++) {
    //do ch-'a' because we start at index 0
        albet[ch-'a'] = ch;
        std::cout<<char(ch)<<std::endl;
    }
}
