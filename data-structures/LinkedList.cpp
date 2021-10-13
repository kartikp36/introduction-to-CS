// Linked list implementation in C++

#include <iostream>
using namespace std;

struct Node {
  int data;
  struct Node *next;
} *head = NULL;

// Insertion

void insertAtBeginning(int value) {
  struct Node *new_node;
  new_node = (struct Node *)malloc(sizeof(struct Node));
  new_node->data = value;
  if (head == NULL) {
    new_node->next = NULL;
    head = new_node;
  } else {
    new_node->next = head;
    head = new_node;
  }
  cout << " Node inserted at the beginning!" << endl;
}

void insertAfter(int value, int location) {
  struct Node *new_node;
  new_node = (struct Node *)malloc(sizeof(struct Node));
  new_node->data = value;
  if (head == NULL) {
    new_node->next = NULL;
    head = new_node;
  } else {
    struct Node *temp = head;
    while (temp->data != location) {
      temp = temp->next;
      // if (temp->next == NULL)
      // {
      //   cout << " Given node not found in the LinkedLst. Insertion
      //   failed!" << endl; break;
      // };
    }
    new_node->next = temp->next;
    temp->next = new_node;
  }
  cout << " Node inserted!" << endl;
}

void insertAtEnd(int value) {
  struct Node *new_node;
  new_node = (struct Node *)malloc(sizeof(struct Node));
  new_node->data = value;
  new_node->next = NULL;
  if (head == NULL) {
    head = new_node;
  } else {
    struct Node *temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    };
    temp->next = new_node;
  }
  cout << " Node inserted at the end!" << endl;
}

// Deletion

void deleteAtBeginning() {
  if (head == NULL) {
    cout << "List is empty. Deletion failed!" << endl;
  } else {
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp = head;
    if (temp->next == NULL) {
      head = NULL;
    } else {
      head = temp->next;
    }
    delete temp;
  }
  cout << " Node at the beginning deleted!" << endl;
}

void deleteAtEnd() {
  if (head == NULL) {
    cout << "List is empty. Deletion failed!" << endl;
  } else {
    struct Node *temp1, *temp2;
    temp1 = (struct Node *)malloc(sizeof(struct Node));
    temp2 = (struct Node *)malloc(sizeof(struct Node));
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
}

void deleteNode(int value) {
  if (head == NULL) {
    cout << "List is empty. Deletion failed!" << endl;
  } else {
    struct Node *temp1, *temp2;
    temp1 = (struct Node *)malloc(sizeof(struct Node));
    temp2 = (struct Node *)malloc(sizeof(struct Node));
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
}
// Display

void display() {
  if (head == NULL) {
    cout << " List is Empty" << endl;
  } else {
    struct Node *temp = head;

    cout << "\n Linked List elements are: " << endl;
    while (temp != NULL) {
      cout << temp->data << " --> ";
      temp = temp->next;
    }
    cout << "NULL" << endl;
  }
}

int main() {
  insertAtEnd(1);
  display();
  insertAtBeginning(2);
  insertAtBeginning(3);
  display();
  insertAtEnd(4);
  insertAtEnd(5);
  display();
  insertAfter(6, 1);
  display();
  deleteAtBeginning();
  display();
  deleteAtEnd();
  display();
  deleteNode(6);
  display();
  deleteNode(4);
  display();
  deleteNode(2);
  display();
  cout << "\n Final Linked list: ";
  display();
}
