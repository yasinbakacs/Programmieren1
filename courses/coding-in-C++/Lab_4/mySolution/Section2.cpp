#include <iostream>
#include <string>
#include <cstdint>

class Shape{
    public:
    virtual double area() const = 0;

    virtual ~Shape() {};
};

class Circle : public Shape{
    private:
    double radius;
    static constexpr double PI = 3.1415;
    public:
    Circle(double r) : radius(r) {};

    double area() const override{
        std::cout << radius * radius * PI << std::endl;
        return radius * radius * PI;
    }
};

class Rectangle : public Shape{
    private:
    double lengthA;
    double lengthB;

    public:
    Rectangle(double a, double b) : lengthA(a), lengthB(b) {}

    double area() const override{
        std::cout << lengthA * lengthB << std::endl;
        return lengthA * lengthB;
    }
};

int main(){
    // Shape shape1;
    // std::cout << shape1.area() << std::endl;
    // Not possible anymore -> abstract!
    Circle Circle1(2);
    Circle1.area();

    Rectangle Rectangle1(2, 4);
    Rectangle1.area();
    Circle circle1(1); 
    Rectangle rec1(1, 2);
    Circle circle2(2);
    Rectangle rec2(2, 3);

    constexpr int SIZE = 4;
    Shape* arr[SIZE];
    arr[0] = &circle1;
    arr[1] = &rec1;
    arr[2] = &circle2;
    arr[3] = &rec2;

    for(int i = 0; i < SIZE; i++){
        arr[i]->area();
    }
}