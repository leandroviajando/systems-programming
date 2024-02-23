namespace iii_heaps {

#include <iostream>
#include <string>

class Node {
   public:
    int value;
    Node *left, *right;
    Node(int val = 0) {
        value = val;
        left = right = nullptr;
    }
    ~Node() {
        delete left;
        left = nullptr;
        delete right;
        right = nullptr;
    }
};

/* The printTreeVertical function gives you a verbose,
vertical printout of the tree, where the leftmost nodes
are displayed highest. This function has already been
defined in some hidden code. */
void printTreeVertical(const Node *n) {}

void downHeap(Node *n) {
    if (n) {
        if (n->left) {
            if (n->value > n->left->value) {
                int tmp = n->left->value;
                n->left->value = n->value;
                n->value = tmp;
            }
            downHeap(n->left);
        }

        if (n->right) {
            if (n->value > n->right->value) {
                int temp = n->right->value;
                n->right->value = n->value;
                n->value = temp;
            }
            downHeap(n->right);
        }
    }
}

void printTree(Node *n) {
    if (!n) return;
    std::cout << n->value << "(";
    printTree(n->left);
    std::cout << ")(";
    printTree(n->right);
    std::cout << ")";
}

int main() {
    Node *n = new Node(100);
    n->left = new Node(1);
    n->right = new Node(2);
    n->right->left = new Node(3);
    n->right->right = new Node(4);
    n->right->right->right = new Node(5);

    downHeap(n);

    std::cout << "Compact printout:" << std::endl;
    printTree(n);
    std::cout << std::endl
              << "Vertical printout:" << std::endl;
    printTreeVertical(n);

    delete n;
    n = nullptr;

    return 0;
}

}  // namespace iii_heaps
