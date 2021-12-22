#include <iostream>
#include "Rectangle.h"
using namespace std;

Rectangle(const int &x1, const int &y1, const int &x2, const int &y2) : upLeft(x1, y1), lowRight(x2, y2) { // Member Initializer ver.
// upLeft(x1, y1) : upLeft의 생성과정에서 x1, y1을 인자로 전달받는 생성자를 호출하라
// lowRight(x2, y2) : lowRight의 생성과정에서 x2, y2를 인자로 전달받는 생성자를 호출하라

    /* if(ul.GetX() > lr.GetX() || ul.GetY()>lr.GetY()) { // 만약 좌상단과 우하단의 좌표가 뒤바뀌는 경우를 대비한 if문
        cout<<"LOCATION SET ERROR"<<endl;
        return false;
    }

    upLeft = ul;
    lowRight = lr;
    return true; 생성자 아닌 버전*/
}

void Rectangle::ShowRecInfo() const {
    cout<<"Up Left : "<<"["<<upLeft.GetX()<<", "<<upLeft.GetY()<<"]"<<endl;
    cout<<"Low Right : "<<"["<<lowRight.GetX()<<", "<<lowRight.GetY()<<"]"<<endl<<endl;
}