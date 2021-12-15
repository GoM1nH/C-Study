#include <iostream>
#include <cstring>
#include "class.h"

using namespace std;

// 함수를 얘들처럼 밖으로 빼서 정의를 해도, 이는 클래스의 일부라서 함수 내에서 private으로 선언된 변수에 접근 가능

void User::InitMembers(char *ID, int IDrank) {
    strcpy(gamerID, ID);
    rank = IDrank;
    point = 0;
}

void User::ShowGamerState() {
    cout<<"Gamer ID :"<<gamerID<<endl;
    cout<<"His / Her rank is : "<<rank<<endl;
    cout<<"His / Her Point is : "<<point<<endl;
    cout<<"\n";
}

void User::PointUP() {
    point += 10;    
}