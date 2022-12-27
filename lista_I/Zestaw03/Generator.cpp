#include <iostream>
#include <cstdlib>
#include <random>

using namespace std;


int liczbaOperacji() {
    int n;
    std::cin>>n;

    if(n>0 && n<=1000){
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
    std::uniform_int_distribution<> distrib2(1, 1000);

    int n; //liczba <=106, wskazujaca liczbe operacji do wykonania
    n = liczbaOperacji();
    cout<<n<<" "<<endl;
    int chooseOperation;
    int x = 0;
    for(int i = 0; i<n; i++){
        chooseOperation = distrib(gen); //numer pomiedzy 1-100
        if(chooseOperation>=1 && chooseOperation<20){
            x = distrib2(gen); //randomowo wylosowana liczba, ktora zostanie umieszczona na stosie
            cout<<"F "<<  x << " "<<endl;
        }else if(chooseOperation>=20 && chooseOperation<40){
            x = distrib2(gen);
            cout<<"B "<<x<<endl;;
        }else if(chooseOperation>=40 && chooseOperation<60){
            cout<<"f "<<endl;
        }else if(chooseOperation>=60 && chooseOperation<80){
            cout<<"b "<<endl;
        }else if(chooseOperation>=80 && chooseOperation<90){
            x = distrib2(gen);
            int y = distrib2(gen);
            cout<<"R "<<x<<" "<<y<<" "<<endl;
        }else {
            cout<<"S "<<endl;
        }
    }

    return 1;
}

