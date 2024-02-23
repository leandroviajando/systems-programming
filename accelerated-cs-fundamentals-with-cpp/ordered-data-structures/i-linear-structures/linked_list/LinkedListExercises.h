
/**
 * @file LinkedListExercises.h
 * University of Illinois CS 400, MOOC 2, Week 1: Linked List
 * Spring 2019
 *                        STUDENT STARTER FILE
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

#include "LinkedList.h"

template <typename T>
void LinkedList<T>::insertOrdered(const T &newData) {
  Node *newNode = new Node(newData);

  if (!head_)
    head_ = tail_ = newNode;
  else if (newData <= head_->data) {
    Node *oldHead = head_;
    oldHead->prev = newNode;
    newNode->next = oldHead;
    head_ = newNode;
  } else if (newData >= tail_->data) {
    Node *oldTail = tail_;
    oldTail->next = newNode;
    newNode->prev = oldTail;
    tail_ = newNode;
  } else {
    Node *cur = head_->next;

    while (cur && newData > cur->data) cur = cur->next;

    Node *oldNode = cur;
    newNode->next = oldNode;
    newNode->prev = oldNode->prev;

    oldNode->prev->next = newNode;
    oldNode->prev = newNode;
    cur = newNode;
  }

  size_++;
}

template <typename T>
LinkedList<T> LinkedList<T>::merge(const LinkedList<T> &other) const {
  // You can't edit the original instance of LinkedList that is calling
  // merge because the function is marked const, and the "other" input
  // list is also marked const.
  LinkedList<T> left = *this;
  LinkedList<T> right = other;
  LinkedList<T> merged;

  while (!left.empty() && !right.empty()) {
    if (left.front() <= right.front()) {
      merged.pushBack(left.front());
      left.popFront();
    } else {
      merged.pushBack(right.front());
      right.popFront();
    }
  }

  LinkedList<T> nonEmpty = (!left.empty()) ? left : right;

  while (!nonEmpty.empty()) {
    merged.pushBack(nonEmpty.front());
    nonEmpty.popFront();
  }

  // We return the merged list by value here. It may be copied out of the
  // function, but usually the compiler will optimize this to automatically
  // create it directly in the correct memory space outside without copying.
  // Don't worry about the speed of that right now. (By the way, did you
  // notice that all of our nodes are created on the heap? The part of the
  // list that we pass back is really small; it just contains two pointers
  // and an int.)
  return merged;
}
