#include <stdexcept>
#include<iostream>

class List {
private:
    struct Node {
        Node *prev;
        int value;
        Node *next;
    };

    Node *head; //pierwsszy wezel
    Node *tail; //ostatni wezel
    int size_;


public:
List(); //konstruktor
~List();   
void push_front(int x); // Dołącza element na początek listy
int pop_front(); // Usuwa i zwraca element z początku listy
void push_back(int x); // Dołącza element na koniec listy
int pop_back(); // Usuwa i zwraca element z końca listy
int size(); // Zwraca liczbę elementów w liście
bool empty(); // Zwraca true gdy lista jest pusta
void clear(); // Czyści listę
int find(int x); // Zwraca pozycję pierwszego elementu o wartości x
int erase(int i); // Usuwa i zwraca element na pozycji i
void insert(int i, int x); // Wstawia element x przed pozycję i
int remove(int x); // Usuwa wystąpienia x i zwraca ich liczbę
};

List::List() : head(nullptr), tail(nullptr), size_(0){};
List::~List() {
    if(size_ != 0){
        Node *current(head); //przypisanie noda current do noda head
        while(current) {
            Node *next = current->next;
            delete current;
            current = next;
        }
    }
}

void List::push_front(int x){
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


void List::push_back(int x){
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



void List::insert(int i, int x){
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


int List::erase(int i) {
     if(i<0 || i>=size_){
        throw std::out_of_range("Out of defined range");
    }

    if(head==nullptr) {
        throw std::out_of_range("EMPTY");
    } 
    Node *erasedNode = new Node;
    int erasedValue;
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

int List::size(){
    return size_ ;
}

bool List::empty(){
    return (head == nullptr);
}



 int List::pop_front(){
    if(head==nullptr) {
        throw std::out_of_range("EMPTY");
    }
    Node *poppedNode = new Node;
    int poppedNodeValue = head->value;
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

int List::pop_back(){
    if(head==nullptr) {
        throw std::out_of_range("EMPTY");
    }
    Node *poppedNode = new Node;
    int poppedNodeValue = tail->value;
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



void List::clear(){
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


int List::find(int x) {
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

int List::remove(int x){
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