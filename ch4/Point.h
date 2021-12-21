#ifndef __POINT_H__
#define __POINT_H__

class Point {

private :
    int x;
    int y;

public :
    bool InitMembers(int xpos, int ypos);
    int GetX() const; // 이는 const 함수라고 함. "이 함수 내에선 멤버변수에 저장된 값을 변경하지 않겠다"는 의미를 가진다.
    int GetY() const;
    bool SetX(int xpos);
    bool SetY(int ypos);
};

#endif