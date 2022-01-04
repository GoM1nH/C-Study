#include <iostream>
using namespace std;

class SoSimple {

private :
    int num1;
    int num2;

public :
    SoSimple(int n1, int n2) : num1(n1), num2(n2) { } // 그냥 생성자

    SoSimple(const SoSimple &copy) : num1(copy.num1), num2(copy.num2) { // 복사 생성자!
        cout<<"Called SoSimple(SoSimple &copy)"<<endl;
    } // 만약 이 복사 생성자를 따로 선언해주지 않으면 디폴트 복사 생성자가 존재할것이다.
    
    void ShowSimpleData() {
        cout<<num1<<endl;
        cout<<num2<<endl;
    }
};

int main() {

    SoSimple sim1(15, 30);
    SoSimple sim2 = sim1;
    sim2.ShowSimpleData();

    return 0;
}