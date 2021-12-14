#include <iostream>
using namespace std;

namespace ID_CONST {
    enum {
        ID_LEN = 10
    };
}

struct User {

    char gamerID[ID_CONST::ID_LEN]; // 범위 지정 연산자 사용
    int rank;
    int point;

    void ShowGamerState();

    void PointUP();

};

int main() {

    User A = {"Coutei", 31, 1420};
    A.ShowGamerState();
    A.PointUP();
    A.ShowGamerState();

    User B = {"PrettyG", 143, 780};
    B.ShowGamerState();
    B.PointUP();
    B.PointUP();
    B.ShowGamerState();

    return 0;
}

void User::ShowGamerState() {
    cout<<"Gamer ID :"<<gamerID<<endl;
    cout<<"His / Her rank is : "<<rank<<endl;
    cout<<"His / Her Point is : "<<point<<endl;
    cout<<"\n";
}

void User::PointUP() {
    point += 10;    
}