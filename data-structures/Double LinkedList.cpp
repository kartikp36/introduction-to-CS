// Double Linked list implementation in C++

#include <iostream>
using namespace std;

struct Node {
  int data;
  struct Node *previous, *next;
} *head = NULL;

// Insertion

void insertAtBeginning(int value) {
  struct Node *new_node;
  new_node = (struct Node *)malloc(sizeof(struct Node));
  new_node->data = value;
  new_node->previous = NULL;

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
    new_node->previous = NULL;
    head = new_node;
  } else {
    struct Node *temp2, *temp1 = head;
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
  cout << " Node inserted!" << endl;
}

void insertAtEnd(int value) {
  struct Node *new_node;
  new_node = (struct Node *)malloc(sizeof(struct Node));
  new_node->data = value;
  new_node->next = NULL;
  if (head == NULL) {
    new_node->previous = NULL;
    head = new_node;
  } else {
    struct Node *temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    };
    temp->next = new_node;
    new_node->previous = temp;
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
    if (temp->next == temp->previous) {
      head = NULL;
    } else {
      head = temp->next;
      head->previous = NULL;
    }
    delete temp;
  }
  cout << " Node at the beginning deleted!" << endl;
}

void deleteAtEnd() {
  if (head == NULL) {
    cout << "List is empty. Deletion failed!" << endl;
  } else {
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
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
  cout << " Node at the end deleted!" << endl;
}

void deleteNode(int value) {
  if (head == NULL) {
    cout << "List is empty. Deletion failed!" << endl;
  } else {
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
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
  cout << " Node: " << value << " deleted!" << endl;
}
// Display

void display() {
  if (head == NULL) {
    cout << " List is Empty" << endl;
  } else {
    struct Node *temp = head;

    cout << "\n Double Linked List elements are: " << endl;
    while (temp != NULL) {
      cout << temp->data << " <===> ";
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
