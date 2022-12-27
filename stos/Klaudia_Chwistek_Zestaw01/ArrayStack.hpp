#ifndef ARRAYSTACK_HPP_INCLUDED
#define ARRAYSTACK_HPP_INCLUDED

template <class T> class Stack {
private:
    T *data; //wskaźnik do tablicy
    int capacity; // pojemnosc stosu, jezeli nie zostanie podana wyniesie max: 10000000
    T poppedElement; //przechowywanie usunietego elementu
    int top = 0; //wskazuje konkretny element na stosie

public:
    Stack(int capacity_ = 1000000) {capacity = capacity_; data = new T[capacity];} // Konstruktor. Argumentem jest rozmiar tablicy.
    void push(T x); // Wstawia element na stos
    T pop(); // Usuwa element ze stosu i zwraca jego wartość
    int size(); // Zwraca liczbę elementów na stosie
    bool empty(); // Sprawdza czy stos jest pusty
    T getTop();
};


template <class T>void Stack<T>::push(T x){
    if(top == capacity) {
        throw std::out_of_range("full");
    }
    data[top] = x;
    top++;
}

template <class T>T Stack<T>::pop() {
    if(empty() == true) {
        throw std::out_of_range("empty");
    }
    poppedElement = data[top-1];
    data[top-1] = 0;
    top--; // zmniejszam liczbe elementów na stosie o 1
    return poppedElement;
}


template <class T>bool Stack<T>::empty() {
    return (top == 0) ? true:false;
}


template <class T>int Stack<T>::size() {
    return top;
}

template <class T>T Stack<T>::getTop() {
    if(top == 0) {
        throw std::out_of_range("EMPTY");
    }
    return data[top-1];
}

#endif // ARRAYSTACK_HPP_INCLUDED

