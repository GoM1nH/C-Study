#include <iostream>
using namespace std;

class Person {
public :
    void Sleep() {
        cout<<"Sleep.. zzZ"<<endl;
    }
};

class Student : public Person {
public :
    void Study() {
        cout<<"Study Now."<<endl;
    }
};

class PartTimeStudent : public Student {
public :
    void Work() {
        cout<<"Work hard.."<<endl;
    }
};

int main() {
    Person *ptr1 = new Student();
    // 포인터 변수 ptr1은 Student 객체의 주소값을 저장하고 있다.
    // 학생(Student)은 사람(Person)이다 라는 IS-A 관계를 성립시킬 수 있다.
    Student *ptr2 = new PartTimeStudent();
    // 포인터 변수 ptr2는 PartTimeStudent 객체의 주소값을 저장하고 있다.
    // 근로학생(PartTimeStudent)은 학생(Person)이다 라는 IS-A 관계를 성립시킬 수 있다.
    
    ptr1->Sleep();
    ptr2->Study();

    delete ptr1;
    delete ptr2;

    return 0;
}