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
        if(amount > 0){
            balance += amount;
        }else{
            std::cout << "Input not valid." << std::endl;
        }
    }
    void withdraw(double amount){
        if(amount < 1){
            
        }
    }
    double getBalance();
    void getAccountBalance();
}