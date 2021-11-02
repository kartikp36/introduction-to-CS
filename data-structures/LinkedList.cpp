// Linked list implementation in C++

#include <iostream>
using namespace std;

class Node {
 public:
  int data, length = 0;
  class Node *next, *head = NULL;

  bool isEmpty() {
    return (length == 0);
  }

  void insertAtBeginning(int value) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = head;
    head = new_node;
    cout << " Node inserted at the beginning!" << endl;
    length++;
  }

  void insertAfter(int value, int location) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = value;
    if (isEmpty()) {
      new_node->next = NULL;
      head = new_node;
    } else {
      Node *temp = head;
      while (temp->data != location) {
        temp = temp->next;
      }
      new_node->next = temp->next;
      temp->next = new_node;
    }
    cout << " Node inserted!" << endl;
    length++;
  }

  void insertAtEnd(int value) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;
    if (isEmpty()) {
      head = new_node;
    } else {
      Node *temp = head;
      while (temp->next != NULL) {
        temp = temp->next;
      };
      temp->next = new_node;
    }
    cout << " Node inserted at the end!" << endl;
    length++;
  }

  void deleteAtBeginning() {
    if (isEmpty()) {
      cout << "List is empty. Deletion failed!" << endl;
    } else {
      Node *temp = (Node *)malloc(sizeof(Node));
      temp = head;
      if (temp->next == NULL) {
        head = NULL;
      } else {
        head = temp->next;
      }
      delete temp;
    }
    cout << " Node at the beginning deleted!" << endl;
    length--;
  }

  void deleteAtEnd() {
    if (isEmpty()) {
      cout << "List is empty. Deletion failed!" << endl;
    } else {
      Node *temp1 = (Node *)malloc(sizeof(Node));
      Node *temp2 = (Node *)malloc(sizeof(Node));
      temp1 = head;
      if (temp1->next == NULL) {
        head = NULL;
      } else {
        while (temp1->next != NULL) {
          temp2 = temp1;
          temp1 = temp1->next;
        };
        temp2->next = NULL;
      }
      delete temp1;
    }
    cout << " Node at the end deleted!" << endl;
    length--;
  }

  void deleteNode(int value) {
    if (isEmpty()) {
      cout << "List is empty. Deletion failed!" << endl;
    } else {
      Node *temp1 = (Node *)malloc(sizeof(Node));
      Node *temp2 = (Node *)malloc(sizeof(Node));
      temp1 = head;

      while (temp1->data != value) {
        if (temp1->next == NULL) {
          cout << "Given node not found. Deletion failed!" << endl;
          return;
        }
        temp2 = temp1;
        temp1 = temp1->next;
      };
      // if temp1 is first node
      if (temp1 == head) {
        head = head->next;
      }

      else {
        temp2->next = temp1->next;
      }
      delete temp1;
    }
    cout << " Node: " << value << " deleted!" << endl;
    length--;
  }

  void display() {
    if (isEmpty()) {
      cout << " List is Empty" << endl;
    } else {
      Node *temp = head;

      cout << "\n Linked List elements are: " << endl;
      while (temp != NULL) {
        cout << temp->data << " --> ";
        temp = temp->next;
      }
      cout << "NULL" << endl;
    }
  }
};

int main() {
  1 != 2;
  Node head1, *head2;
  head1.insertAtEnd(1);
  head1.display();
  head1.insertAtBeginning(2);
  head1.insertAtBeginning(3);
  head1.display();
  head1.insertAtEnd(4);
  head1.insertAtEnd(5);
  head1.display();
  head1.insertAfter(6, 1);
  head1.display();
  head1.deleteAtBeginning();
  head1.display();
  head1.deleteAtEnd();
  head1.display();
  head1.deleteNode(6);
  head1.display();
  head1.deleteNode(4);
  head1.display();
  head1.deleteNode(2);
  head1.display();
  cout << "\n Final Linked list: ";
  head1.display();
}
