#ifndef ARRAYQUEUE_HPP_INCLUDED
#define ARRAYQUEUE_HPP_INCLUDED
class Queue {
private:
    int size_;
    int r;
    int w;
    int capacity;
    int *q; //wskaznik do tablicy

public:
    //Queue(); // Konstruktor domyślny
    Queue(int capacity); // Konstruktor przyjmujacy jako argument rozmiar tablicy
    ~Queue(); //destruktor
    void push(int x); // Wstawia element x do kolejki (także enqueue)
    int pop(); // Usuwa element z kolejki i zwraca jego wartość (dequeue)
    int size(); // Zwraca liczbę elementów w kolejce
    bool empty(); // Sprawdza czy kolejka jest pusta
};


Queue::Queue(int capacity = 100001) : size_(0), r(0), w(0), capacity(capacity),q(new int[capacity]) {};
Queue::~Queue(){delete [] q;};

void Queue::push(int x) {
    if((w+1)%capacity == r) {
        throw std::out_of_range("full");
    }

    w = (w+1)%capacity;
    q[w] = x;
    size_++;
}

int Queue::pop(){
    int popped;
    if(r==w){
        throw std::out_of_range("empty");
    }
    r = (r+1)%capacity;
    popped = q[r];
    q[r] = 0;
    size_--;
    return popped;
}

bool Queue::empty() {
    return (r == w);
}

int Queue::size() {
    return size_;
}


#endif // ARRAYQUEUE_HPP_INCLUDED
