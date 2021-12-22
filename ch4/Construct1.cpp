#include <iostream>

using namespace std;

class AClass {

private :

    int num1;
    int num2;

public :

    AClass() { // 생성자의 형태! 반환형 없고 + class의 이름과 같다
        int num1 = 0;
        int num2 = 0;
    }

    AClass(int n) {
        num1 = n;
        num2 = 0;
    }

    AClass(int n1, int n2) {
        num1 = n1;
        num2 = n2;
    }

    /* AClass(int n1 = 0, int n2 = 0) { // default값도 설정 가능
        num1 = n1;
        num2 = n2;
    } */

    void ShowData() const {
        cout<<num1<<' '<<num2<<endl;
    }
};

int main() {
    AClass cls1;
    cls1.ShowData();

    AClass cls2(321);
    // 만약 동적할당으로 선언하고 싶다면
    // AClass *ptr = new AClass(321);
    cls2.ShowData();

    AClass cls3(843, 927);
    cls3.ShowData();

    return 0;
}