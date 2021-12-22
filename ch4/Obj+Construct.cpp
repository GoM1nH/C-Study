#include <iostream>

using namespace std;

class FruitSeller { // 과일을 파는 과일장수의 객체 선언

private : // 멤버 변수이자 객체의 상태정보

    const int APPLE_PRICE;
    int NumOfApples;
    int MyMoney;

public : // 멤버 함수이자 객체의 행동(기능)
    
    FruitSeller(int price, int num, int money) :APPLE_PRICE(price){ // Init 함수를 쓰지 않고 객체 선언과 동시에 초기화. 생성자 활용.
    // Member Initializer는 선언과 동시에 초기화가 이뤄지는 형태로, const 멤버변수도 이니셜라이저 이용 가능
        NumOfApples = num;
        MyMoney = money;
    }
    
    int SaleApple(int money) {
        int num = money / APPLE_PRICE;
        NumOfApples -= num;
        MyMoney += money;
        return num;
    }

    void ShowResult() {
        cout<<"How many apples left : "<<NumOfApples<<endl;
        cout<<"Profit : "<<MyMoney<<endl;
    }

};

class FruitBuyer { // 과일을 구매하는 구매자의 객체 선언

    int MyMoney;
    int NumOfApples;

public :
    FruitBuyer(int money) { // Init 함수를 쓰지 않고 객체 선언과 동시에 초기화. 생성자 활용.
        MyMoney = money;
        NumOfApples = 0;
    }

    void BuyApple(FruitSeller &seller, int money) {
        NumOfApples += seller.SaleApple(money);
        MyMoney -= money;
    }

    void ShowResult() {
        cout<<"Balance : "<<MyMoney<<endl;
        cout<<"Apples : "<<NumOfApples<<endl;
    }
};

int main() {

    FruitSeller bjj(1000, 20, 0);
    FruitBuyer bdg(12000);
    
    bdg.BuyApple(bjj, 6000);

    cout<<"Seller state : "<<endl;
    cout<<bjj.ShowResult()<<endl;
    cout<<"Buyer state : "<<endl;
    cout<<bdg.ShowResult()<<endl;

    return 0;
}