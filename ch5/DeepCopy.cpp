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

    Person(const Person& p) : age(p.age) { // age를 대상으로 멤버 변수 복사가 일어남.
        name = new char[strlen(p.name)+1]; // 메모리 공간 할당 후 문자열을 복사하여
        strcpy(name, p.name); // 할당된 메모리의 "주소값"을 멤버 name에 저장
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
    Person man2 = man1;
    man1.ShowPersonInfo();
    man2.ShowPersonInfo();

    return 0;
}