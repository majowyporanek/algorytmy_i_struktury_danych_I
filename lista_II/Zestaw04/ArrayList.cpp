#include <iostream>
#include "ArrayList.hpp"
using namespace std;

int main() {
    List l;
    int n; 
    char c;
    int x;
    int y;
    cin>>n;


    for(int i = 0; i<n; i++){
        cin>>c;
       if(c == 'F' || c=='B' || c=='R'){
            cin>>x;
            if(c=='R'){
                cin>>y;
            }
       }
        int whereIsX;
       switch(c) {
        case 'F':
            if(l.size()<1000){l.push_front(x);}
            break;
        case 'B':
            if(l.size() <1000){l.push_back(x);}
            break;
        case 'f':
              try
            {
                cout<<l.pop_front()<<endl;
            }
            catch(const std::out_of_range & e)
            {
                cout<<"EMPTY"<<endl;
                break;
            }
            break;
        case 'b':
            try 
            {
                cout<<l.pop_back()<<endl;
            }
            catch(const std::out_of_range & e)
            {
                cout<<"EMPTY"<<endl;
                break;
            }
            break;
        case 'R':
            try
            {
              whereIsX = l.find(x);
            } 
            catch(const std::out_of_range & e)
            {
                cout<<"FALSE"<<endl;
                break;
            }

            if(whereIsX == -1) {
                cout<<"FALSE"<<endl;
                break;
            }else {
                l.insert(whereIsX, y);
                l.erase(whereIsX+1);
                cout<<"TRUE"<<endl;
                break;            
            }
        case 'S':
            cout<<l.size()<<endl;
            break;
       }
}
    return 0;
}