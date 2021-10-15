// Stack using LinkedList implementation in C++

#include <iostream>
using namespace std;

struct Node {
  int data;
  struct Node *next;
} *top = NULL;

void push(int value) {
  struct Node *new_node;
  new_node = (struct Node *)malloc(sizeof(struct Node));
  new_node->data = value;
  if (top == NULL) {
    new_node->next = NULL;
  } else {
    new_node->next = top;
  }
  top = new_node;
  cout << "Insertion Successful !" << endl;
}

int pop() {
  if (top == NULL)
    cout << "Stack is Empty!" << endl;
  else {
    struct Node *temp = top;
    cout << "Deleted element: " << temp->data << endl;
    int pop = temp->data;
    top = temp->next;
    delete temp;
    return pop;
  }
}

void display() {
  if (top == NULL)
    cout << "\nStack is Empty!" << endl;
  else {
    struct Node *temp = top;
    while (temp->next != NULL) {
      cout << temp->data << "--->";
      temp = temp->next;
    }
    cout << temp->data << "--->NULL" << endl;
  }
}

int main() {
  int choice, value;
  cout << "\n Stack using Linked List" << endl;
  display();
  push(1);
  push(2);
  push(3);
  display();
  cout << pop()<<endl;

  display();
  return 0;
}
