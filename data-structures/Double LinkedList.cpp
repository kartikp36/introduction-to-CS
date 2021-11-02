// Double Linked list implementation in C++

#include <iostream>
using namespace std;

class Node {
 public:
  int data, length = 0;
  class Node *previous, *next, *head = NULL;

  bool isEmpty() {
    return (length == 0);
  }
  void insertAtBeginning(int value) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = value;
    new_node->previous = NULL;

    if (isEmpty()) {
      new_node->next = NULL;
      head = new_node;
    } else {
      new_node->next = head;
      head = new_node;
    }
    length++;
    cout << " Node inserted at the beginning!" << endl;
  }

  void insertAfter(int value, int location) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = value;
    if (isEmpty()) {
      new_node->next = NULL;
      new_node->previous = NULL;
      head = new_node;
    } else {
      Node *temp2, *temp1 = head;
      while (temp1->data != location) {
        if (temp1->next == NULL) {
          cout << " Given node not found in the LinkedLst. Insertion failed !" << endl;
          return;
        };
        temp1 = temp1->next;
      }
      temp2 = temp1->next;
      temp1->next = new_node;
      new_node->previous = temp1;
      new_node->next = temp2;
      temp2->previous = new_node;
    }
    length++;
    cout << " Node inserted!" << endl;
  }

  void insertAtEnd(int value) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;
    if (isEmpty()) {
      new_node->previous = NULL;
      head = new_node;
    } else {
      Node *temp = head;
      while (temp->next != NULL) {
        temp = temp->next;
      };
      temp->next = new_node;
      new_node->previous = temp;
    }
    length++;
    cout << " Node inserted at the end!" << endl;
  }

  void deleteAtBeginning() {
    if (isEmpty()) {
      cout << "List is empty. Deletion failed!" << endl;
    } else {
      Node *temp = (Node *)malloc(sizeof(Node));
      temp = head;
      if (temp->next == temp->previous) {
        head = NULL;
      } else {
        head = temp->next;
        head->previous = NULL;
      }
      delete temp;
    }
    length--;
    cout << " Node at the beginning deleted!" << endl;
  }

  void deleteAtEnd() {
    if (isEmpty()) {
      cout << "List is empty. Deletion failed!" << endl;
    } else {
      Node *temp = (Node *)malloc(sizeof(Node));
      temp = head;
      if (temp->next == temp->previous) {
        head = NULL;
      } else {
        while (temp->next != NULL) {
          temp = temp->next;
        };
        temp->previous->next = NULL;
      }
      delete temp;
    }
    length--;
    cout << " Node at the end deleted!" << endl;
  }

  void deleteNode(int value) {
    if (isEmpty()) {
      cout << "List is empty. Deletion failed!" << endl;
    } else {
      Node *temp = (Node *)malloc(sizeof(Node));
      temp = head;

      while (temp->data != value) {
        if (temp->next == NULL) {
          cout << "Given node not found. Deletion failed!" << endl;
          return;
        }
        temp = temp->next;
      };

      if (temp == head) {
        head = head->next;
        head->previous = NULL;
      } else if (temp->next == NULL) {
        temp->previous->next = NULL;
      } else {
        temp->previous->next = temp->next;
        temp->next->previous = temp->previous;
      }
      delete temp;
    }
    length--;
    cout << " Node: " << value << " deleted!" << endl;
  }

  void display() {
    if (isEmpty()) {
      cout << " List is Empty" << endl;
    } else {
      Node *temp = head;

      cout << "\n Double Linked List elements are: " << endl;
      while (temp != NULL) {
        cout << temp->data << " <===> ";
        temp = temp->next;
      }
      cout << "NULL" << endl;
    }
  }
};

int main() {
  Node head1;
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
