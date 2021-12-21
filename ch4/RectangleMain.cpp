#include <iostream>
#include "Point.h"
#include "Rectangle.h"

using namespace std;

int main() {
    Point pos1;
    if(!pos1.InitMembers(-2, 4)) {
        cout<<"Init Fail"<<endl;
    }
    if(!pos1.InitMembers(2, 4)) {
        cout<<"Init Fail"<<endl;
    }

    Point pos2;
    if(!pos2.InitMembers(5, 9)) {
        cout<<"Init Fail"<<endl;
    }

    Rectangle rec;
    if(!rec.InitMembers(pos1, pos2)) {
        cout<<"Rectangle Init Fail"<<endl;
    }

    rec.ShowRecInfo();
    return 0;
}