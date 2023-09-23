#include <iostream>
#include <vector>
#include <string>

using namespace std;

class BankAccount {
private:
    string accHolderName;
    string mobileNumber;
    int pin;
    int accNumber;
    double accountBalance;

public:
    BankAccount(string name, string mobile, int pin, int accountNumber) {
        this->accHolderName = name;
        this->mobileNumber = mobile;
        this->pin = pin;
        this->accNumber = accountNumber;
        this->accountBalance = 0;
    }

    void displayAccountDetails() {
        cout << "Account Number: " << accNumber << endl;
        cout << "Name: " << accHolderName << endl;
        cout << "Mobile: " << mobileNumber << endl;
        cout << "Balance: $" << accountBalance << endl;
    }

    void setPin(int newPin) {
        this->pin = newPin;
    }

    bool verifyPin(int enteredPin) {
        return this->pin == enteredPin;
    }

    void deposit(double amount) {
        accountBalance += amount;
        cout << "Amount deposited successfully! New balance: $" << accountBalance << endl;
    }

    void withdraw(double amount) {
        if (amount > accountBalance) {
            cout << "Insufficient balance!" << endl;
        } else {
            accountBalance -= amount;
            cout << "Amount withdrawn successfully! New balance: $" << accountBalance << endl;
        }
    }

    void updateAccountDetails(string name, string mobile, int pin) {
        this->accHolderName = name;
        this->mobileNumber = mobile;
        this->pin = pin;
        cout << "Account details updated successfully!" << endl;
    }

    void deleteAccount() {
        // Reset account details
        accHolderName = "";
        mobileNumber = "";
        pin = 0;
        accountBalance = 0;
        cout << "Account deleted successfully!" << endl;
    }

    int getAccountNumber() {
        return accNumber;
    }

    int getPin() {
        return pin;
    }
};

int findAccount(vector<BankAccount>& accounts, int accountNumber) {
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i].getAccountNumber() == accountNumber) {
            return i;
        }
    }
    return -1;
}

int main() {
    vector<BankAccount> bankAccounts;
    int choice;
    int accountNumber;
    int pin;
    string name;
    string mobile;
    double amount;
    int index;

    do {
        cout << "     ######  Bank Management System ######" <<endl;
        cout << "###############################################"<<endl;
        cout << "########### 1. Open an account      ###########" << endl;
        cout << "########### 2. Show account details ###########" << endl;
        cout << "########### 3. Deposit              ###########" << endl;
        cout << "########### 4. Withdraw             ###########" << endl;
        cout << "########### 5. Edit account details ###########" << endl;
        cout << "########### 6. Delete account       ###########" << endl;
        cout << "########### 7. Exit                 ###########" << "\n" <<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Open an account
                cout << "Enter name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter mobile: ";
                getline(cin, mobile);
                cout << "Enter PIN (4 digits): ";
                cin >> pin;
                accountNumber = bankAccounts.size() + 1;
                bankAccounts.push_back(BankAccount(name, mobile, pin, accountNumber));
                cout << "Account created successfully! Account Number: " << accountNumber << endl;
                break;
            case 2:
                // Show account details
                cout << "Enter account number: ";
                cin >> accountNumber;
                index = findAccount(bankAccounts, accountNumber);
                if (index != -1) {
                    int enteredPin;
                    cout << "Enter PIN for VERIFICATION: ";
                    cin >> enteredPin;
                    if (bankAccounts[index].verifyPin(enteredPin)) {
                        bankAccounts[index].displayAccountDetails();
                    } else {
                        cout << "Incorrect PIN!" << endl;
                    }
                } else {
                    cout << "Account not found!" << endl;
                }
                break;
            case 3:
                // Deposit
                cout << "Enter account number: ";
                cin >> accountNumber;
                index = findAccount(bankAccounts, accountNumber);
                if (index != -1) {
                    int enteredPin;
                    cout << "Enter PIN for VERIFICATION: ";
                    cin >> enteredPin;
                    if (bankAccounts[index].verifyPin(enteredPin)) {
                        cout << "Enter deposit amount: $";
                        cin >> amount;
                        bankAccounts[index].deposit(amount);
                    } else {
                        cout << "Incorrect PIN!" << endl;
                    }
                } else {
                    cout << "Account not found!" << endl;
                }
                break;
            case 4:
                // Withdraw
                cout << "Enter account number: ";
                cin >> accountNumber;
                index = findAccount(bankAccounts, accountNumber);
                if (index != -1) {
                    int enteredPin;
                    cout << "Enter PIN for VERIFICATION: ";
                    cin >> enteredPin;
                    if (bankAccounts[index].verifyPin(enteredPin)) {
                        cout << "Enter withdrawal amount: $";
                        cin >> amount;
                        bankAccounts[index].withdraw(amount);
                    } else {
                        cout << "Incorrect PIN!" << endl;
                    }
                } else {
                    cout << "Account not found!" << endl;
                }
                break;
            case 5:
                // Edit account details
                cout << "Enter account number: ";
                cin >> accountNumber;
                index = findAccount(bankAccounts, accountNumber);
                if (index != -1) {
                    int enteredPin;
                    cout << "Enter PIN for VERIFICATION: ";
                    cin >> enteredPin;
                    if (bankAccounts[index].verifyPin(enteredPin)) {
                        cout << "Enter new name: ";
                        cin.ignore();
                        getline(cin, name);
                        cout << "Enter new mobile: ";
                        getline(cin, mobile);
                        cout << "Enter new PIN (4 digits): ";
                        cin >> pin;
                        bankAccounts[index].updateAccountDetails(name, mobile, pin);
                    } else {
                        cout << "Incorrect PIN!" << endl;
                    }
                } else {
                    cout << "Account not found!" << endl;
                }
                break;
            case 6:
                // Delete account
                cout << "Enter account number: ";
                cin >> accountNumber;
                index = findAccount(bankAccounts, accountNumber);
                if (index != -1) {
                    int enteredPin;
                    cout << "Enter PIN for VERIFICATION: ";
                    cin >> enteredPin;
                    if (bankAccounts[index].verifyPin(enteredPin)) {
                        bankAccounts[index].deleteAccount();
                        bankAccounts.erase(bankAccounts.begin() + index);
                    } else {
                        cout << "Incorrect PIN!" << endl;
                    }
                } else {
                    cout << "Account not found!" << endl;
                }
                break;
            case 7:
                // Exit
                cout << "Thank you for using Bank Management System. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 7);

    return 0;
}
