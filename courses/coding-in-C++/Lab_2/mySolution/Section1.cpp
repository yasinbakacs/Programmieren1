#include <iostream>
#include <string>

class BankAccount{
    private:
    std::string owner;
    double balance;

    public:
    void setOwner(std::string ownerName){
        owner = ownerName;
    }
    std::getOwner(){
        return owner;
    }
    void deposit(double amount){
        if (amount <= 0){
            std::cout <<"Invalid deposit amount." << std::endl;
            return;
        }
        balance += amount;
    }
    void withdraw(double amount){
        if (amount  > balance){
            std::cout << "Not enough money on account." << std::endl;
        }
        balance -= amount;
        
    }
}