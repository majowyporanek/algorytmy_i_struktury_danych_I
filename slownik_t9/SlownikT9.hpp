#ifndef SLOWNIK_T9_HPP
#define SLOWNIK_T9_HPP
#include "PrefixTree.hpp"
#include <vector>

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
    List<std::string> search_words_by_numbers(int numbers[], int lenght, std::string prefix, List<std::string>&result);
    List<List<std::string>> search_words_by_numbers(int numbers[], int length, std::string prefix, List<List<std::string>> &result);
    List<List<std::string>> get_words();
    std::vector<std::string>wordstore;
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
    List<std::string> foundedwords = words_store.search(prefix);
    return foundedwords;
}

List<std::string> SlownikT9::search_words_by_numbers(int numbers[], int length, std::string prefix, List<std::string> &result) {
    if(length == 0){
        return find_words_by_prefix(prefix);
    }

    // List<std::string> result;
    std::string letters = nums_to_letters[numbers[0]];

    for(int i = 0; i < letters.length(); i++){
        std::string new_prefix = prefix + letters[i];
        List<std::string> words = search_words_by_numbers(numbers + 1, length -1, new_prefix, result);
        if(!words.empty()){
            auto it = words.begin();
            while(!words.empty()){
                std::string w = words.pop_front();
                wordstore.push_back(w);
                it++;
            }
        }
    }
    return result;
}

std::vector<std::string>get_words(int numbers[],int len, SlownikT9 &O){
    O.wordstore.clear();
    std::string prefix = "";
    List<std::string>resultsmy;
    O.search_words_by_numbers(numbers,len, prefix, resultsmy);
    return O.wordstore;
}


#endif