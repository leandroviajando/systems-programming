namespace iv_oop_in_cpp {

#include <iostream>

class Pair {
   public:
    Pair(int a, int b) {}
};

class SumPair : public Pair {
   public:
    int sum;
    SumPair(int, int);
};

SumPair::SumPair(int a, int b) : Pair(a, b) {
    sum = a + b;
}

int main() {
    SumPair sp(15, 16);
    std::cout << "sp(15,16).sum =" << sp.sum << std::endl;
    return 0;
}

}  // namespace iv_oop_in_cpp
