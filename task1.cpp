#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Transaction {
private:
    string type;
    double amount;

public:
    Transaction(string type, double amount) : type(type), amount(amount) {}

    string getType() {
        return type;
    }

    double getAmount() {
        return amount;
    }
};

class BankAccount {
private:
    string accountNumber;
    string accountHolderName;
    double balance;
    string accountTypeStr;
    vector<Transaction> transactions;

public:
    BankAccount(string accountHolder, double initialBalance, string accountType)
        : accountNumber(generateAccountNumber()), accountHolderName(accountHolder),
          balance(initialBalance), accountTypeStr(accountType) {}

    // Deposit money into the account
    void deposit(double amount) {

        balance += amount;
        recordTransaction("Deposit", amount);
    }
    // Withdraw money from the account
    bool withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            recordTransaction("Withdraw", amount);
            return true;
        }
        return false; // Insufficient funds
    }

    // Transfer money from this account to another account
    bool transfer(BankAccount& recipient, double amount) {
        if (withdraw(amount)) {
            recipient.deposit(amount);
            recordTransaction("Transfer", amount);
            return true; 
        }
        return false; // Insufficient funds
    }

    // Get account details
    void printAccountDetails() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Balance: $" << balance << endl;
        cout << "Account Type: " << accountTypeStr << endl;
    }

    // Display transaction history
    void printTransactionHistory() {
        for (Transaction& transaction : transactions) {
            cout << "Type: " << transaction.getType() << ", Amount: $" << transaction.getAmount() << endl;
        }
    }

private:
    // Generate a unique account number (simplified for the example)
    string generateAccountNumber() {
        static int nextAccountNumber = 1;
        return "ACCT" + to_string(nextAccountNumber++);
    }

    // Record a transaction
    void recordTransaction(string type, double amount) {
        transactions.push_back(Transaction(type, amount));
    }
};

int main() {
    // Create instances of the BankAccount class
    BankAccount account1("Muhammad Ishaq", 1000.0, "Savings");
    BankAccount account2("Muhammad Ashar Javid", 500.0, "Checking");

    double acc, x, y;
    char c;

    // Perform transactions
    cout << "Enter the amount to deposit in Account 1: ";
    cin >> x;
    account1.deposit(x);
    cout << "Enter the amount to deposit in Account 2: ";
    cin >> x;
    account2.deposit(x);
    cout << "Enter the amount to withdraw from Account 1: ";
    cin >> y;
    account1.withdraw(y);
    cout << "Enter the amount to withdraw from Account 2: ";
    cin >> y;
    account2.withdraw(y);

    cout << "Would you like to transfer money (y/n): ";
    cin >> c;

    if (c == 'y' || c == 'Y') {
        double money;
        cout << "Press 1 to transfer money from account 1 to account 2, Press 2 to transfer money from account 2 to account 1: ";
        cin >> acc;
        if (acc == 1) {
            cout << "How much you would like to transfer "<<endl;
            cin >> money;
            account1.transfer(account2, money);
        } else if (acc == 2) {
            cout << "How much you would like to transfer "<<endl;
            cin >> money;
            account2.transfer(account1, money);
        } else {
            cout << "Invalid input" << endl;
        }
    }

    // Display account details and transaction history
    cout << "Account 1 Details:\n";
    account1.printAccountDetails();
    cout << "Transaction History:\n";
    account1.printTransactionHistory();

    cout << "\nAccount 2 Details:\n";
    account2.printAccountDetails();
    cout << "Transaction History:\n";
    account2.printTransactionHistory();

    return 0;
}
