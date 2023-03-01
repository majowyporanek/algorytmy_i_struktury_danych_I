#include <iostream>
#include <fstream>
#include "PrefixTree.hpp"
#include "Dict.hpp"
#include "SlownikT9.hpp"
#include "vector"

int main() {
    SlownikT9 slownik("./words.txt");
    int numbers[] = {9,4,2,8,3,8,3,7};
    int len = sizeof(numbers)/sizeof(int);
    std::vector<std::string>v = get_words(numbers,len,slownik);


}
