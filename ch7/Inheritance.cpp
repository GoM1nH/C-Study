#include <iostream>
#include <cstring>
using namespace std;

class Person {
private:
    int age;
    char name[50];
public:
    Person(int myage, char* myname) : age(myage) {
        strcpy(name, myname);
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
        strcpy(major, mymajor);
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