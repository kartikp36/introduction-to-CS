// Double Linked list implementation in C++

#include <iostream>
using namespace std;

struct Node {
 public:
  int data, length = 0;
  Node *previous, *next;
};
bool isEmpty(Node *head_ref) {
  return (head_ref == NULL);
}
void insertAtBeginning(Node **head_ref, int value) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->data = value;
  new_node->previous = NULL;

  if (isEmpty((*head_ref))) {
    new_node->next = NULL;
    (*head_ref) = new_node;
  } else {
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
  }
  (*head_ref)->length++;
  cout << " Node inserted at the beginning!" << endl;
}

void insertAfter(Node **head_ref, int value, int location) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->data = value;
  if (isEmpty((*head_ref))) {
    new_node->next = NULL;
    new_node->previous = NULL;
    (*head_ref) = new_node;
  } else {
    Node *temp2, *temp1 = (*head_ref);
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
  (*head_ref)->length++;
  cout << " Node inserted!" << endl;
}

void insertAtEnd(Node **head_ref, int value) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->data = value;
  new_node->next = NULL;
  if (isEmpty((*head_ref))) {
    new_node->previous = NULL;
    (*head_ref) = new_node;
  } else {
    Node *temp = (*head_ref);
    while (temp->next != NULL) {
      temp = temp->next;
    };
    temp->next = new_node;
    new_node->previous = temp;
  }
  (*head_ref)->length++;
  cout << " Node inserted at the end!" << endl;
}

void deleteAtBeginning(Node **head_ref) {
  if (isEmpty((*head_ref))) {
    cout << "List is empty. Deletion failed!" << endl;
  } else {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp = (*head_ref);
    if (temp->next == temp->previous) {
      (*head_ref) = NULL;
    } else {
      (*head_ref) = temp->next;
      (*head_ref)->previous = NULL;
      (*head_ref)->length--;
    }
    delete temp;
  }
  cout << " Node at the beginning deleted!" << endl;
}

void deleteAtEnd(Node **head_ref) {
  if (isEmpty((*head_ref))) {
    cout << "List is empty. Deletion failed!" << endl;
  } else {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp = (*head_ref);
    if (temp->next == temp->previous) {
      (*head_ref) = NULL;
    } else {
      while (temp->next != NULL) {
        temp = temp->next;
      };
      temp->previous->next = NULL;
      (*head_ref)->length--;
    }
    delete temp;
  }
  cout << " Node at the end deleted!" << endl;
}

void deleteNode(Node **head_ref, int value) {
  if (isEmpty((*head_ref))) {
    cout << "List is empty. Deletion failed!" << endl;
  } else {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp = (*head_ref);

    while (temp->data != value) {
      if (temp->next == NULL) {
        cout << "Given node not found. Deletion failed!" << endl;
        return;
      }
      temp = temp->next;
    };

    if (temp == (*head_ref)) {
      (*head_ref) = (*head_ref)->next;
      (*head_ref)->previous = NULL;
    } else if (temp->next == NULL) {
      temp->previous->next = NULL;
    } else {
      temp->previous->next = temp->next;
      temp->next->previous = temp->previous;
    }
    delete temp;
  }
  (*head_ref)->length--;
  cout << " Node: " << value << " deleted!" << endl;
}

void display(Node **head_ref) {
  if (isEmpty((*head_ref))) {
    cout << " List is Empty" << endl;
  } else {
    Node *temp = (*head_ref);

    cout << "\n Double Linked List elements are: " << endl;
    while (temp != NULL) {
      cout << temp->data << " <===> ";
      temp = temp->next;
    }
    cout << "NULL" << endl;
  }
};

int main() {
  Node *head1 = NULL;
  insertAtEnd(&head1, 1);
  display(&head1);
  insertAtBeginning(&head1, 2);
  insertAtBeginning(&head1, 3);
  display(&head1);
  insertAtEnd(&head1, 4);
  insertAtEnd(&head1, 5);
  display(&head1);
  insertAfter(&head1, 6, 1);
  display(&head1);
  deleteAtBeginning(&head1);
  display(&head1);
  deleteAtEnd(&head1);
  display(&head1);
  deleteNode(&head1, 6);
  display(&head1);
  deleteNode(&head1, 4);
  display(&head1);
  deleteNode(&head1, 2);
  display(&head1);
  cout << "\n Final Linked list: ";
  display(&head1);
}
