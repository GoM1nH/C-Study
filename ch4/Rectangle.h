#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

#include "Point.h"

class Rectangle { // 이 Rectangle Class는 정보가 은닉되어있는 상태다.

private : // 판단 근거 1. 멤버 변수가 private
    Point upLeft;
    Point lowRight;

public : // 판단 근거 2. 해당 변수에 접근하는 함수가 별도로 정의
    /* bool InitMembers(const Point &ul, const Point &lr); 생성자 아닌 버전 */
    Rectangle(const int &x1, const int &y1, const int &x2, const int &y2); // 생성자 버전

    void ShowRecInfo() const;

};

#endif