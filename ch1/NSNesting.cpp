#include <iostream>

namespace ACom {
    int rank = 1;

    namespace GMH {
        int rank = 2;
    }

    namespace BDG {
        int rank = 100;
    }
}

int main() { // namespace 중첩 사용 방법
    std::cout<<ACom::rank << std::endl;
    std::cout<<ACom::GMH::rank << std::endl;
    std::cout<<ACom::BDG::rank << std::endl;
    return 0;
}