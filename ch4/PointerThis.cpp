#include <iostream>
#include <cstring>
using namespace std;

class SoSimple {
private :
    int num;
public :
    SoSimple(int n) : num(n) {
        cout<<num<<", "<<"address ="<<this<<endl; // this 포인터 등장
    }

    SoSimple * GetThisPointer() {
        return this; // 객체 자신의 주소값을 반환한다는 의미다. 즉, this는 객체 자신의 주소값을 대신하는 표현.
    }
};

int main() {
    SoSimple example(100);
    SoSimple *ptr = example.GetThisPointer(); // ptr에 example 객체의 주소값 저장
}