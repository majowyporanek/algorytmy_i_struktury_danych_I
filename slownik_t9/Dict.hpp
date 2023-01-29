#include "LinkedList.hpp"
#include <cmath>
#define CAPACITY 12

// unsigned int Hash(std::string k){
//     unsigned int num = 13;
//     unsigned int hashKey = 0;
//     for(int i = 0; (unsigned int)i<k.size(); i++){
//         hashKey += k[i] * pow(13, i) + k[i];
//     }
//     return hashKey % CAPACITY;
// }
unsigned int Hash(std::string k){
    unsigned int num = 13;
    unsigned int hashKey = 0;
    for(int i = 0; (unsigned int)i<k.size(); i++){
        hashKey = num * hashKey + k[i];
    }
    return hashKey % CAPACITY;
}

template<class K, class V>
class Dict {
using Pair = std::pair<K, V>;

private:
    Pair pair;
    int capacity;
    int size_;
    int longest_size;
    int shortest_size;
    List<Pair>dictionary[CAPACITY];


public: 
    Dict():capacity(CAPACITY), size_(0){}

    void clear() {
        for(int i = 0; i < capacity; i++){
            dictionary[i] == nullptr;
        }        
    }

    bool insert(const Pair& p) {
        unsigned int hashKey = Hash(p.first);
        if(!find(p.first)){
            dictionary[hashKey].push_back(p);
            size_++;
            return true;
        }else {
            auto it = dictionary[hashKey].begin();
            while(it != nullptr){
                if(p.first == it->value.first){
                    it->value.second = p.second;
                    return false;}
                it++;
            }
        }
        return false;
    }


    bool find(const K& k) {
        int hashKey = Hash(k);  
        auto it = dictionary[hashKey].begin();
        while(it != nullptr){
           if(k == it->value.first){return true;}
           it++;
        }
        return false;
    }

    V& operator[](const K& k){
        unsigned int hashKey = Hash(k);
        auto it = dictionary[hashKey].begin();
        while(it != nullptr){
            if(k == it->value.first){
                return it->value.second;
            }
            it++;
        }
        pair.first = k;
        insert(pair);
        return pair.second;
    }

    bool erase(const K& k) {
        unsigned int keyHash = Hash(k);
        auto it = dictionary[keyHash].begin();
        int index = 0;
        while(it !=nullptr){
            if(it->value.first == k){
                dictionary[keyHash].erase(index);
                size_--;
                return true;
                }
            it++;
            index++;
        }
        return false;
    }

    int size() {
        return size_;
    }
    bool empty() {
        return (size_ == 0);
    }

    void buckets() {
        shortest_size = 0;
        longest_size = 0;
        int i = 0;
        while(i!=CAPACITY){
            longest_size = (dictionary[i].size()>longest_size) ? dictionary[i].size() : longest_size;
            i++;
        }

        i = 0;
        while(i != CAPACITY){
            shortest_size = (dictionary[i].size()<shortest_size) ? dictionary[i].size() : shortest_size;
            i++;
        }
        std::cout<<"#"<< " "<<size_<<" "<<CAPACITY<< " "<<longest_size<<" "<<shortest_size<<std::endl;
    }
};


