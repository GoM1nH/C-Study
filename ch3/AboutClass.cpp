#include "class.h"

int main() {

    User A;
    A.InitMembers("GORAD", 5);
    A.ShowGamerState();
    A.PointUP();
    A.ShowGamerState();

    User B;
    B.InitMembers("B-IM-ZZ", 3);
    B.ShowGamerState();
    B.PointUP();
    B.PointUP();
    B.ShowGamerState();

    return 0;
}