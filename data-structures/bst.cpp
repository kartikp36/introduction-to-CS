// Binary Searh Tree implementation in C++

#include <iostream>
#include <list>
#include <stack>

using namespace std;

class Node {
 public:
  int n, i, data;
  class Node *left, *right, *temp, *root;

  // Reccursive traversals
  void inorder(Node* root) {
    if (root) {
      inorder(root->left);
      cout << root->data << " ";
      inorder(root->right);
    }
  }

  void preorder(Node* root) {
    if (root) {
      cout << root->data << " ";
      preorder(root->left);
      preorder(root->right);
    }
  }

  void postorder(Node* root) {
    if (root) {
      postorder(root->left);
      postorder(root->right);
      cout << root->data << " ";
    }
  }

  //  Iterative traverals
  // Depth-First Search
  void inorderIterative(Node* root) {
    // return if the tree is empty
    if (root == nullptr)
      return;
    // create an empty stack
    stack<Node*> stack;

    // start from the root Node (set current Node to the root Node)
    Node* current = root;

    // if the current Node is null and the stack is also empty, traversal is complete
    while (!stack.empty() || current != nullptr) {
      // if the current Node exists, push it into the stack and move to its left child
      if (current != nullptr) {
        stack.push(current);
        current = current->left;
      } else {
        // otherwise, if the current Node is null, pop an element from the stack,
        // print it, and set the current Node to its right child
        current = stack.top();
        stack.pop();
        cout << current->data << " ";
        current = current->right;
      }
    }
  }

  void preorderIterative(Node* root) {
    // return if the tree is empty
    if (root == nullptr)
      return;

    // create an empty stack and push the root Node
    stack<Node*> stack;
    stack.push(root);

    // loop till stack is empty
    while (!stack.empty()) {
      // pop a Node from the stack and print it
      Node* current = stack.top();
      stack.pop();

      cout << current->data << " ";

      // push the right child of the popped Node into the stack
      if (current->right) {
        stack.push(current->right);
      }

      // push the left child of the popped Node into the stack
      if (current->left) {
        stack.push(current->left);
      }
    }
  }

  void postorderIterative(Node* root) {
    // return if the tree is empty
    if (root == nullptr) {
      return;
    }

    // create an empty stack and push the root Node
    stack<Node*> s;
    s.push(root);

    // create another stack to store postorder traversal
    stack<int> post;

    // loop till stack is empty
    while (!s.empty()) {
      // pop a Node from the stack and push the data into the post stack
      Node* current = s.top();
      s.pop();

      post.push(current->data);

      // push the left and right child of the popped Node into the stack
      if (current->left) {
        s.push(current->left);
      }

      if (current->right) {
        s.push(current->right);
      }
    }

    // print postorder traversal
    while (!post.empty()) {
      cout << post.top() << " ";
      post.pop();
    }
  }

  // Breadth-First Search, Level-order Traversal

  void levelOrderTraversal(Node* root) {
    // return if the tree is empty
    if (root == nullptr) {
      return;
    }

    // create an empty queue and enqueue the root node
    list<Node*> queue;
    queue.push_back(root);

    // pointer to store the current node
    Node* current = nullptr;

    // loop till queue is empty
    while (queue.size()) {
      // process each node in the queue and enqueue it's non-empty left and right child
      current = queue.front();
      queue.pop_front();

      cout << current->data << " ";

      if (current->left) {
        queue.push_back(current->left);
      }

      if (current->right) {
        queue.push_back(current->right);
      }
    }
  }
  Node* search(Node* root, int data) {
    // Base Case: root is null or data is present at root
    if (root == NULL || root->data == data)
      return root;

    // Key is greater than root's data
    if (root->data < data)
      return search(root->right, data);

    // Key is smaller than root's data
    return search(root->left, data);
  }

  Node* minValueNode(Node* n) {
    Node* current = n;

    /* Loop down to find the leftmost leaf */
    while (current && current->left != NULL)
      current = current->left;

    return current;
  }

  Node* deleteNode(Node* root, int data) {
    // Base case
    if (root == NULL)
      return root;

    // If the data to be deleted is smaller than the root's data, then it lies in left subtree
    if (data < root->data)
      root->left = deleteNode(root->left, data);

    // If the data to be deleted is greater than the root's data, then it lies in right subtree
    else if (data > root->data)
      root->right = deleteNode(root->right, data);

    // If data is same as root's data, then This is the Node to be deleted
    else {
      // Node has no child
      if (root->left == NULL and root->right == NULL)
        return NULL;

      // Node with only one child
      else if (root->left == NULL) {
        Node* temp = root->right;
        delete root;
        return temp;
      } else if (root->right == NULL) {
        Node* temp = root->left;
        delete root;
        return temp;
      }

      // Node with two children: Get the inorder successor
      // (smallest in the right subtree)
      Node* temp = minValueNode(root->right);

      // Copy the inorder successor's content to this Node
      root->data = temp->data;

      // Delete the inorder successor
      root->right = deleteNode(root->right, temp->data);
    }
    return root;
  }

  void insert(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    if (i == 0) {
      root = newNode;  // root always point to the root Node
      i++;
    } else {
      temp = root;  // temp is used to traverse the tree
      while (1) {
        if (newNode->data > temp->data) {
          if (temp->right == NULL) {
            temp->right = newNode;
            break;
          } else
            temp = temp->right;
        } else {
          if (temp->left == NULL) {
            temp->left = newNode;
            break;
          } else
            temp = temp->left;
        }
      }
    }
  }
};

int main() {
  // Insert
  Node bst;
  bst.insert(4);
  bst.insert(2);
  bst.insert(6);
  bst.insert(1);
  bst.insert(3);
  bst.insert(5);
  bst.insert(7);
  cout << bst.search(bst.root, 1);

  cout << "\nBinary Search Tree nodes in Inorder Traversal: ";
  bst.inorder(bst.root);
  cout << "\nInorder Traversal Iterative: ";
  bst.inorderIterative(bst.root);

  cout << "\nBinary Search Tree nodes in Pre-order Traversal: ";
  bst.preorder(bst.root);

  cout << "\nBinary Search Tree nodes in Post-order Traversal: ";
  bst.postorder(bst.root);

  cout << "\nBinary Search Tree nodes in Level-order Traversal: ";
  bst.levelOrderTraversal(bst.root);

  bst.deleteNode(bst.root, 4);
  cout << "\n Delete 4" << endl;
  bst.inorder(bst.root);

  bst.deleteNode(bst.root, 6);
  bst.deleteNode(bst.root, 1);
  cout << "\n After deletion" << endl;
  bst.inorder(bst.root);
  cout << endl << endl;
  return 0;
}
