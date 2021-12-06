#include <iostream>

int CalSale(int x) {
    return (int) (50+(x*0.12));
}

int main() {

    int num, result;
    while (1) {
        std::cout<<"Won : ";
        std::cin>>num;
        if (num == -1) {
            break;
        }

        result = CalSale(num);
        std::cout<<"Your Salary is : "<<result<<"\n";
    }
    std::cout<<"QUIT"<<std::endl;

}