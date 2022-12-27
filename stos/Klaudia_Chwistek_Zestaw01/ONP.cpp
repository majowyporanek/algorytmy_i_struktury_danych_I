#include <iostream>
#include <cstdlib>
#include "ArrayStack.hpp"
#include <sstream>  
#include <cstring>
#include<ctype.h> //isDigit

using namespace std;

//funkcja do sprawdzania priorytetów znaków
int priorytet(char z){
    if(z == '*' || z == '/') {
        return 3;
    }else if(z == '+'|| z == '-'){
        return 2;
    }else if(z == '(' || z == ')') {
        return 0;
    }else {
        return -1;
    }
}

//funkcja do usuwania spacji
string removeSpaces(const string &s)
{
  int last = s.size() - 1;
  while (last >= 0 && s[last] == ' ')
    --last;
  return s.substr(0, last + 1);
}


bool nawias(char z) {
    return (z == ')' || z == '(') ? true : false;
}


void wstawNaStos(char x, Stack<char> &s, string &output) {
    //nawiasy i operatory rozpatruję osobno
    if(!nawias(x)) {

        if(s.empty() || (priorytet(x) > priorytet(s.getTop()))){
            s.push(x);
        }else {
            while(!(s.empty() || (priorytet(x) > priorytet(s.getTop())))){
                output += s.pop(); //sciagam ze stosu;
                output += " ";
            }
        }

    }else{
        if(x == '('){
            s.push(x);
        }else {
            while(s.getTop() != '('){
                output += s.pop();
                output += " ";
            }
            s.pop(); 
        }
    }
}

int main() {
    Stack<char> st;
    string input, s, output;
    getline(cin, input);
    stringstream x(input);

    while(getline(x,s,' ')) {
        bool num;
        for(unsigned int i = 0; i< s.length(); i++) {
            num = true;
            if(!isdigit(s[i])){
                num = false;
                wstawNaStos(s[i], st, output);
                break;
            }
        }
        if(num) {output += s + " ";} //jezeli to numer to wypisz do wyjscia
    }

    cout<<removeSpaces(output);
    return 0;
}