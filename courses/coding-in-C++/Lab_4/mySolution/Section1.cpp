#include <iostream>
#include <cstdint>
#include <string>
#include <cmath>

class Vector2D{
    private:
    double x;
    double y;

    public:
    Vector2D() : x(0.0), y(0.0) {}
    Vector2D(double x, double y) : x(x), y(y) {}

    double getX() const {return x;}
    double getY() const {return y;}

    void print(int i) {
        std::cout << "x-Koordinate (" << i << "): " << x << std::endl;
        std::cout << "y-Koordinate (" << i << "): " << y << std::endl;
    }

    double getLength(){
        return sqrt((pow(x, 2) + pow(y, 2)));
    }

    double getLength(int percision) {
        double length = sqrt((pow(x, 2) + pow(y, 2)));
        double factor = pow(10.0, percision);
        return std::round(length * factor) / factor;
    }

    Vector2D& operator+=(const Vector2D& v){
        x += v.x;
        y += v.y;
        return *this;
    }

    
    // Vector2D operator*(double scalar){
    //     Vector2D vOut(scalar * x, scalar * y);
    //     return vOut;
    // }

    bool operator==(const Vector2D &v){
        if(x == v.x && y == v.y){
            std::cout << "Die Vektoren sind gleich." << std::endl;
            return true;
        }else{
            std::cout << "Die Vektoren sind nicht gleich" << std::endl;
            return false;
        }
    }
};

std::ostream& operator<<(std::ostream& output, const Vector2D& v){
    output << "x-Koordinate: " << v.getX() << std::endl << "y-Koordinate: " << v.getY() << std::endl;
    return output;
}

Vector2D operator*(double scalar, const Vector2D& vIn){
    Vector2D vOut(scalar * vIn.getX(), scalar * vIn.getY());
    return vOut;
}

Vector2D operator*(const Vector2D& vIn, double scalar){
    Vector2D vOut(scalar * vIn.getX(), scalar * vIn.getY());
    return vOut;
}

int main(){
    Vector2D vec1(1, 1);
    vec1.print(1);
    Vector2D vec2(7, 8);
    std::cout << vec1.getLength() << std::endl;
    std::cout << vec1.getLength(2) << std::endl;
    vec1 += vec2;
    std::cout << std::endl << vec1 << std::endl;
    Vector2D vec3;
    vec3 = 2 * vec1;
    std::cout << vec3 << std::endl;
    vec1 == vec2;
    Vector2D vec4;
    vec4 += vec2;
    vec4 == vec2;
   
}