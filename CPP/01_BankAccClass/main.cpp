/* ==================================================================
 * A program to  implement  the bank account  class  with a/c holders
 * name, number, a/c type, balance amount.
 * ==================================================================
 */

#include <iostream>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 32

using namespace std;

int currentIndex = 0;   //-- Useful for determining an unique a/c no.

class Account {
    char * accName;     //-- Should be re-written using String class.
    int accNo;          //-- Should be kept unique using currentIndex
    char accType;       //-- Insert S for savings a/c, C for current.
    double balanceAmt;
public:
    void init();
    void getDetails();
    void deposit(double amount);
    bool withdraw(double amount); /* Function returns true if success
                                   * Minimum a/c balance of Rs. 1,000
                                   * should be kept.
                                   */
    char * determineAcType(char type); //-- Returns a/c type in words
    void display();
};

void Account::init() {
    accName = (char *)malloc(sizeof(char) * MAXLEN);
    strcpy(accName, " ");

    accNo = ++currentIndex;
    accType = 'n';
    balanceAmt = 0.0;
}

void Account::getDetails() {
    cout << "Name of a/c holder: ";
    cin >> accName;

    cout << "A/c type: ";
    cin >> accType;
}

void Account::deposit(double amount) {
    balanceAmt += amount;
}

bool Account::withdraw(double amount) {
    if(balanceAmt > 1000) {
        balanceAmt -= amount;
        return true;
    }
    else
        return false;
}

char * Account::determineAcType(char type) {
    char * accType;
    accType = (char *)malloc(sizeof(char) * 8);

    if(type == 'C')
        strcpy(accType, "Current");
    else
        strcpy(accType, "Savings");

    return accType;
}

void Account::display() {
    cout << "\n"
         << "Account number: " << accNo << "\n"
         << "Name of a/c holder: " << accName << "\n"
         << "A/c type: " << determineAcType(accType) << "\n"
         << "Balance in account: " << balanceAmt << "\n";
}

int main() {
    int op, index;
    int numberOfAccounts;
    int accNo;
    double amount;

    cout << "How many accounts to be created? ";
    cin >> numberOfAccounts;

    Account ac[numberOfAccounts];

    cout << "Enter details..\n";
    for(int i = 0 ; i < numberOfAccounts ; i++) {
        ac[i].init();
        ac[i].getDetails();
    }

    cout << "\n" << numberOfAccounts
         << " accounts successfully created with the following details..\n";
    for(int i = 0 ; i < numberOfAccounts ; i++) {
        ac[i].display();
    }

    while(1) {
        cout << "\n"
             << "\tChoose and operation..\n"
             << "\t1. Deposit money.\n"
             << "\t2. Withdraw from a/c.\n"
             << "\t3. Display details.\n"
             << "\t4. Exit application.\n"
             << "(1/2/3/4)? ";

        cin >> op;

        switch(op) {
            case 1:
                cout << "Enter a/c number: ";
                cin >> accNo;

                cout << "Enter deposit amount: ";
                cin >> amount;

                index = accNo - 1;
                ac[index].deposit(amount);

                break;
            case 2:
                cout << "Enter a/c number: ";
                cin >> accNo;

                cout << "Enter amount to withdraw: ";
                cin >> amount;

                index = accNo - 1;
                if(ac[index].withdraw(amount) != true) {
                    cout << ">>> You must have atleast Rs. 1000 in your account.\n"
                         << "Here is your a/c details..\n";
                    ac[index].display();
                }

                break;
            case 3:
                cout << "Enter a/c number: ";
                cin >> accNo;

                index = accNo - 1;
                ac[index].display();

                break;
            case 4:
                exit(0);
            default:
                cout << ">>> Wrong input.\n";
                continue;
        }
    }

    return 0;
}
