/**
 * @file GenericTreeExercises.h
 * University of Illinois CS 400, MOOC 2, Week 3: Generic Tree
 * Spring 2019
 *                       STUDENT STARTER FILE
 *
 * @author Eric Huber - University of Illinois staff
 *
 **/

#pragma once

// It's good to put system headers first, so that if your own libraries
// cause conflicts, the compiler will most likely identify the problem
// as being in your own source code files, where it arises later.
#include <iostream>
#include <string>

#include "GenericTree.h"

// The root is 4, which has two children: a left child, 8,
// and a right child, 15. 8 has a left child that is 16, and a right
// child that is 23. 16 has a single child that is 42.
static void treeFactory(GenericTree<int>& tree) {
  tree.clear();

  tree.createRoot(4);
  GenericTree<int>::TreeNode* left = tree.getRootPtr()->addChild(8);
  GenericTree<int>::TreeNode* right = tree.getRootPtr()->addChild(15);

  left->addChild(16)->addChild(42);
  left->addChild(23);
}

// treeFactoryTest: This function demonstrates the execution of treeFactory
// and displays a preview of the results in the main function.
static void treeFactoryTest() {
  std::cout << std::endl;
  std::cout << "------------------------------" << std::endl;
  std::cout << "EXERCISE 1: treeFactoryTest" << std::endl;
  std::cout << "The output should match what you see in the code comments" << std::endl
            << std::endl;

  GenericTree<int> tree(9999);
  treeFactory(tree);
  std::cout << tree << std::endl;
}

// countNullChildrenRecursive: Given a pointer to a TreeNode, look at the
// subtree that is implicitly rooted at that node, and count how many children
// throughout the tree are null pointers. Here, templated type N should be a
// TreeNode inner type belonging to some type of GenericTree.
template <typename N>
int countNullChildrenRecursive(N* subtreeRoot) {
  // Base case: If the root of this subtree itself is null, then return 1.
  if (!subtreeRoot) return 1;

  int nullChildrenSum = 0;

  // Note 1: We'll allow our definition of recursion to include a combination
  //  of looping and recursing.
  // Node 2: Since we dereference subtreeRoot below with "->", we had to make
  //  sure that it was not null first. We already handled that base case above.
  // Note 3: Instead of "auto", it also works to write "auto*" or "N*" here
  //  based on how we've set up the template. But you can't use "auto" in the
  //  function arguments list, only inside the function.

  for (auto childPtr : subtreeRoot->childrenPtrs)
    nullChildrenSum += countNullChildrenRecursive(childPtr);

  return nullChildrenSum;
}

// countNullChildrenIterative: Given a pointer to a TreeNode, look at the
// subtree that is implicitly rooted at that node, and count how many children
// throughout the tree are null pointers. Here, templated type N should be a
// TreeNode inner type belonging to some type of GenericTree.
template <typename N>
int countNullChildrenIterative(N* subtreeRoot) {
  int nullChildrenSum = 0;

  // Stack of node pointers that we still need to explore (constructed empty)
  std::stack<N*> nodesToExplore;

  // Begin by pushing our subtree root pointer onto the stack
  nodesToExplore.push(subtreeRoot);

  // Loop while there are still nodes to explore
  while (!nodesToExplore.empty()) {
    // Make a copy of the top pointer on the stack, then pop it to decrease the stack
    N* topNode = nodesToExplore.top();
    nodesToExplore.pop();

    if (!topNode) {
      // If the top node pointer is null, then we must not dereference it.
      // Just increment the null counter, then "continue" to jump back to the top of the loop.
      nullChildrenSum++;
      continue;
    }

    // If the node exists, it may have children pointers. Let's iterate
    // through the childrenPtrs vector and push copies of those pointers
    // onto the exploration stack.
    for (auto childPtr : topNode->childrenPtrs)
      nodesToExplore.push(childPtr);
  }

  return nullChildrenSum;
}

// traverseLevels: Performs a level-order traversal of the input tree
// and records copies of the data found, in order, in a std::vector,
// which should then be returned.
template <typename T>
std::vector<T> traverseLevels(GenericTree<T>& tree) {
  using TreeNode = typename GenericTree<T>::TreeNode;
  std::vector<T> results;

  auto rootNodePtr = tree.getRootPtr();
  if (!rootNodePtr)
    return results;

  results.push_back(rootNodePtr->data);

  std::vector<TreeNode*> childrenPtrs = rootNodePtr->childrenPtrs;
  std::vector<TreeNode*> grandChildrenPtrs;

  while (childrenPtrs.size() > 0) {
    grandChildrenPtrs.clear();

    for (size_t i = 0; i < childrenPtrs.size(); i++) {
      TreeNode* childPtr = childrenPtrs[i];

      results.push_back(childPtr->data);

      for (size_t j = 0; j < childPtr->childrenPtrs.size(); j++) {
        TreeNode* grandChildPtr = childPtr->childrenPtrs[j];

        grandChildrenPtrs.push_back(grandChildPtr);
      }
    }

    childrenPtrs.clear();
    childrenPtrs = grandChildrenPtrs;
  }

  return results;
}

// traversalTest: Runs some tests with your traverseLevels function and
// displays comparison output.
static void traversalTest() {
  std::cout << std::endl;
  std::cout << "------------------------------" << std::endl;
  std::cout << "EXERCISE 2: traversalTest" << std::endl;
  std::cout << "Testing your traverseLevels function" << std::endl
            << std::endl;

  {
    // This is the tree from exampleTree1() in main.cpp
    std::cout << "[Test 1] Expected output:" << std::endl
              << "A B E C D F G" << std::endl;
    GenericTree<std::string> tree1("A");
    auto nodeA = tree1.getRootPtr();
    auto nodeB = nodeA->addChild("B");
    nodeB->addChild("C");
    nodeB->addChild("D");
    auto nodeE = nodeA->addChild("E");
    nodeE->addChild("F");
    nodeE->addChild("G");
    std::vector<std::string> tree1_results = traverseLevels(tree1);
    std::cout << "Your traverseLevels output:" << std::endl;
    for (auto result : tree1_results) {
      std::cout << result << " ";
    }
    std::cout << std::endl
              << std::endl;
  }

  {
    // This is the tree from exampleTree2() in main.cpp
    std::cout << "[Test 2] Expected output:" << std::endl
              << "A B D J K C E I L F G M H" << std::endl;
    GenericTree<std::string> tree2("A");
    auto A = tree2.getRootPtr();
    A->addChild("B")->addChild("C");
    auto D = A->addChild("D");
    auto E = D->addChild("E");
    E->addChild("F");
    E->addChild("G")->addChild("H");
    D->addChild("I");
    A->addChild("J");
    auto L = A->addChild("K")->addChild("L");
    L->addChild("M");
    std::vector<std::string> tree2_results = traverseLevels(tree2);
    std::cout << "Your traverseLevels output:" << std::endl;
    for (auto result : tree2_results) {
      std::cout << result << " ";
    }
    std::cout << std::endl
              << std::endl;
  }

  {
    // This is the tree you should have built for the first part of this
    // assignment above, with treeFactory.
    std::cout << "[Test 3] Expected output:" << std::endl
              << "4 8 15 16 23 42" << std::endl;
    GenericTree<int> tree3(9999);
    treeFactory(tree3);
    std::vector<int> tree3_results = traverseLevels(tree3);
    std::cout << "Your traverseLevels output:" << std::endl;
    for (auto result : tree3_results) {
      std::cout << result << " ";
    }
    std::cout << std::endl
              << std::endl;
  }
}
