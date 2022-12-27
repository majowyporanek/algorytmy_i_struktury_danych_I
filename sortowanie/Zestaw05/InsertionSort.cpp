#include <iostream>
#include <vector>
#include<chrono>

using namespace std;
 
template <class T> void sort(std::vector<T>& v){
    T x;
    int j, n, i;
    n = v.size();

    for(i = 1; i < n; i++) {
        j = i-1;
        x = v.at(i); // element do insert

        while(j>-1 && v.at(j)>x){
            v.at(j+1) = v.at(j);
            j--;
        }
        v.at(j+1) = x;
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