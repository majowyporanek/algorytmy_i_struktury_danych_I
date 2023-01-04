#include <iostream>

class BinaryTree {
private:
    struct Node {
        Node *left;
        Node *right;
        int value;
        Node(int value_) : left(nullptr), right(nullptr), value(value_){}; 
    };



    int size_; //liczba wezlow
    Node *root;

public:
    BinaryTree();
    ~BinaryTree();
    void insert(int x);
    Node* search(int x);
    Node* searchRecursive(int x);
    int size();
    int minimum();
    int maximim();
    int depth();
    void inorder();
    void preorder();
    void postorder();
};

BinaryTree::BinaryTree() : size_(0), root(nullptr){}
BinaryTree::~BinaryTree(){
    std::cout<<"Destructor";
}

void BinaryTree::insert(int x) {
    if(root == nullptr){
        //drzewo jest puste
        root = new Node(x);
        size_++;
        std::cout<<"Drzewo puste"<<std::endl;
    }else {
        //drzewo nie jest puste, trzeba sprawdzic pozostale elementy
        Node *current = root;
        bool checkAgain = true;

        while(checkAgain){
            if(x < current->value){
                // std::cout<<"Ide w lewo"<<std::endl;
                if(current->left == nullptr){
                    current->left = new Node(x);
                    size_++;
                    checkAgain = false;
                }else {
                    current = current->left;
                }
            }else {
                // std::cout<<"Ide w prawo"<<std::endl;
                if(current->right == nullptr){
                    current->right = new Node(x);
                    size_++;
                    checkAgain = false;
                }else {
                    current = current->right;
                }
            }
        }
    }
}

BinaryTree::Node* BinaryTree::search(int x){

    if(root == nullptr){
        throw std::out_of_range("EMPTY");
    }

    Node* searchedNode = nullptr;
    Node* current = root;
    bool searchAgain = true;

    while(searchAgain){
        if(current->value == x){
            searchedNode = current;
            searchAgain = false;
        }else {
            if(x<current->value){
                if(current->left){
                    current = current->left;
                }else {
                    searchAgain = false;
                }
            }else {
                if(current->right){
                    current = current->right;
                }else {
                    searchAgain = false;
                }
            }
        }
    }

    return searchedNode;
}

int BinaryTree::minimum(){
    if(root == nullptr){
        throw std::out_of_range("EMPTY");
    }
    int minEl;
    Node* current = root;
    minEl = root->value;
    while (current->left != nullptr)
    {
        minEl = current->left->value;
        current = current->left;
    }

    return minEl;
}

int BinaryTree::maximim(){
    if(root == nullptr){
        throw std::out_of_range("EMPTY");
    }
    int maxEl;
    Node* current = root;
    maxEl = root->value;
    while (current->right != nullptr)
    {
        maxEl = current->right->value;
        current = current->right;
    }

    return maxEl;
}

int BinaryTree::size(){return size_;}

