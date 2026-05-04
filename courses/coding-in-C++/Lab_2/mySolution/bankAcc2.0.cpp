#include <iostream>
#include <string>
#include <cstdint>


class BankAccount{
    private:
    std::string owner;
    double balance;

    public:
    void setOwner(std::string ownerName){
    owner = ownerName;
    }

    std::string getOwner(){
        return owner;
    }

    void deposit(double amount){
        
    }
    void withdraw(double amount);
    double getBalance();
    void getAccountBalance();
}