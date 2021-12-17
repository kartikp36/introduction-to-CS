// Trie implementation in C++

#include <iostream>
using namespace std;

const int ALPHA_SIZE = 26;

struct Trie {
  struct Trie *child[ALPHA_SIZE];
  bool end_of_string;
};

struct Trie *createNode(void) {
  struct Trie *top_node = new Trie;
  top_node->end_of_string = false;
  for (int i = 0; i < ALPHA_SIZE; i++)
    top_node->child[i] = NULL;
  return top_node;
}

void insert(struct Trie *root, string key) {
  struct Trie *current = root;
  for (int i = 0; i < key.length(); i++) {
    int index = key[i] - 'A';
    if (!current->child[index]) {
      current->child[index] = createNode();
    }
    current = current->child[index];
  }
  current->end_of_string = true;
}

bool search(struct Trie *root, string key) {
  struct Trie *current = root;
  for (int i = 0; i < key.length(); i++) {
    int index = key[i] - 'A';
    if (!current->child[index]) {
      cout << "Key: " << key << " is not found" << endl;
      return false;
    }
    current = current->child[index];
  }
  bool is_found = current != NULL && current->end_of_string;
  (is_found) ? (cout << "Key: " << key << " is Found\n") : (cout << "Key: " << key << " is not Found\n");
  return (is_found);
}

bool isEmpty(Trie *root) {
  for (int i = 0; i < ALPHA_SIZE; i++)
    if (root->child[i]) {
      return false;
    }
  return true;
}
Trie *deletion(Trie *root, string key, int depth = 0) {
  if (!root)
    return NULL;
  if (depth == key.length()) {
    if (root->end_of_string) {
      root->end_of_string = false;
    } else if (isEmpty(root)) {
      delete (root);
      root = NULL;
    }
    return root;
  }
  int index = key[depth] - 'A';
  root->child[index] = deletion(root->child[index], key, depth + 1);
  if (isEmpty(root) && root->end_of_string == false) {
    delete (root);
    root = NULL;
  }
  return root;
}

int main() {
  string inputs[] = {"ABCD", "ABC", "LMN", "NOP"};
  int n = sizeof(inputs) / sizeof(inputs[0]);
  struct Trie *root = createNode();
  for (int i = 0; i < n; i++) {
    insert(root, inputs[i]);
  }
  search(root, "ABCD");
  search(root, "A");
  deletion(root, "ABC")
      ? cout << "Key deleted\n"
      : cout << "Key not Deleted\n";
  search(root, "ABC");
  return 0;
}
