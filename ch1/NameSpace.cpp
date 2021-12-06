#include <iostream>

namespace ACom {
    void SimpleFunc(void);
} // A회사의 SimpleFunc

namespace ACom {
    void RealFunc(void);
} // A회사의 RealFunc

namespace BCom {
    void SimpleFunc(void);
} // B회사의 SimpleFunc

int main() {
    ACom::SimpleFunc();
    return 0;
}

void ACom::SimpleFunc(void) { // A회사의 namespace에 있는 SimpleFunc
    std::cout<<"ACom의 함수"<<std::endl;
    SimpleFunc();
    RealFunc(); // 같은 회사(namespace)의 영역에 있으므로, 바로 사용 가능
    BCom::SimpleFunc(); // 다른 회사(namespace)의 영역에 있으므로, 범위지정 연산자로 B회사의 namespace에서 불러옴
}

void ACom::RealFunc(void) { // A회사의 namespace에 있는 RealFunc
    std::cout<<"This is REAL"<<std::endl;
}

void BCom::SimpleFunc(void) { // B회사의 namespace에 있는 SimpleFunc
    std::cout<<"B회사의 SimpleFunc 함수"<<std::endl;
}