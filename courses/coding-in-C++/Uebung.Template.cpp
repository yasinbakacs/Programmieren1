#include <iostream>
#include <string>
#include <cstdint>

template <typename T, typename U>

class Pair{
    private: 
    T value;
    U value2;
    public:
    Pair(T value, U value2) : value(value), value2(value2){};

    T getValue(){
        return this->value;
    }

    void setValue(T value){
        this->value = value;
    }

    U getValue2(){
        return this->value2;
    }

    void setValue2(U value2){
        this->value2 = value2;
    }

};

int main(){
    Pair<int, double> a(12, 3.5);

    std::cout << a.getValue() << std::endl;
}