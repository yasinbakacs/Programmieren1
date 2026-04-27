#include <iostream>
#include <cstdint>
#include <string>

class User{
    protected:
    std::string name;
    int id;

    public:
    User(std::string name, int id) : name(name), id(id){
        std::cout << "Constructor User\n";
    };
    void printInfo();
};

void User::printInfo(){
    std::cout << "Name: " << name << std::endl;
    std::cout << "ID: " << id << std::endl;
}


class Student : public User {
    private:
    int matrikelnummer;

    public:
    Student(std::string name, int id, int matrikelnummer) : User(name, id), matrikelnummer(matrikelnummer){
        std::cout << "Constructor Student\n";
    };

    void printRole();


};

void printRole

class Instructor : public User {
    private:
    int profnummer;
}