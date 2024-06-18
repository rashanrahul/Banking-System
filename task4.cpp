#include <iostream>
#include <string>
using namespace std;


class Bank {
private:
    int Acno;
    char name[30];
    long balance;

public:
    void OpenAccount()
    {
        cout << "* Enter the Account Number: ";
        cin >> Acno;
        cout << "Enter the Name: ";
        cin >> name;
        cout << "Enter the  Balance: ";
        cin >> balance;
        cout<<endl;
    }
    void ShowAccount()
    {
        cout << "Account Number: " << Acno << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
    }
    void Deposit()
    {
        long amt;
        cout << "You want to deposit? ";
        cin >> amt;
        balance = balance + amt;
    }
    void Withdrawal()
    {
        long amt;
        cout << "You want to withdraw? ";
        cin >> amt;
        if (amt <= balance)
            balance = balance - amt;
        else
            cout << "Low Balance..." << endl;
    }
    int Search(int);
};

int Bank::Search(int a)
{
    if (Acno == a) {
        ShowAccount();
        return (1);
    }
    return (0);
}

int main()
{
    Bank C[3];

    int found = 0, a, ch, i;
    for (i = 0; i <= 2; i++) {
        C[i].OpenAccount();
    }

    do {
        cout<<endl;
        cout<<endl;
        // display 
        cout <<"1:Display All : "<< endl;
        cout<<"2.By Account No : "<<endl;
        cout<<"3.Deposit : "<<endl;
        cout<<"4.Withdraw : "<<endl;
        cout<<"5.Exit : "<<endl;
        // user input
        cout<<endl;
        cout <<"Please input your choice: ";
        cin >> ch;
        cout<<endl;

        switch (ch) {
        case 1: 
            for (i = 0; i <= 2; i++) {
                C[i].ShowAccount();
            }
            break;
        case 2: 
            cout << "Account Number? ";
            cin >> a;
            for (i = 0; i <= 2; i++) {
                found = C[i].Search(a);
                if (found)
                    break;
            }
            if (!found)
                cout << "Record Not Found" << endl;
            break;
        case 3: 
            cout << "Account Number To Deposit Amount? ";
            cin >> a;
            for (i = 0; i <= 2; i++) {
                found = C[i].Search(a);
                if (found) {
                    C[i].Deposit();
                    break;
                }
            }
            if (!found)
                cout << "Record Not Found" << endl;
            break;
        case 4: // withdraw 
            cout << "Account Number To Withdraw Amount? ";
            cin >> a;
            for (i = 0; i <= 2; i++) {
                found = C[i].Search(a);
                if (found) {
                    C[i].Withdrawal();
                    break;
                }
            }
            if (!found)
                cout << "Record Not Found" << endl;
            break;
        case 5: // exit
            cout << "Have a nice day" << endl;
            break;
        default:
            cout << "Wrong Option" << endl;
        }
    } while (ch != 5);
    return 0;
}