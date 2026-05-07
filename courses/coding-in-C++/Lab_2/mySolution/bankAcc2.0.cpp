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
            std::cout << "Amount has to be bigger than 0." << std::endl;
        }
    }
    void withdraw(double amount){
        if(amount < 1){
            std::cout << "Amount has to be greater than 0.";
            return;
        }
        if(amount > balance){
            std::cout << "Amount grater than balance. Your current balance is: "
                      << balance << std::endl;
            return;
        }

        balance -= amount;
        std::cout << "Withdrawel successful. Your new balance is: " << amount << std::endl;

    }
    double getBalance();
    void getAccountInfo();
};

double BankAccount::getBalance(){
    return balance;
}

void BankAccount::getAccountInfo(){
    std::cout << "Owner: " << getOwner() << std::endl;
    std::cout << "Balance: " << getBalance() << std::endl;
}


int main(){
    BankAccount Acc1;
    Acc1.setOwner("Bob");
    Acc1.getAccountInfo();
    Acc1.deposit(10);
    Acc1.getAccountInfo();
}