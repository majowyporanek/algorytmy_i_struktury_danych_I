#include <iostream>
#include <cstdlib>
#include <random>
#include <time.h>


int main(int argc, char *argv[]) {
    (void)argc;
    std::random_device rd;  //silnik
    std::mt19937 gen(rd()); //generator z ziarnem
    int n = atoi(argv[1]);
    int max = atoi(argv[2]);
    std::uniform_int_distribution<> distrib(1, max); //zakres liczb pseudolosowych
    
    for(int i = 0; i<n; i++){
        std::cout<<distrib(gen)<<std::endl;
    }

}