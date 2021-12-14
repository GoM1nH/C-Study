#include <iostream>
using namespace std;

#define ID_LEN  10

struct User {
    char gamerID[ID_LEN];
    int rank;
    int point;

    void ShowGamerState() {
        cout<<"Gamer ID :"<<gamerID<<endl;
        cout<<"His / Her rank is : "<<rank<<endl;
        cout<<"His / Her Point is : "<<point<<endl;
        cout<<"\n";
    }

    void PointUP() {
        point += 10;
    }
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