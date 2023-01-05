#include <iostream>
#include <cstdlib>
#include "BinaryTree.hpp"
using namespace std;

int main() {
    BinaryTree tree;
    int n;
    int nodeValue;

    cin>>n;

    for(int i = 0; i<n; i++){
        cin>>nodeValue;
        tree.insert(nodeValue);
    }

    //size, depth, min, max:
    std::cout<< tree.size() << " " << tree.depth() << " " << tree.minimum() << " " << tree.maximim() << std::endl;
    tree.preorder(tree.getRoot());
    for(int i = 1; i<10; i++){
        if(tree.search(i) != nullptr){
            std::cout<<"Yes"<<std::endl;
        }else{
            std::cout<<"No"<<std::endl;;
        }
    }

}