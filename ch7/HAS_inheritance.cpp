#include <iostream>
#include <cstring>
using namespace std;

class Gun {
private :
    int bullet;
public :
    Gun(int bnum) : bullet(bnum) { }
    void Shot() {
        cout<<"BBANG!"<<endl;
        bullet--;
    }
};

class Police : public Gun { // 이 class의 상속 관계를 HAS-A로 표현하면 "Police has a Gun"이 된다.
private :
    int handcuffs;
public :
    Police(int bnum, int bcuff) : Gun(bnum), handcuffs(bcuff) { }
    void PutHandCuff() {
        cout<<"SNAP!"<<endl;
        handcuffs--;
    }
};

int main() {
    Police pman(5, 3);
    pman.Shot();
    pman.PutHandCuff();
    
    return 0;    
}