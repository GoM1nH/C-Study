#include <iostream>

int main() {

    int sum=0;
    int num;

    for (int i=0 ; i<5 ; i++) {
        std::cout<<i+1<<" num input : ";
        std::cin>>num;
        sum+=num;
    }

    std::cout<<sum<<std::endl;
    
}