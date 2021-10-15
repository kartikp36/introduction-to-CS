// Queue using LinkedList implementation in C++

#include <iostream>
using namespace std;

struct Node {
  int data;
  struct Node *next;
} *front = NULL, *rear = NULL;

void enQueue(int value) {
  struct Node *new_node;
  new_node = (struct Node *)malloc(sizeof(struct Node));
  new_node->data = value;
  new_node->next = NULL;

  if (front == NULL)
    front = rear = new_node;
  else {
    rear->next = new_node;
    rear = new_node;
  }
  cout << " Insertion Successful!" << endl;
}

void deQueue() {
  if (front == NULL)
    cout << " Queue is Empty!" << endl;
  else {
    struct Node *temp = front;
    front = front->next;
    cout << " Deleted element: " << temp->data << endl;
    delete temp;
  }
}

void display() {
  if (front == NULL)
    cout << " Queue is Empty!" << endl;
  else {
    struct Node *temp = front;
    while (temp->next != NULL) {
      cout << temp->data << " ---> ";
      temp = temp->next;
    }
    cout << temp->data << " ---> NULL" << endl;
  }
}

int main() {
  cout << "\n Queue Implementation using Linked List" << endl;
  enQueue(1);
  enQueue(2);
  enQueue(3);
  display();
  deQueue();
  display();

  return 0;
}
