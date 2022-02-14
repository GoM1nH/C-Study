#include <iostream>
#include <cstring>

using namespace std;

/* 계좌 정보 */

class Info {
    
private:
    int id;
    char *name;
    int balance;
    
public:
    Info (int idNum, char *myName, int money) : id(idNum), balance(money) {
        name = new char[strlen(myName)+1];
        strcpy(name, myName);
    }

    Info (const Info &copy) : id(copy.id), balance(copy.balance) {
        name = new char[strlen(copy.name) + 1];
        strcpy(name, copy.name);
    }

    int GetID() const {
        return id;
    }

    void Deposit(int money) {
        balance += money;
    }

    void Withdraw(int money) {
        balance -= money;
    }

    void ShowInfo() const {
        cout<<"ID : "<<id<<endl;
        cout<<"name : "<<name<<endl;
        cout<<"balance : "<<balance<<endl;
        cout<<"\n";
    }

    ~Info() {
        delete []name;
    }
};

/* Control Class */

class AccountHandler { 
private :
    Info *users[100];
    int NumOfUsers;
    
public :
    AccountHandler() : NumOfUsers(0);
    void MakeAccount();
    void DepositMoney();
    void WithdrawMoney();
    void ShowAllAccount() const;
    ~AccountHandler() {
        for (int i=0 ; i<NumOfUsers ; i++) {
            delete users[i];
        }
    }
};

void AccountHandler::MakeAccount() {
    int id;
    char name[20];
    int money;

    cout<<"Bank ID : ";
    cin>>id;
    cout<<"name : ";
    cin>>name;
    cout<<"money : ";
    cin>>money;
    cout<<endl;

    users[NumOfUsers++] = new Info(id, name, money);
}

void AccountHandler::DepositMoney() {
    int id;
    int money;

    cout<<"Deposit Money in your Account."<<endl;
    cout<<"What's your ID : ";
    cin>>id;
    cout<<"money : ";
    cin>>money;

    for(int i=0 ; i<NumOfUsers ; i++) {
        if (users[i]->GetID() == id) {
            users[i]->Deposit(money);
            cout<<"Deposit Finish"<<"\n"<<endl;
            return;
        }
    }

    cout<<"invalid ID"<<"\n"<<endl;
}
void AccountHandler::WithdrawMoney() {
    int id;
    int money;

    cout<<"Withdraw Money in your account."<<endl;
    cout<<"What's your ID : ";
    cin>>id;
    cout<<"money : ";
    cin>>money;

    for(int i=0 ; i<NumOfUsers ; i++) {
        if (users[i]->GetID() == id) {
            users[i]->Withdraw(money);
            cout<<"Withdraw Finish"<<"\n"<<endl;
            return;
        }
    }

    cout<<"invalid ID"<<"\n"<<endl;
}

void AccountHandler::ShowAllAccount() const{
    for(int i=0 ; i<NumOfUsers ; i++) {
        users[i]->ShowInfo();
    }
}

/* Main 함수 */

int main() {

    while(1) {
        AccountHandler Handle;
        int num;

        cout<<"\n---Menu---"<<endl;
        cout<<"1. Make Account"<<endl;
        cout<<"2. Deposit"<<endl;
        cout<<"3. Withdraw"<<endl;
        cout<<"4. Show All Account in this bank"<<endl;
        cout<<"5. QUIT"<<"\n"<<endl;

        cout<<"What you want? : ";
        cin>>num;
        cout<<endl;

        switch(num) {
            case 1 :
                Handle.MakeAccount();
                break;
            case 2 :
                Handle.DepositMoney();
                break;
            case 3 :
                Handle.WithdrawMoney();
                break;
            case 4 :
                Handle.ShowAllAccount();
                break;
            case 5 :
                for(int i=0 ; i<NumOfUsers ; i++) {
                    delete users[i];
                }
                cout<<"QUIT."<<endl;
                return 0;
            default :
                cout<<"Invalid Section"<<"\n"<<endl;
        }
    }

    return 0;
} 