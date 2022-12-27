#ifndef LINKEDSTACK_HPP_INCLUDED
#define LINKEDSTACK_HPP_INCLUDED

template <typename T>
class Stack {
private:
    struct Node {
        Node *prev; //wskaznik do poprzedniego elementu
        T value; // wartosc
    };

    Node* top;
    int size_ = 0;

public:
//    Stack();
    Stack(){top = nullptr;};
    void push(T x); // Wstawia element na stos
    T pop(); // Usuwa element ze stosu i zwraca jego wartość
    int size(); // Zwraca liczbę elementów na stosie
    bool empty(); // Sprawdza czy stos jest pusty
    T getTop();
};


template <typename T>
void Stack<T>::push(T x){
    Node *newNode = new Node; //tworze nowy element
    if(newNode == NULL) {
        throw std::out_of_range("FULL");
    }
    newNode -> prev = top;
    newNode-> value = x;
    top = newNode;
    size_++;   
}

template <typename T>
T Stack<T>::pop(){

    if(top == nullptr) {
        throw std::out_of_range("EMPTY");
    }

    T x; // przechowywanie zwracanej wartości
    Node *poppedNode = new Node;
    poppedNode = top;
    top = top->prev;
    x = poppedNode->value;
    delete poppedNode; // zwalniam miejsce
    size_--;
    return x;
}

template <typename T>
int Stack<T>::size() {
    return size_;
}

template <typename T>
bool Stack<T>::empty() {
    return (top == nullptr) ? true : false;
}

template <class T>T Stack<T>::getTop() {
    if(top == nullptr) {
        throw std::out_of_range("EMPTY");
    }
    return top->value;
}


#endif // LINKEDSTACK_HPP_INCLUDED
