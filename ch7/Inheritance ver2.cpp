#include <iostream>
#include <cstring>
using namespace std;

// 각 클래스마다 소멸자가 추가되었다.
// 각 생성자에 동적할당을 해주며, 이에 따라 소멸자에서 메모리 해제를 해준다.

class Person {
private:
    int age;
    char *name;
public:
    Person(int myage, char* myname) : age(myage) {
        name = new char[strlen(myname)+1];
        strcpy(name, myname);
    }

    ~Person() { // 생성자에서 동적 할당한 메모리 공간은 소멸자에서 해제해주는 과정을 거쳐야 한다.
        delete []name;
    }

    void Name() const {
        cout<<"Name is "<<name<<endl;
    }

    void Age() const {
        cout<<age<<"years old"<<endl;
    }
};

class UnivStudent : public Person {// ": public Person"은 Perseon 클래스의 상속을 의미함. 이 문장은 그 중에서도 public 상속을 의미한다.
private:
    char major[50];
public:
    UnivStudent(char *myname, int myage, char *mymajor) : Person(myage, myname) {
        major = new char[strlen(mymajor) + 1];
        strcpy(major, mymajor);
    }

    ~UnivStudent() { // 생성자에서 동적 할당한 메모리 공간은 소멸자에서 해제해주는 과정을 거쳐야 한다.
        delete []major;
    }

    void WhoAreYou() const {
        Name();
        Age();
        cout<<"Major is : "<<major<<endl<<endl;
    } // 이 Class가 Person class를 상속했기에 Person class의 Name 멤버함수, Age 멤버함수를 사용할 수 있다.
};

int main() {
    UnivStudent std1("Go", 23, "Multimedia Eng.");
    std1.WhoAreYou();
    
    UnivStudent std2("Bae", 23, "Math Edu.");
    std2.WhoAreYou();

    return 0;
}