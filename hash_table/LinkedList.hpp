#include <stdexcept>
#include<iostream>
template<class T>
class List {
public:
    struct Node {
        Node *prev;
        T value;
        Node *next;
    };

    private:
    Node *head; //pierwsszy wezel
    Node *tail; //ostatni wezel
    int size_;
    public:

    struct Iterator 
    {
    using pointer = Node*;
    using reference = Node&;
    public:
        pointer m_ptr;

    Iterator(pointer ptr):m_ptr(ptr){}
    reference operator*() const { return *m_ptr; }
    pointer operator->() { return m_ptr; }
    Iterator operator++(int) { m_ptr = m_ptr->next; return *this; }
    friend bool operator== (const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; };
    friend bool operator!= (const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; };
};

    Iterator begin() { return Iterator(head); }
    Iterator end(){return Iterator(tail);}




public:

List() : head(nullptr), tail(nullptr), size_(0){};
~List() {
    if(size_ != 0){
        Node *current(head); //przypisanie noda current do noda head
        while(current) {
            Node *next = current->next;
            delete current;
            current = next;
        }
    }
}

    void push_front(T x){
    Node *newNode = new Node;
    newNode ->value = x;
    newNode-> next = head;
    newNode->prev = nullptr;
    if(head){
    head->prev = newNode;
    head = newNode;
    }else {
        head = newNode;
        tail = head;
    }
    size_++;
}


    void push_back(T x){
    Node *newNode = new Node;
    newNode->prev = tail;
    newNode->value = x;
    newNode->next = nullptr;
    if(tail) {
        tail->next = newNode;
        tail = newNode;
    }else  {
        tail = newNode;
        head = tail; //mamy tylko jeden wezel
    }
    size_++;
}



    void insert(int i, T x){
    if(i<0 || i>=size_){
        throw std::out_of_range("Out of defined range");
    }

    if(head==nullptr) {
        throw std::out_of_range("EMPTY");
    }

    //tworze nowy Node
    Node *newNode = new Node;
 
    if(i == 0) {
        //wstawianie na poczatek listy
        newNode->value = x;
        newNode->prev = nullptr;
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    else {
        Node *wsk(head);
        for(int j = 0; j<i; j++){
            wsk = wsk->next;
        }
        newNode->value = x;
        newNode->prev = wsk->prev;
        newNode->next = wsk;
        wsk->prev->next = newNode;
        wsk->prev = newNode;
        wsk = nullptr; // wskaznik juz nie wskazuje na dany element 
        delete wsk;        
    }
    size_++;
}


    T erase(int i) {
     if(i<0 || i>=size_){
        throw std::out_of_range("Out of defined range");
    }

    if(head==nullptr) {
        throw std::out_of_range("EMPTY");
    } 
    Node *erasedNode = new Node;
    T erasedValue;
    erasedNode = head;

    if(i==0) {
        erasedValue = head->value;
        head = head->next;
        if(head) {
            head->prev = nullptr;
        }else {
            tail = head;
        }
        delete erasedNode;
    }else {
        //usuwam z innej pozycji niz 0
        for(int j = 0; j<i; j++){
            erasedNode = erasedNode->next;
        }

        erasedValue = erasedNode->value;
        erasedNode->prev->next = erasedNode->next; 
        if(erasedNode->next)  {
            //jezeli nie jest to sytuacja gdzie usuwamy tail
            erasedNode->next->prev = erasedNode->prev;
        }else {
            tail = erasedNode->prev;
        }  
        delete erasedNode;
    }
    size_--;
    return erasedValue;
    }

    int size(){
    return size_ ;
}

    bool empty(){
    return (head == nullptr);
    }



    T pop_front(){
    if(head==nullptr) {
        throw std::out_of_range("EMPTY");
    }
    Node *poppedNode = new Node;
    T poppedNodeValue = head->value;
    poppedNode = head; // wskaz na pierwszy Node
    head = head->next; // nastepny Node staje sie pierwszym
    if(head){
    head->prev = nullptr; // 'odpinam' usuwany Node
    }else {
        tail = head; // przepinam tail aby takze wskazywalo na nullptr - lista jest pusta
    }
    delete poppedNode;
    size_= size_-1;
    return poppedNodeValue;
}

    T pop_back(){
    if(head==nullptr) {
        throw std::out_of_range("EMPTY");
    }
    Node *poppedNode = new Node;
    T poppedNodeValue = tail->value;
    poppedNode = tail;

    tail = tail->prev;
    if(tail) {
        tail->next = nullptr;
    }else {
        head = tail; // lista jest pusta
    }

    delete poppedNode;
    size_--;
    return poppedNodeValue;
}



void clear(){
    if(head==nullptr) {
        throw std::out_of_range("EMPTY");   
    }
    Node *current(head); //przypisanie noda current do noda head
    while(current) {
        Node *next = current->next;
        delete current;
        current = next;
        size_--;
    }
}


int find(T x) {
    if(head==nullptr) {
        throw std::out_of_range("EMPTY");   
    }
    Node *current(head);
    int pos = 0; 
    while(current) {
        if (current->value == x) {return pos;};
        current = current->next;
        pos++;
    }

    return -1;
}

int remove(T x){
    if(head==nullptr) {
        throw std::out_of_range("EMPTY");   
    }

    int duplicates = 0;
    int pos = 0;
    Node *current(head);

    while(current) {
        if(current->value == x){
            erase(pos);
            duplicates++;
            size_--;
        }else {
            pos++;
        }
        current = current->next;
    }

    return duplicates;
}

Node* head_(){
    return head;
}

};