namespace ii_trees {

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

class Node {
   public:
    int height;
    Node *left, *right;
    Node() {
        height = -1;
        left = right = nullptr;
    }
    ~Node() {
        delete left;
        left = nullptr;
        delete right;
        right = nullptr;
    }
};

int count(Node *n) {
    if (n == nullptr)
        return 0;

    return 1 + count(n->left) + count(n->right);
}

void computeHeight(Node *n) {
    if (n != nullptr) {
        computeHeight(n->left);
        computeHeight(n->right);

        if (n->left != nullptr && n->right != nullptr)
            n->height = 1 + (n->left->height > n->right->height ? n->left->height : n->right->height);
        else if (n->left != nullptr)
            n->height = 1 + n->left->height;
        else if (n->right != nullptr)
            n->height = 1 + n->right->height;
        else
            n->height = 0;
    }
}

// This function prints the tree in a nested linear format.
void printTree(const Node *n) {
    if (!n) return;
    std::cout << n->height << "(";
    printTree(n->left);
    std::cout << ")(";
    printTree(n->right);
    std::cout << ")";
}

/* The printTreeVertical function gives you a verbose,
vertical printout of the tree, where the leftmost nodes
are displayed highest. This function has already been
defined in some hidden code. */
void printTreeVertical(const Node *n) {}

int main() {
    Node *n = new Node();
    n->left = new Node();
    n->right = new Node();
    n->right->left = new Node();
    n->right->right = new Node();
    n->right->right->right = new Node();

    // This should print a count of six nodes
    std::cout << count(n) << std::endl;

    computeHeight(n);

    printTree(n);
    std::cout << std::endl
              << std::endl;
    printTreeVertical(n);

    delete n;
    n = nullptr;

    return 0;
}

}  // namespace ii_trees
