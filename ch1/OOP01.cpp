#include <iostream>
#include <cstring>

using namespace std;

typedef struct _info {
    
    int id;
    char name[20];
    int balance;
    
} Information;

Information users[100];

int main() {
    int NumOfUsers = 0;

    while(1) {
        int num;

        cout<<"\n---Menu---"<<endl;
        cout<<"1. 계좌개설"<<endl;
        cout<<"2. 입 금"<<endl;
        cout<<"3. 출 금"<<endl;
        cout<<"4. 계좌정보 전체 출력"<<endl;
        cout<<"5. 종료"<<endl;

        cout<<"선택 : ";
        cin>>num;

        if (num == 1) {
            int id;
            char name[20];
            int balance;

            cout<<"계좌id : ";
            cin>>id;
            cout<<"성함 : ";
            cin>>name;
            cout<<"첫 입금 금액 : ";
            cin>>balance;

            users[NumOfUsers].id = id;
            strcpy(users[NumOfUsers].name, name);
            users[NumOfUsers].balance = balance;
            NumOfUsers += 1;
        } else if (num == 2) {
            int id;
            int money;
            
            cout<<"입금할 계좌 : ";
            cin>>id;
            cout<<"\n";

            for (int i=0 ; i<NumOfUsers ; i++) {
                if (users[i].id == id) {
                    cout<<"입금할 금액 : ";
                    cin>>money;
                    users[i].balance += money;
                    
                    cout<<"\n입금 완료\n";
                    break;
                }
            }
        } else if (num == 3) {
            int id;
            int money;
            
            cout<<"출금할 계좌 : ";
            cin>>id;
            cout<<"\n";

            for (int i=0 ; i<NumOfUsers ; i++) {
                if (users[i].id == id) {
                    cout<<"출금할 금액 : ";
                    cin>>money;
                    if ((users[i].balance - money) < 0) {
                       cout<<"계좌에 잔고가 부족합니다.\n";
                       break;
                    } 

                    users[i].balance -= money;
                    
                    cout<<"\n출금 완료\n";
                    break;
                }
            }
        } else if (num == 4) {
            for (int i=0 ; i<NumOfUsers ; i++) {
                cout<<i+1<<"번째 \n";
                cout<<"계좌ID : "<<users[i].id<<endl;
                cout<<"이름 : "<<users[i].name<<endl;
                cout<<"잔고 : "<<users[i].balance<<endl;
            }
        } else {
            cout<<"\n";
            break;
        }

    }

    cout<<"프로그램을 종료합니다."<<endl;

    return 0;
} 
