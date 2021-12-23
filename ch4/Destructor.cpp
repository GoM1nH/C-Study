#include <iostream>
#include <cstring>
using namespace std;

class Person {

private :

    char *name;
    int age;

public :

    Person(char *myname, int myage) { // 생성자
        int len = strlen(myname) + 1;
        name = new name[len];
        strcpy(name, myname);
        age = myage;
    }

    void ShowPersonInfo() const {
        cout<<"Name : "<<name<<endl;
        cout<<"Age : "<<name<<endl;
    }

    ~Person() { // 소멸자
        delete []name; // 앞서 Person에서 할당한 리소스(메모리 공간)를 소멸시킨다!
        cout<<"DESTRUCTOR"<<endl;
    }

}

int main() {
    Person man1("Lee", 25);
    Person man2("Gang", 21);
    man1.ShowPersonInfo();
    man2.ShowPersonInfo();

    return 0;
}