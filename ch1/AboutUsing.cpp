#include <iostream>

using std::cin; // cin을 이름공간 std에서 찾으라는 일종의 선언이 되는 것이다. define이나 typedef처럼 편하게 코드를 짜는데 도움이 된다.
using std::cout;
using std::endl;

int main() {
    int num = 20;

    cout << "Hello, World" << endl;
    cout << num << endl;
    cout << num << ' '<<'A';

    return 0;
}