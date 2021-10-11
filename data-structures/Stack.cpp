// Stack implementation in C++

#include <iostream>
using namespace std;

const int SIZE = 10;

class Stack
{
public:
  int top = -1;
  int stack[SIZE];

  bool isValid()
  {
    bool flag = false;
    if (top == SIZE - 1)
    {
      flag = true;
    }
    return flag;
  };

  void push(int value)
  {
    if (isValid())
    {
      cout << "Stack is full. Insertion failed!" << endl;
    }
    else
    {
      top++;
      stack[top] = value;
    }
  };

  int pop()
  {
    if (isValid())
    {
      cout << "Stack is Empty. Pop failed!" << endl;
    }
    else
    {
      int pop = stack[top];
      top--;
      return pop;
    };
  };

  void peek()
  {
    if (isValid())
    {
      cout << "Stack is Empty. Nothing to peek!" << endl;
    }
    else
    {
      cout << "Peek: " << stack[top] << endl;
    };
  };

  void display()
  {
    if (isValid())
    {
      cout << "Stack is Empty" << endl;
    }
    else
    {
      cout << "Stack elements are: " << endl;
      for (int i = top; i >= 0; i--)
      {
        cout << stack[i] << endl;
      }
    };
  };
};

int main()
{
  Stack my_stack;
  my_stack.display();
  my_stack.push(1);
  my_stack.display();
  my_stack.push(2);
  my_stack.push(3);
  my_stack.display();
  cout<<"Pop:" << my_stack.pop()<<endl;
  my_stack.peek();
  my_stack.display();
  return 0;
}
