// Stack implementation in C++

#include <iostream>
using namespace std;

const int SIZE = 10;

class Stack {
 public:
  int top = -1;
  int stack[SIZE];

  bool isFull() {
    return (top == SIZE - 1);
  };
  
  bool isEmpty() {
    return (top == -1);
  };
  void push(int value) {
    if (isFull()) {
      cout << "Stack is full. Insertion failed!" << endl;
    } else {
      top++;
      stack[top] = value;
    }
  };

  void pop() {
    if (isEmpty()) {
      cout << "Stack is Empty. Pop failed!" << endl;
    } else {
      int pop = stack[top];
      top--;
      cout << " Pop: " << pop << endl;
    };
  };

  void peek() {
    if (isEmpty()) {
      cout << "Stack is Empty. Nothing to peek!" << endl;
    } else {
      cout << "Peek: " << stack[top] << endl;
    };
  };

  void display() {
    if (isEmpty()) {
      cout << "Stack is Empty" << endl;
    } else {
      cout << "Stack elements are: " << endl;
      for (int i = top; i >= 0; i--) {
        cout << stack[i] << endl;
      }
    };
  };
};

int main() {
  Stack my_stack;
  my_stack.display();
  my_stack.push(1);
  my_stack.display();
  my_stack.push(2);
  my_stack.push(3);
  my_stack.display();
  my_stack.pop();
  my_stack.peek();
  my_stack.display();
  return 0;
}
