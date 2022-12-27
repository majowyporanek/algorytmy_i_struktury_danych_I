#include <iostream>
#include <vector>
#include<chrono>

using namespace std;
 
template <class T> void sort(std::vector<T>& v){
    T x;
    int n = v.size();
    int licznik_porownan = 0;
    int swap_licznik = 0;

    for(int i = 1; i<n; i++){
        for(int j = n-1; j>=i; j--){
            licznik_porownan++;
            if(v.at(j-1)>v.at(j)){
                x = v.at(j-1);
                v.at(j-1) = v.at(j);
                v.at(j) = x;
                swap_licznik++;
            }
        }
    }
    // cout<<"Ilosc potownan: "<<licznik_porownan<<endl;
    // cout<<"Ilosc swaps: "<<swap_licznik<<endl;
}

int main(){
    vector<int>kontener;
    int element;
    
    while(cin>>element){
        kontener.push_back(element);
    }

    // cout<<"Wektor przed posortowaniem: "<<endl;
    // for(int i = 0; i<kontener.size(); i++){
    //     cout<<kontener.at(i)<<endl;
    // }
    // auto start = std::chrono::high_resolution_clock::now();
    sort<int>(kontener);
    // auto end = std::chrono::high_resolution_clock::now();
    // std::chrono::duration<double> elapsed = end - start;

    for(const auto& i : kontener)
        std::cout << i << std::endl;

    // std::cerr << "Elapsed time[s] = " << elapsed.count() << endl;

}