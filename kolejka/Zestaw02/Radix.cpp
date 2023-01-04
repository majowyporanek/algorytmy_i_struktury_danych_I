#include <iostream>
#include <vector>
#include "LinkedQueue.hpp"

void radix(std::vector<int> &v) {
    std::vector<Queue>queues;
    //Stworz 10 kolejek
    for(int i = 0; i<10; i++){
        Queue current;
        queues.push_back(current);
    }


    int counter = 0; // zmienna pomocnicza (max == 9)
    int x = 10; // liczba do przechowywania poteg 10
    int modNum, significantNum; // zmienne pomocnicze
    int index = 0; // zmienna potrzena do erase
    auto it = v.begin();


    // //petla przechodzi 10 razy bo jest max 10-cyfrowa cyfra
     while(counter < 10){
         while(it != v.end()){
    //        //czytam po kolei liczby w wektorze
             modNum =*it%x;

            //jezeli spelniony warunek ponizej nie usuwam liczby z wektora
            if((modNum == *it) && (modNum/(x/10) == 0)){
                index++; // indeks wskazujacy czy jest jakis 'staly element' (juz posortowany) w wektorze
                it++;
                continue;
            }else {
                significantNum = (modNum == 0) ? modNum : ((modNum)/(x/10)); //jezeli reszta z dzielenia modulo to nie 0, 'wyciagam' znaczaca cyfre liczby
                queues[significantNum].push(*it);// dodaje do kolejki

                if(index == 0){
                    v.erase(v.begin()); //usuwam z poczatku
                }else {
                    v.erase(v.begin()+index);
                }
            }
         }

    //przechodze po kazdej kolejce, usuwam liczby i wstawiam spowrotem do wektora
    for(int j = 0; j<10; j++){
        //poki kolejka nie bedzie pusta usuwam liczby i wpisuje do wektora
        if(queues[j].empty()){
            continue;
        }else {
            for(int i = 0; i<=queues[j].size(); i++){
                while(!queues[j].empty()){
                    v.push_back(queues[j].pop()); // wstawiam do wektora usunieta z kolejki liczbe;
                }
            }
        }
    }

    counter++;
    x*=10; // poteguje 10
    }
}



int main() {
    //wczytywanie danych do wektora
    int x;
    std::vector<int> v;

    while(std::cin >> x)
    v.push_back(x);

    // std::cout<<"wywoluje funkcje radix: "<<std::endl;
    radix(v);

    // std::cout<<"\n Vektor po posortowaniu: "<<std::endl;
    for(const auto& i : v){
        std::cout<<i<<std::endl;
    }

    return 1;
}
