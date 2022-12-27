#include <iostream>
#include <cstdlib>
#include <random>

using namespace std;

int liczbaOperacji() {
    int n;
    std::cin>>n;

    if(n>0 && n<=1000000){
        return n;
    }else {
        std::cout<<"Liczba musi byc >=0 oraz <=1000000!";
        return liczbaOperacji();
    }
}


int main() {
    std::random_device rd;  //silnik
    std::mt19937 gen(rd()); //generator z ziarnem
    std::uniform_int_distribution<> distrib(1, 100);
    std::uniform_int_distribution<> distrib2(1, 1000000);

    int n; //liczba <=106, wskazujaca liczbe operacji do wykonania
    n = liczbaOperacji();
    cout<<n<<" "<<endl;
    int chooseOperation;

    for(int i = 0; i<n; i++){
        chooseOperation = distrib(gen); //numer pomiedzy 1-100
        if(chooseOperation>=1 && chooseOperation<40){
            int x = distrib2(gen); //randomowo wylosowana liczba, ktora zostanie umieszczona na stosie
            std::cout<<"A "<<  x << " "<<endl;
        }else if(chooseOperation>=40 && chooseOperation<80){
            std::cout<<"D "<<endl;;
        }else {
            std::cout<<"S "<<endl;
        }
    }

    return 1;
}


