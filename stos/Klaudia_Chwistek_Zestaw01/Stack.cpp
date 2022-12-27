#include <iostream>
#include <cstdlib>
#include "LinkedStack.hpp"
using namespace std;

int main() {
    Stack<int> stack1;
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
            stack1.push(x);
            break;
        case 'D':
            try
            {
                cout<<stack1.pop()<<endl;
            }
            catch(const std::out_of_range & e)
            {
                cout<<"EMPTY"<<endl;
            }
            
            break;
        case 'S':
            cout<<stack1.size()<<endl;
            break;
       }
    }


    return 1;
}
