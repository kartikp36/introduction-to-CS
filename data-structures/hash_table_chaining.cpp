// Hash Table chaining with Singly Linked Lists implementation in C++

#include <iostream>
using namespace std;
const int SIZE = 10;

struct HashNode {
 public:
  int key, value;
  HashNode *next;
  HashNode(int key, int value) {
    this->key = key;
    this->value = value;
    this->next = NULL;
  }
};

struct HashNode **hash_array = new HashNode *[SIZE];
struct HashNode *deleted_item = new HashNode(-1, -1);

int hashCode(int key) { return key % SIZE; }

struct HashNode *search(int key) {
  int hash_val = hashCode(key);
  HashNode *entry = hash_array[hash_val];
  while (entry != NULL) {
    if (entry->key == key) {
      return entry;
    }
    entry = entry->next;
  }
  return deleted_item;
}

void insertItem(int key, int value) {
  int hash_val = hashCode(key);
  HashNode *prev = NULL;
  HashNode *entry = hash_array[hash_val];
  while (entry != NULL) {
    prev = entry;
    entry = entry->next;
  }
  if (entry == NULL) {
    entry = new HashNode(key, value);
    if (prev == NULL) {
      hash_array[hash_val] = entry;
    } else {
      prev->next = entry;
    }
  } else {
    entry->value = value;
  }
}

// struct HashNode* deleteItem(struct HashNode* item) {
void removeItem(int key) {
  bool flag = false;
  int hash_val = hashCode(key);
  HashNode *prev = NULL;
  HashNode *entry = hash_array[hash_val];
  while (entry != NULL) {
    if (entry->key == key) {
      if (prev == NULL) {
        hash_array[hash_val] = entry->next;
      } else {
        prev->next = entry->next;
      }
      flag = true;
      cout << " HashNode: (" << entry->key << " ," << entry->value
           << ") deleted" << endl;
      break;
    }
    prev = entry;
    entry = entry->next;
  }
  if (!flag) {
    cout << " Node not found" << endl;
  }
}

void display() {
  int i = 0;

  for (i = 0; i < SIZE; i++) {
    if (hash_array[i] != NULL) {
      cout << "[ ";
      HashNode *prev = NULL;
      HashNode *entry = hash_array[i];
      while (entry != NULL) {
        prev = entry;
        cout << " (" << prev->key << ", " << prev->value << ")";
        entry = entry->next;
      }
      cout << " ]";
    } else {
      cout << " [ ~~ ]";
    }
  }
  cout << endl;
}

int main() {
  insertItem(1, 10);
  insertItem(9, 112);
  insertItem(42, 30);
  insertItem(4, 25);
  insertItem(112, 44);
  insertItem(14, 6);
  insertItem(17, 13);
  insertItem(10, 78);
  insertItem(12, 69);

  display();
  struct HashNode *item;
  item = search(112);
  cout << "Element at key " << item->key << " is: " << item->value << endl;
  removeItem(42);
  item = search(2);
  cout << "(" << item->key << ", " << item->value << ")" << endl;
  removeItem(9);
  display();
}
