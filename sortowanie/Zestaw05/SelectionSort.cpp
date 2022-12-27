#include <iostream>
#include <vector>
#include<chrono>

using namespace std;
 
template <class T> void sort(std::vector<T>& v){
    T x; // minimalny element
    int k; // indeks minimalnego elementu
    int n = v.size();
    for(int i = 0; i<n; i++){
        k = i;
        x = v.at(i); 
        for(int j = i+1; j<n; j++) {
            if(v.at(j)<x){
                k=j;
                x = v.at(j);
            }
        }
                v.at(k) = v.at(i);
        v.at(i) = x;

    }
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
    // std::cerr << "Elapsed time[s] = " << elapsed.count() << endl;

    for(const auto& i : kontener)
        std::cout << i << std::endl;

}