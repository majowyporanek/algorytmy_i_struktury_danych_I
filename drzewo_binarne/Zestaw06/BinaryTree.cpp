#include <iostream>
#include <cstdlib>
#include "BinaryTree.hpp"
using namespace std;

int main() {
    // int n;
    // char c;
    // int x;

    // cin>>n;

    // for(int i = 0; i<n; i++){
    //     cin>>c;
    // }

    // return 1;
    BinaryTree tree;
    for(int i = 10; i > 0; i--){
        tree.insert(i * 5);
        tree.insert(i);
        tree.insert(i*7);
    }

    std::cout<<tree.size()<<std::endl;
    std::cout<<"Min el: "<<tree.minimum()<<std::endl;
    std::cout<<"Max el: "<<tree.maximim()<<std::endl;
    std::cout<<"Szukam 70" << tree.search(70)<<std::endl;
    std::cout<<"Szukam 92389281"<<tree.search(982387)<<std::endl;

    if(tree.search(9889) == nullptr){
        std::cout<<"Yes"<<std::endl;
    }else {
        std::cout<<"No"<<std::endl;
    }
}