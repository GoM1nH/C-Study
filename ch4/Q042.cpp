#include <iostream>
#include <cmath>

using namespace std;

class Point {

private :
    int xpos, ypos;

public :
    Point(int x, int y) : xpos(x), ypos(y) {
    }
    
    /* void Init(int x, int y) {
        xpos = x;
        ypos = y;
    } */

    void ShowPointInfo() const {
        cout<<"["<<xpos<<", "<<ypos<<"]"<<endl;
    }
};

class Circle {

private :
    int rad;
    Point center;

public :
    Circle(int x, int y, int r) : rad(r), center(x, y){
    }
    /* void Init(int x, int y, int r) {
        rad = r;
        center.Init(x, y);
    } */

    void ShowCircleInfo() const {
        cout<<"Radius : "<<rad<<endl;
        center.ShowPointInfo();
    }
};

class Ring {

private :
    Circle Inner;
    Circle Outter;

public :
    Ring(int x1, int y1, int r1, int x2, int y2, int r2) : Inner(x1, y1, r1), Outter(x2, y2, r2) {
    }
    /* void Init(int x1, int y1, int r1, int x2, int y2, int r2) {
        
        Inner.Init(x1, y1, r1);
        Outter.Init(x2, y2, r2);
    } */

    void ShowRingInfo() const {
        cout<<"Inner Circle Info..."<<endl;
        Inner.ShowCircleInfo();
        cout<<"Outter Circle Info..."<<endl;
        Outter.ShowCircleInfo();
    }

};

int main() {
    Ring ring;
    ring.Init(1, 1, 4, 2, 2, 9);
    ring.ShowRingInfo();
    return 0;
}