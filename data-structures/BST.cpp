// Binary Searh Tree implementation in C++

#include <iostream>
using namespace std;

class node {
 public:
  int n, i, data;
  class node *left, *right, *temp, *root;

  void inorder(node* root) {
    if (root) {
      inorder(root->left);
      cout << root->data << " ";
      inorder(root->right);
    }
  }

  node* search(node* root, int key) {
    // Base Case: root is null or key is present at root
    if (root == NULL || root->data == key)
      return root;

    // Key is greater than root's key
    if (root->data < key)
      return search(root->right, key);

    // Key is smaller than root's key
    return search(root->left, key);
  }

  node* minValueNode(node* n) {
    node* current = n;

    /* Loop down to find the leftmost leaf */
    while (current && current->left != NULL)
      current = current->left;

    return current;
  }

  node* deleteNode(node* root, int key) {
    // Base case
    if (root == NULL)
      return root;

    // If the key to be deleted is smaller than the root's key, then it lies in left subtree
    if (key < root->data)
      root->left = deleteNode(root->left, key);

    // If the key to be deleted is greater than the root's key, then it lies in right subtree
    else if (key > root->data)
      root->right = deleteNode(root->right, key);

    // If key is same as root's key, then This is the node to be deleted
    else {
      // node has no child
      if (root->left == NULL and root->right == NULL)
        return NULL;

      // node with only one child
      else if (root->left == NULL) {
        node* temp = root->right;
        delete root;
        return temp;
      } else if (root->right == NULL) {
        node* temp = root->left;
        delete root;
        return temp;
      }

      // Node with two children: Get the inorder successor
      // (smallest in the right subtree)
      node* temp = minValueNode(root->right);

      // Copy the inorder successor's content to this node
      root->data = temp->data;

      // Delete the inorder successor
      root->right = deleteNode(root->right, temp->data);
    }
    return root;
  }

  void insert(int value) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    if (i == 0) {
      root = newNode;  // root always point to the root node
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
  node bst;
  bst.insert(2);
  bst.insert(6);
  bst.insert(9);
  bst.insert(1);
  bst.insert(5);
  bst.insert(8);
  cout << bst.search(bst.root, 1);

  cout << "\nBinary Search Tree nodes in Inorder Traversal: ";
  bst.inorder(bst.root);

  bst.deleteNode(bst.root, 9);
  cout << "\n Delete 9" << endl;
  bst.inorder(bst.root);

  bst.deleteNode(bst.root, 5);
  bst.deleteNode(bst.root, 1);
  cout << "\n After deletion" << endl;
  bst.inorder(bst.root);

  return 0;
}
