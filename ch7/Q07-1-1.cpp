#include <iostream>
#include <cstring>
using namespace std;

class Car {
private :
    int gasoline;
public :
    Car(int n) : gasoline(n) {    } 

    int GetGasGauge() {
        return gasoline;
    }
};

class Hybrid : public Car {
private:
    int electric;
public :
    Hybrid(int n1, int n2) : Car(n1), electric(n2) {   }

    int GetElecGauge() {
        return electric;
    }
};

class HybridWater : public Hybrid {
private :
    int water;
public :
    HybridWater(int n1, int n2, int n3) : Hybrid(n1, n2), water(n3) {   }

    int ShowCurrentGauge() {
        cout<<"Gasoline : "<<GetGasGauge()<<endl;
        cout<<"Electric : "<<GetElecGauge()<<endl;
        cout<<"Water : "<<water<<endl;
    }
}

int main() {
    HybridWater car1(33, 74, 38);
    car1.ShowCurrentGauge();
    return 0;
}