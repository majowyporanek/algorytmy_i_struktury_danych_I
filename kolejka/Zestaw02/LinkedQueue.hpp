#ifndef LINKEDQUEUE_HPP_INCLUDED
#define LINKEDQUEUE_HPP_INCLUDED

class Queue
{
private:
    /* data */
        struct Node {
        Node *next; //wskaznik do nastepnego elementu kolejki
        int value; // wartosc
    };

    Node *head;
    Node *tail;
    int size_ = 0;

public:
    Queue() {head = nullptr; tail = nullptr; size_ = 0;}; // Konstruktor domyślny
    void push(int x); // Wstawia element x do kolejki (także enqueue)
    int pop(); // Usuwa element z kolejki i zwraca jego wartość (dequeue)
    int size(); // Zwraca liczbę elementów w kolejce
    bool empty(); // Sprawdza czy kolejka jest pusta

};

void Queue::push(int x){
    Node *newNode = new Node;
    if(newNode == nullptr) {
        throw std::out_of_range("full");
    }

    newNode->next = nullptr;
    newNode->value = x;

    //pierwszy węzel
    if(head == nullptr) {
        head = newNode;
        tail = newNode;
        size_++;
    }else {
        tail->next = newNode;
        tail = newNode;
        size_++;
    }
}

int Queue::pop(){
    if(head == nullptr){
        throw std::out_of_range("empty");
    }
    int popped = head->value;
    Node *poppedNode = new Node;
    poppedNode = head; // pomocniczy node
    head = head->next;
    delete poppedNode;
    size_--;

    return popped;
}

bool Queue::empty() {
    return (head == nullptr) ? true:false;
}

int Queue::size(){return size_;};

#endif // LINKEDQUEUE_HPP_INCLUDED
