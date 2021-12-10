#include <iostream>
#include <string.h>

using namespace std;

char *MakeStrArr(int len) {
    char *str = new char[len];
    return str;
}

int main() {
    char *str = MakeStrArr(20);
    strcpy(str, "This Is NEW");
    cout<<str<<endl;

    delete []str;
    return 0;
}