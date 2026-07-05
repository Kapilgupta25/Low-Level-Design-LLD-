#include <bits/stdc++.h>
using namespace std;


class Account{
public:
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
};

class SavingsAccount : public Account {
private:
    double balance;

public:
    SavingsAccount(){
        balance = 0.0;
    }

    void deposit(double amount) override {
        balance += amount;
        cout << "Deposited: " << amount << ", New Balance: " << balance << endl;
    }

    void withdraw(double amount) override {
        if (amount > 0 && amount <= balance){
            balance -= amount;
            cout << "Withdrawn: " << amount << ", New Balance: " << balance << endl;
        } else {
            cout << "Withdrawal amount exceeds balance or is invalid." << endl;
        }
    }
};

class CurrentAccount : public Account {
private:
    double balance;
public:
    CurrentAccount() {
        balance = 0.0;
    }
    void deposit(double amount) override {
        balance += amount;
        cout << "Deposited: " << amount << ", New Balance: " << balance << endl;
    }

    void withdraw(double amount) override {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << ", New Balance: " << balance << endl;
        } else {
            cout << "Withdrawal amount exceeds balance or is invalid." << endl;
        }
    }
};  


class FixedDepositAccount : public Account {
private:
    double balance;

public:

    FixedDepositAccount() {
        balance = 0.0;
    }
    void deposit(double amount) override {
        balance += amount;
        cout << "Deposited: " << amount << ", New Balance: " << balance << endl;
    }

    void withdraw(double amount) override {
        throw logic_error("Withdrawals are not allowed from Fixed Deposit accounts.");
    }
};


class Client{
private:
    vector<Account*> accounts;

public:
    void addAccount(vector<Account*> account) {
        this->accounts= account;
    }

    void processTransactions() {
        for (auto& account : accounts) {
            account->deposit(100.0);    // Deposit 100.0 to each account

            // checking account type before withdrawal exciplitly
            // voilating OCP but following LSP as we have to change the code here for any new type of account id added in the bank
            if(typeid(*account) == typeid(FixedDepositAccount)) {
                cout << "Cannot withdraw from Fixed Deposit Account." << endl;
            } else {
                account->withdraw(50.0); // Withdraw 50.0 from each account
            }
        }
    }

};

int main(){

    vector<Account*> accounts;
    accounts.push_back(new SavingsAccount());
    accounts.push_back(new CurrentAccount());
    accounts.push_back(new FixedDepositAccount());

    Client* client = new Client();
    client->addAccount(accounts);
    client->processTransactions();
    
    return  0;
}