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

template <typename T, typename U>
void printFrames (T arr[], U size){
    std::cout << std::endl << "[ ";
    for(int i = 0; i < size; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << "]" << std::endl;
}

template <typename T, typename U>
T smallestVal(T arr[], U size){
    T temp = arr[0];
    for(int i = 1; i < size; i++){
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
    printFrames(arr, sizeof(arr) / sizeof(arr[0]));
    smallestVal(arr, sizeof(arr) / sizeof(arr[0]));
    double arr2[] = {1.1, 1.2, 1.3, 0.6};
    printFrames(arr2, sizeof(arr2) / sizeof(arr2[0]));
    smallestVal(arr2, sizeof(arr2) / sizeof(arr2[0]));
    pairs("label1", 3, "label2", 4);
    


    

}