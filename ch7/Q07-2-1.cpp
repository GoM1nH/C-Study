#include <iostream>
#include <cstring>
using namespace std;

class Rectangle {
private :
    int width;
    int height;
public :
    Rectangle(int a, int b) : width(a), height(b) { }
    void ShowAreaInfo() {
        cout<<"Area : "<< width * height << endl;
    }
};

class Square : public Rectangle {
public :
    Square(int k) : Rectangle(k, k) { }
};

int main