// Linked list implementation in C++

#include <iostream>
using namespace std;

struct Node {
 public:
  int data, length = 0;
  Node *next;
};

bool isEmpty(Node *head_ref) {
  return (head_ref == NULL);
}

void insertAtBeginning(Node **head_ref, Node **tail_ref, int value) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->data = value;
  new_node->next = (*head_ref);
  if (isEmpty(*head_ref)) {
    (*tail_ref) = new_node;
  }
  (*head_ref) = new_node;
  cout << " Node inserted at the beginning!" << endl;
  (*head_ref)->length++;
}

void insertAfter(Node **head_ref, Node **tail_ref, int value, int location) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->data = value;
  if (isEmpty((*head_ref))) {
    new_node->next = NULL;
    (*head_ref) = new_node;
    (*tail_ref) = (*head_ref);
  } else {
    Node *temp = (*head_ref);
    while (temp->data != location) {
      temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
  }
  cout << " Node inserted!" << endl;
  (*head_ref)->length++;
}

void insertAtEnd(Node **head_ref, Node **tail_ref, int value) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->data = value;
  new_node->next = NULL;
  if (isEmpty((*head_ref))) {
    (*head_ref) = new_node;
    (*tail_ref) = (*head_ref);
  } else {
    (*tail_ref)->next = new_node;
    (*tail_ref) = new_node;
  }
  cout << " Node inserted at the end!" << endl;
  (*head_ref)->length++;
}

void deleteAtBeginning(Node **head_ref, Node **tail_ref) {
  if (isEmpty((*head_ref))) {
    cout << "List is empty. Deletion failed!" << endl;
  } else {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp = (*head_ref);
    if (temp->next == NULL) {
      (*head_ref) = NULL;
      (*tail_ref) = NULL;
    } else {
      (*head_ref) = temp->next;
      (*head_ref)->length--;
    }
    delete temp;
  }
  cout << " Node at the beginning deleted!" << endl;
}

void deleteAtEnd(Node **head_ref, Node **tail_ref) {
  if (isEmpty((*head_ref))) {
    cout << "List is empty. Deletion failed!" << endl;
  } else {
    Node *temp1 = (Node *)malloc(sizeof(Node));
    Node *temp2 = (Node *)malloc(sizeof(Node));
    temp1 = (*head_ref);
    if (temp1->next == NULL) {
      (*head_ref) = NULL;
      (*tail_ref) = NULL;
    } else {
      while (temp1->next != NULL) {
        temp2 = temp1;
        temp1 = temp1->next;
      };
      temp2->next = NULL;
      (*tail_ref) = temp2;
      (*head_ref)->length--;
    }
    delete temp1;
  }
  cout << " Node at the end deleted!" << endl;
}

void deleteNode(Node **head_ref, Node **tail_ref, int value) {
  if (isEmpty((*head_ref))) {
    cout << "List is empty. Deletion failed!" << endl;
  } else {
    Node *temp1 = (Node *)malloc(sizeof(Node));
    Node *temp2 = (Node *)malloc(sizeof(Node));
    temp1 = (*head_ref);

    while (temp1->data != value) {
      if (temp1->next == NULL) {
        cout << "Given node not found. Deletion failed!" << endl;
        return;
      }
      temp2 = temp1;
      temp1 = temp1->next;
    };
    // if temp1 is first node
    if (temp1 == (*head_ref)) {
      (*head_ref) = (*head_ref)->next;
    } else if (temp1 == (*tail_ref)) {
      temp2->next = temp1->next;
      (*tail_ref) = temp2;
    } else {
      temp2->next = temp1->next;
    }
    delete temp1;
  }
  cout << " Node: " << value << " deleted!" << endl;
  (*head_ref)->length--;
}

void display(Node **head_ref) {
  if (isEmpty((*head_ref))) {
    cout << " List is Empty" << endl;
  } else {
    Node *temp = (*head_ref);

    cout << "\n Linked List elements are: " << endl;
    while (temp != NULL) {
      cout << temp->data << " --> ";
      temp = temp->next;
    }
    cout << "NULL" << endl;
  }
};

int main() {
  Node *head1 = NULL, *tail1 = NULL;
  //  *head2i;
  insertAtEnd(&head1, &tail1, 1);
  display(&head1);
  insertAtBeginning(&head1, &tail1, 2);
  insertAtBeginning(&head1, &tail1, 3);
  display(&head1);
  insertAtEnd(&head1, &tail1, 4);
  insertAtEnd(&head1, &tail1, 5);
  display(&head1);
  insertAfter(&head1, &tail1, 6, 1);
  display(&head1);
  deleteAtBeginning(&head1, &tail1);
  display(&head1);
  deleteAtEnd(&head1, &tail1);
  display(&head1);
  deleteNode(&head1, &tail1, 6);
  display(&head1);
  deleteNode(&head1, &tail1, 4);
  display(&head1);
  deleteNode(&head1, &tail1, 2);
  display(&head1);
  deleteAtBeginning(&head1, &tail1);
  cout << "\n Final Linked list: ";
  display(&head1);
}
