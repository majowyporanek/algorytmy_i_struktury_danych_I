#include <iostream>
#include <cstdlib>
#include "ArrayQueue.hpp"
using namespace std;

int main() {
    Queue q;
    int n;
    char c;
    int x;

    cin>>n;

    for(int i = 0; i<n; i++){
        cin>>c;
       if(c == 'A'){
            cin>>x;
       }
       switch(c) {
        case 'A':
            q.push(x);
            break;
        case 'D':
            try
            {
                cout<<q.pop()<<endl;
            }
            catch(const std::out_of_range & e)
            {
                cout<<"EMPTY"<<endl;
            }

            break;
        case 'S':
            cout<<q.size()<<endl;
            break;
       }
    }


    return 1;
}
