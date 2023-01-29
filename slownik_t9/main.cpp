#include "PrefixTree.hpp"
#include "Dict.hpp"
#include <iostream>

using namespace std;

int main() {
    
    PrefixTree tree;
    Dict<std::string, std::string>dict;
    dict.insert(make_pair("Klaudia", "Iza"));
    tree.insert("klaudia");
    tree.insert("kinga");
    tree.insert("klosz");
    std::cout<<tree.search_one("klosz");
    std::cout<<tree.search_one("kla");
    return 0;
}
