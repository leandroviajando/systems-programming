namespace iii_classes_in_cpp {

#include <iostream>

class Pair {
   public:
    int *pa, *pb;
    Pair(int, int);
    Pair(const Pair &);
    ~Pair();
};

Pair::Pair(int a, int b) {
    pa = new int(a);
    pb = new int(b);
}
Pair::Pair(const Pair &p) {
    pa = new int(*p.pa);
    pb = new int(*p.pb);
}
Pair::~Pair() {
    delete pa, pb;
    pa = nullptr;
    pb = nullptr;
}

int main() {
    Pair p(15, 16);
    Pair q(p);
    Pair *hp = new Pair(23, 42);
    delete hp;

    std::cout << "If this message is printed,"
              << " at least the program hasn't crashed yet!\n"
              << "But you may want to print other diagnostic messages too." << std::endl;
    return 0;
}

}  // namespace iii_classes_in_cpp
