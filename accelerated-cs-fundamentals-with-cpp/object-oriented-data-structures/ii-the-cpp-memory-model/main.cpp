namespace ii_the_cpp_memory_model {

#include <iostream>

class Pair {
   public:
    int first, second;
    void check() {
        first = 5;
        std::cout << "Congratulations! The check() method of the Pair class \n has executed. (But, this isn't enough to guarantee \n that your code is correct.)" << std::endl;
    }
};

Pair *pairFactory() {
    return new Pair;
}

int main() {
    Pair *p = pairFactory();

    // This function call should work without crashing:
    p->check();

    // Deallocating the heap memory. (Assuming it was made on the heap!)
    delete p;
    p = nullptr;

    std::cout << "If you can see this text, the system hasn't crashed yet!" << std::endl;

    return 0;
}

}  // namespace ii_the_cpp_memory_model
