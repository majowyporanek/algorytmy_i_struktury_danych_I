#ifndef SLOWNIK_T9_HPP
#define SLOWNIK_T9_HPP
#include "PrefixTree.hpp"

class SlownikT9 {
private:
    PrefixTree words_store;
    std::string nums_to_letters[10];
    std::string filepath;

public:
    SlownikT9(std::string filepath);
    ~SlownikT9();
    void readWords(std::string filepath);
    List<std::string> find_words_by_prefix(std::string prefix);
};

SlownikT9::SlownikT9(std::string filepath) : filepath(filepath){
    nums_to_letters[2] = "abc";
    nums_to_letters[3] = "def";
    nums_to_letters[4] = "ghi";
    nums_to_letters[5] = "jkl";
    nums_to_letters[6] = "mno";
    nums_to_letters[7] = "pqrs";
    nums_to_letters[8] = "tuv";
    nums_to_letters[9] = "wxyz";
    readWords(filepath);
}

SlownikT9::~SlownikT9() {}

void SlownikT9::readWords(std::string filepath){
    std::ifstream file(filepath);
    if(!file.is_open())
        std::cout<<"Error with opening a file with words!";

    std::string line;

    while(getline(file, line))
        words_store.insert(line);

    file.close();
}

List<std::string> SlownikT9::find_words_by_prefix(std::string prefix){
    List<std::string> foundedwords = words_store.search("prefix");
    return foundedwords;
}


#endif