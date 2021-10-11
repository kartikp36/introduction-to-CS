// Queue implementation in C++

#include <iostream>
using namespace std;

const int SIZE = 10;

class Queue
{
public:
  int front = -1;
  int rear = -1;
  int queue[SIZE];

  bool isFull()
  {
    bool full = false;
    if (rear == SIZE - 1)
    {
      full = true;
    }
    return full;
  };

  bool isEmpty()
  {
    bool empty = false;
    if (rear == front)
    {
      empty = true;
    }
    return empty;
  };

  void enQueue(int value)
  {
    if (isFull())
    {
      cout << "Queue is full. Insertion failed!" << endl;
    }
    else
    {
      rear++;
      queue[rear] = value;
    }
  };

  void deQueue()
  {
    if (isEmpty())
    {
      cout << "Queue is Empty. Deletion failed!" << endl;
    }
    else
    {
      front++;
      cout << "Deleted: " << queue[front] << endl;
      if (isEmpty())
      {
        front = rear = -1;
      };
    };
  };

  void peek()
  {
    if (isEmpty())
    {
      cout << "Queue is Empty. Nothing to peek!" << endl;
    }
    else
    {
      cout << "Peek: " << queue[front + 1] << endl;
    };
  };

  void display()
  {
    if (isEmpty())
    {
      cout << "Queue is Empty" << endl;
    }
    else
    {
      cout << "Queue elements are: " << endl;
      for (int i = front + 1; i <= rear; i++)
      {
        cout << queue[i] << endl;
      }
    };
  };
};

int main()
{
  Queue q;
  q.display();
  q.enQueue(1);
  q.display();
  q.enQueue(2);
  q.enQueue(3);
  q.display();
  q.deQueue();
  q.peek();
  q.display();
  return 0;
}
