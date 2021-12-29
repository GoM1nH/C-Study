#include <iostream>
#include <cstring>
using namespace std;

class Person {

private :
    char *name;
    int age;
public :
    Person (char *myname, int myage) : age(myage) {
        int len = strlen(myname) + 1;
        name = new char[len];
        strcpy(name, myname);
    }

    Person() { // 배열 선언을 위해서다. 선언과 동시에 배열 초기화를 진행한다고 생각하면 됨.
        name = NULL;
        age = 0;
    }

    void SetPersonInfo(char *myname, int myage) {
        name = myname;
        age = myage;
    }

    ~Person() { // 소멸자
        delete []name;
        cout<<"Called DESTRUCTOR"<<endl;
    }
};

int main() {
    Person *parr[3];
    char namestr[100];
    int age;

    for (int i=0 ; i<3; i++) {
        cin>>namestr;
        cin>>age;
        parr[i] = new Person(namestr, age);
    }

    delete parr[0];
    delete parr[1];
    delete parr[2];

    return 0;
}