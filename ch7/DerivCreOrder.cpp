#include <iostream>
using namespace std;

class Base {

private:
    int baseNum;
public:
    Base() : baseNum(20) {
        cout<<"Base() call"<<endl;
    }
    Base(int n) : baseNum(n) {
        cout<<"Base(int n) call"<<endl;
    }
    void ShowBaseData() {
        cout<<baseNum<<endl
    }

    ~Base() {
        cout<<"~Base called"<<endl;
    }
};

class Derived : public Base { // Base를 상속받는다. Derived가 상속하는 클래스, Base가 상속되는 클래스
private :
    int derivNum;
public :
    Derived() : derivNum(34) {
        cout<<"Derived() called"<<endl;
    }
    Derived(int n) : derivNum(n) {
        cout<<"Derived(int n) called"<<endl;
    }
    Derived(int n1, int n2) : Base(n1), derivNum(n2) {
        cout<<"Derived(int n1, int n2) called"<<endl;
    }

    void ShowDerivNum() {
        ShowBaseData();
        cout<<derivNum<<endl;
    }

    ~Derived() {
        cout<<"~Derived called"<<endl;
    }
};

int main() {
    cout<<"case 1 :"<<endl;
    Derived dr1;
    dr1.ShowDerivNum();
    cout<<"case 2 :"<<endl;
    Derived dr2(12);
    dr2.ShowDerivNum();
    cout<<"case 3 :"<<endl;
    Derived dr3(14, 83);
    dr3.ShowDerivNum();

    return 0;
}