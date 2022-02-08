#include <iostream>
#include <cstring>
using namespace std;

class MyFriendInfo {
private :
    char *name;
    int age;
public :
    MyFriendInfo(char *theyname, int theyage) : age(theyage) {
        name = new char[strlen(theyname) + 1];
        strcpy(name, theyname);
    }

    ~MyFriendInfo() {
        delete []name;
    }

    void ShowMyFriendInfo() {
        cout<<"Name : "<<name<<endl;
        cout<<"Age : "<<age<<endl;
    }
};

class MyFriendDetail : public MyFriendInfo {
private:
    char *addr;
    char *phone;
public:
    MyFriendDetail(char *theyname, int theyage, char *theyaddr, char *theyphone) : MyFriendInfo(theyname, theyage) {
        addr = new char[strlen(theyaddr) + 1];
        strcpy(addr, theyaddr);

        phone = new char[strlen(theyphone) + 1];
        strcpy(phone, theyphone);
    }

    ~MyFriendDetail() {
        delete []addr;
        delete []phone;
    }

    void ShowDetail() {
        ShowMyFriendInfo();
        cout<<"Addr : "<<addr<<endl;
        cout<<"Phone Num : "<<phone<<endl<<endl;
    }
};

int main() {
    MyFriendDetail he("Go", 23, "Seoul", "010-3432-4566");
    he.ShowDetail();

    return 0;
}