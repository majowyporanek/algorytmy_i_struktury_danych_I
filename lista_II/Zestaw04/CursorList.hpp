#include <iostream>
class CursorList { // Klasa listy
private:
    struct Node { // Zagnieżdżona klasa węzła
        int elementWezla; // Element przechowywany przez węzeł listy
        int next; // Indeks kolejnego węzła
    };

    int head; // Indeks pierwszego węzła
    int tail; // Indeks ostatniego węzła
    int size_; // Rozmiar listy
    int spare; // Indeks pierwszego nieużytego elementu tablicy
    int capacity_;
    Node *pojemnik; // Tablica węzłów

public:
    CursorList(int capacity); //konstruktor
    ~CursorList(); //destruktor
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

    CursorList::CursorList(int capacity = 100001) : head(-1), tail(-1), size_(0), spare(0),capacity_(capacity), pojemnik(new Node[capacity]) {
        //inicjalizacja tablicy
        // na poczatku wszystkie wezly laczymy jako wolne
        for(int i = capacity_-1;i>=0; i--){
            pojemnik[i].next = i + 1;
        }
        pojemnik[capacity_-1].next = -1;
    }

    CursorList::~CursorList() {delete [] pojemnik;};

    void CursorList::push_back(int x){
        //wyjatek
        // sytuacja gdy dodajemy do pustej listy:
        if(head == -1 && tail == -1){
            head = spare; // glowa stanie sie pierwszy wolny wezel
            pojemnik[head].elementWezla = x; // dodajemy wartosc do wezla
            spare = pojemnik[head].next; // przepinamy spare (w tym przypadku na 1 index)
            pojemnik[head].next = -1; // jest to pierwszy i ostatni element listy wlasciwej zatem wskazuje na -1
            tail = head; // tail i head sa takie same
        }else {
            int lastSpare = spare;
            pojemnik[spare].elementWezla = x; // ostatni wolny wezel przestaje byc wolny
            spare = pojemnik[spare].next; //przepinam spare na kolejny wolny wezel
            pojemnik[lastSpare].next = -1;
            pojemnik[tail].next = lastSpare; // poprzedni tail bedzie wskazywal na nowo dodany el
            tail = lastSpare; //przepinam tail
        }

        size_++;
    }

    int CursorList::pop_back(){
        if(size_==0) {
            throw std::out_of_range("EMPTY");
        }
        // zmienne pomocnicze
        int temp = tail;
        int tempValue = pojemnik[tail].elementWezla;
        int current = head;
        // deallocate:
        pojemnik[tail].next = spare;
        //szukam przed ostatniego elementu w liscie wlasciwej

        //jezeli mamy jeden element:
        //lista wolnych wezlow stanie sie pusta
        if((head == tail) && (size_==1)) {
            head = -1;
            tail = -1;
            size_--;
        }else {
            while(pojemnik[current].next != temp){
                current = pojemnik[current].next;
            }

            pojemnik[current].next = -1;
            tail = current;
            size_--;
        }
        return tempValue;
    }


    void CursorList::push_front(int x) {
        //wyjatek
        if(size_ == 0){
            head = spare;
            spare = pojemnik[spare].next;
            pojemnik[head].elementWezla = x;
            pojemnik[head].next = -1;
            tail = head;
            size_++;
        }else {

        int temp = head; //przechowuje head aby pozniej dopiac nowy element na poczatek
        head = spare; // przepinam head na nastepny wolny element
        spare = pojemnik[spare].next; // przepinam spare na kolejny wolny element
        pojemnik[head].next = temp; // nowy head wskazuje na stary head
        pojemnik[head].elementWezla = x;
        size_++;
        }
    }

    int CursorList::pop_front(){
        //wyjatek
        if(size_==0) {
            throw std::out_of_range("EMPTY");
        }

        if((head == tail) && size_==1){
            int poppedVale = pojemnik[head].elementWezla;
            pojemnik[head].next = spare;
            spare = head;

            head = -1;
            tail = -1;
            size_--;
            return poppedVale;
        }else {
            int temp = head;
            int tempValue = pojemnik[head].elementWezla;
            head = pojemnik[head].next;

            //dealocate
            pojemnik[temp].next = spare;
            spare  = temp;

            size_--;
            return tempValue;
        }
    }

    int CursorList::erase(int i){
        if(i<0 || i>=size_){
            throw std::out_of_range("Out of defined range");
        }

        if(size_==0) {
            throw std::out_of_range("EMPTY");
        } 
        
        if(i == 0) {
            return pop_front();
        }

        if(i == size_-1){
            return pop_back();
        }
        
        int current = head;
        int j = 0;
        //przechodze do pozycji przed pozycja do usuniecia
        while(j != (i-1)){
            current = pojemnik[current].next;
            j++;
        }
        int toErase = pojemnik[current].next;
        int erasedValue = pojemnik[toErase].elementWezla;
        pojemnik[current].next = pojemnik[toErase].next;
        //deallocate:
        pojemnik[toErase].next = spare;
        spare = toErase;
        size_--;
        return erasedValue;
    }

    int CursorList::find(int x){
        if(size_==0) {
            throw std::out_of_range("EMPTY");   
        }
        int current = head;
        int pos = 0;
        if(pojemnik[current].elementWezla == x)
            return pos;

        while(pojemnik[current].next != -1){
            if(pojemnik[current].elementWezla == x){
                return pos;
            }else {
                current = pojemnik[current].next;
                pos++;
            }
        }
        return -1;
    }


    int CursorList::size(){
        return size_;
    }

    bool CursorList::empty(){
        return (size_==0);
    }

    void CursorList::insert(int i, int x){
        if(i == 0){
            push_front(x);
        }

        if(i == size_-1) {
            push_back(x);
        }

        if(i != (size_-1) && i != 0){
            int current = head;
            int j = 0;
            //przechodze do pozycji przed pozycja do usuniecia
            while(j != (i-1)){
                current = pojemnik[current].next;
                j++;
            }
            int newElement = spare;
            spare = pojemnik[spare].next;
            pojemnik[newElement].elementWezla = x;
            pojemnik[newElement].next = pojemnik[current].next;
            pojemnik[current].next = newElement;
            size_++;
        }
    }

    int CursorList::remove(int x){
        if(size_== 0) {
            throw std::out_of_range("EMPTY");   
        }

        int duplicates = 0;
        int pos = 0;
        int current = head;

        while(pos != size_-1){
            if(pojemnik[current].elementWezla == x){
                duplicates++;
                erase(pos);
            }else {
                pos++;
                current = pojemnik[current].next;
            }
        }
        return duplicates;
    }

    void CursorList::clear() {
        while(size_ !=0){
            pop_back();
        }
    }