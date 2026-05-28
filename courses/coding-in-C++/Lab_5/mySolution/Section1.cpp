#include <stdio.h>
#include <cstdint>
#include <string>
#include <iostream>


template <typename T> 
void swapVal(T &a, T &b){
    std::cout << a << ", "<< b << std::endl;
    T temp = a;
    a = b;
    b = temp;
    std::cout << a << ", "<< b << std::endl;
}

template <typename T, int U>
void printFrames (T (&arr)[U]){
    std::cout << std::endl << "[ ";
    for(int i = 0; i < U; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << "]" << std::endl;
}

template <typename T, int U>
T smallestVal(T (&arr)[U] ){
    T temp = arr[0];
    for(int i = 1; i < U; i++){
        if(temp > arr[i]){
            temp = arr[i];
        }
    }
    std::cout << temp << std::endl;
    return temp;
}

template <typename T, typename U>
void pairs(std::string lbl1, T parameter1, std::string lbl2, U parameter2){
    std::cout << std::endl << lbl1 << ": " << parameter1 << " | " << lbl2 << ": " << parameter2 << std::endl;
}



int main(){
    int a = 3;
    int b = 4;
    swapVal(a, b);
    std::string c = "Hallo";
    std::string d = "Ciao";
    swapVal(c, d);
    double e = 2.5;
    double f = 3.5;
    swapVal(e, f);
    int arr[] = {12, 15, 18, 21};
    printFrames(arr);
    smallestVal(arr);
    double arr2[] = {1.1, 1.2, 1.3, 0.6};
    printFrames(arr2);
    smallestVal(arr2);
    pairs("label1", 3, "label2", 4);



    

}