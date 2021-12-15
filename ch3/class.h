#ifndef __CLASS_H__
#define __CLASS_H__

namespace ID_CONST {
    enum {
        ID_LEN = 10
    };
}

class User {

// 접근제어 지시자에 콜론(:) 이 붙는 이유는, 특정 위치정보를 알리는 레이블(라벨)이기 때문이다.
// 그래서 switch에서도 콜론 씀.

private : // class 내에서만 접근 가능
    char gamerID[ID_CONST::ID_LEN]; // 범위 지정 연산자 사용
    int rank;
    int point;
    // 이 gamerID, rank, point는 User를 구성하는 멤버 변수임

public : // 어디서든 접근 가능.
    void InitMembers(char *ID, int fuel);
    void ShowGamerState();
    void PointUP();
    // 이 InitMembers, Show.., PointUP은 User를 구성하는 멤버함수임
};

#endif