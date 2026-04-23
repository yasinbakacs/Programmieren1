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
    std::string getOwner(){
        return owner;
    }
    void deposit(double amount){
        if (amount <= 0){
            std::cout <<"Invalid deposit amount. \n" << std::endl;
            return;
        }
        balance += amount;
    }

    void withdraw(double amount){
        if (amount < 0){
            std::cout << "Invalid withdraw amount. \n";
        }
        if (amount  > balance){
            std::cout << "Not enough money on account. \n" << std::endl;
        }else{
            balance -= amount;
        }
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

    BankAccount myAcc;
    myAcc.setOwner("Bobby");

    myAcc.getAccountInfo();

    myAcc.deposit(15.15);

    myAcc.getAccountInfo();

    myAcc.withdraw(15.16);

    myAcc.deposit(-12.3);

    myAcc.withdraw(15.14);

    myAcc.getAccountInfo();


}