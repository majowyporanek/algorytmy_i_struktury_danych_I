#include <iostream>
#include <fstream>
#include "Dict.hpp"

int main(int argc, char *argv[]) {
   (void)argc;
    Dict<std::string, std::string>dictionary;
    std::ifstream file;
    file.open(argv[1], std::ios::in);
    if (!file) {
		std::cout << "File not created!";
	}

    std::string key, value;
    
    while(file >> key){
        file>>value;
        dictionary.insert(std::make_pair(key, value));
    }

    while (std::cin>>key)
    {
        if(dictionary.find(key)){
            std::cout<<dictionary[key]<<std::endl;
        }else{
            std::cout<<"-"<<std::endl;
        }
    }
	file.close(); 
}