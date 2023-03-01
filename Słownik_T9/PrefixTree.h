#ifndef PREFIX_TREE_HPP
#define PREFIX_TREE_HPP
#include "LinkedList.h"
#include <string>
#include <iostream>
#define ALPHABET_SIZE 26

class PrefixTree
{

public:
struct Node {
    char value;
    Node* children[ALPHABET_SIZE];
    bool isEnd;
    Node(char value_) : value(value_), isEnd(false){
        for(int i = 0; i<ALPHABET_SIZE; i++){
            children[i] = nullptr;
        }
    };
};

private:
    Node* root;
public:
    PrefixTree();
    ~PrefixTree();
    void deleteNodes(Node* node);
    void clear();
    void insert(std::string word);
    std::string search_one(std::string word);
    List<std::string> search(std::string word);
    std::string display();
    void search_words(Node *current, std::string found_w, List<std::string> &all_words);

};

PrefixTree::PrefixTree() : root(new Node('\0')){}

PrefixTree::~PrefixTree()
{
  clear();
}

void PrefixTree::insert(std::string word){

    Node* current = root;

    for(int i = 0 ; i<(int)word.length(); i++){
        int index = word[i] - 'a'; //index w tablicy

        if(!current->children[index])
            current->children[index] = new Node(word[i]);
        current = current->children[index];
    }
    current->isEnd = true;
}

// std::string PrefixTree::search_one(std::string word){
//     Node* current = root;
//     std::string found_word = "";
//     for(int i = 0; i < word.length(); i++) {
//         int index = word[i] - 'a';
//         if(!current->children[index])
//             return "";
//         found_word += current->children[index]->value;
//         current = current->children[index];
//     }

//     if((current->isEnd))
//         return found_word;
//     return "";
// }

void PrefixTree::search_words(Node *current, std::string found_w, List<std::string> &all_words){
    if(!current) return;

    found_w += current->value;
    if(current->isEnd)
        all_words.push_back(found_w);
    for(int i = 0; i < ALPHABET_SIZE; i++){
        if(current->children[i])
            search_words(current->children[i], found_w, all_words);
    }
}

List<std::string> PrefixTree::search(std::string word){
    Node *current = root;
    std::string found_word = "";
    for(int i = 0; i <(int) word.length(); i++){
        int index = word[i] - 'a';
        if(!current->children[index]){
            List<std::string>newList;
            break;
        }

        found_word += current->children[index]->value;
        current = current->children[index];
    }

    List<std::string>words;
    if(found_word != word)
        return words;

    found_word = found_word.substr(0, found_word.length()-1);
    search_words(current, found_word, words);
    return words;
}

void PrefixTree::deleteNodes(Node *node) {
    if (node == nullptr) {
        return;
    }
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i]) {
            deleteNodes(node->children[i]);
        }
    }
    delete node;
}

void PrefixTree::clear() {
    deleteNodes(root);
    root = new Node('\0');
}


#endif
