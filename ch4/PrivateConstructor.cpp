#include <iostream>
using namespace std;

class AAA {

private :
    int num;

public :
    AAA() : num(0) {} // 클래스 외부에서는 이 생성자를 기반으로 객체를 생성한다.
    AAA& CreateInitObj(int n) const { // private 생성자를 이용해 AAA 객체 생성 및 반환
        AAA *ptr = new AAA(n);
        return *ptr;
    }

    void ShowNum() const {cout<<num<<endl;}

private : // private 생성자
    AAA(int n) : num(n) {}

};

int main(void) {
    AAA base;
    base.ShowNum();

    AAA &obj1 = base.CreateInitObj(43);
    obj1.ShowNum();

    delete &obj1;
    return 0;
}