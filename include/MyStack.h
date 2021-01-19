//  Copyright © 2020 Сапожников Андрей Михайлович. All rights reserved.

#ifndef INCLUDE_MYSTACK_H_
#define INCLUDE_MYSTACK_H_

template <class T>
class MyStack {
 private:
  int max_size;
  int size;
  T* stack;
  
 public:
  MyStack() {
    this->max_size = 0;
    this->size = 0;
    this->stack = nullptr;
  }
  explicit MyStack(unsigned target_size) {
    this->max_size = target_size;
    this->stack = new T[this->max_size];
    this->size = 0;
  }
  MyStack(const MyStack& other_MyStack) {
    this->max_size = other_MyStack.max_size;
    this->stack = new T[this->max_size];
    this->size = other_MyStack.size;

    for (unsigned i = 0; i < this->size; i++)
        this->stack[i] = other_MyStack.stack[i];
  }
  ~MyStack() {
      delete[] this->stack;
  }
  T get() const {
    if (this->isEmpty())
      return 0;
    return this->stack[this->size-1];
  }
  T pop() {
    if (this->isEmpty())
      return 0;
    return this->stack[--size];
  }
  void push(T value) {
    if (this->isFull())
      return;
    this->stack[this->size++] = value;
  }
  bool isFull() const {
    return this->size == this->max_size;
  }
  bool isEmpty() const {
    return this->size == 0;
  }
};

#endif  // INCLUDE_MYSTACK_H_
