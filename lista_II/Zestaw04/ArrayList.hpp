#include <stdexcept>
#include <iostream>

class List {
private:
    int size_;
    int capacity;
    int *q; //wskaznik do tablicy
public:
    List(int capacity);
    ~List(); //destruktor
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


List::List(int capacity = 1000001) : size_(0), capacity(capacity), q(new int[capacity]) {};
List::~List(){delete []q;};

void List::push_back(int x) {
    // if(size_ == capacity) {
    //     // throw std::out_of_range("FULL");
    //     return;
    // }
    q[size_] = x;
    size_++;
}

void List::push_front(int x){
    // if(size_ == capacity) {
    //     throw std::out_of_range("FULL");
    // }

    for(int i = size_; i>0; i--){
        q[i] = q[i-1];
    }

    q[0] = x;
    size_++;
}

int List::pop_front(){
    if(size_==0){
        throw std::out_of_range("EMPTY");
    }

    int popped = q[0];
    for(int i = 0; i<size_-1; i++){
        q[i] = q[i+1];
    }
    size_--;
    return popped;
}

int List::pop_back() {
    if(size_==0){
        throw std::out_of_range("EMPTY");
    }

    int popped;
    popped  = q[size_-1];
    size_--;
    return popped;
}

int List::size() {
    return size_;
}

bool List::empty() {
    return (size_ == 0);
}

void List::clear() {
    if(size_==0){
        throw std::out_of_range("EMPTY");
    }

    for(int i = size_-1; i<=0; i--){
        q[i] = 0;
        size_--;
    }
}


int List::find(int x){
    if(size_==0){
        throw std::out_of_range("EMPTY");
    }

    for(int i = 0; i<size_; i++){
        if(q[i] == x) {
            return i;
        }
    }
    return -1;
}

int List::erase(int i){
    if(size_==0){
        throw std::out_of_range("EMPTY");
    }

    // if(i<0 || i>=size_){
    //     throw std::out_of_range("WRONG INDEX");
    // }

    int erased = q[i];
    for(int j = i; j < size_-1; j++){
        q[j] = q[j+1];
    }
    size_--;
    return erased;
}

void List::insert(int i, int x){
    if(size_==0){
        throw std::out_of_range("EMPTY");
    }

    if(i<0 || i>size_){
        throw std::out_of_range("WRONG INDEX");
    }

    for(int j = size_; j>i; j--){
        q[j] = q[j-1];
    }

    q[i] = x;
    size_++;
}


int List::remove(int x) {
    if(size_==0){
        throw std::out_of_range("EMPTY");
    }

    int xCout = 0;

    int current = 0;
    while(current != size_) {
        if(q[current] == x){
            erase(current);
            xCout++;
        }else {
            current++;
        }
    }
    return xCout;
}
