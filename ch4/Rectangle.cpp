#include <iostream>
#include "Rectangle.h"
using namespace std;

bool Rectangle::InitMembers(const Point &ul, const Point &lr) {
    if(ul.GetX() > lr.GetX() || ul.GetY()>lr.GetY()) { // 만약 좌상단과 우하단의 좌표가 뒤바뀌는 경우를 대비한 if문
        cout<<"LOCATION SET ERROR"<<endl;
        return false;
    }

    upLeft = ul;
    lowRight = lr;
    return true;
}

void Rectangle::ShowRecInfo() const {
    cout<<"Up Left : "<<"["<<upLeft.GetX()<<", "<<upLeft.GetY()<<"]"<<endl;
    cout<<"Low Right : "<<"["<<lowRight.GetX()<<", "<<lowRight.GetY()<<"]"<<endl<<endl;
}