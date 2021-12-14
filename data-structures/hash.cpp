// Linear Hash Table implementation in C++

#include <iostream>
using namespace std;
const int SIZE = 10;

struct DataItem {
 public:
  int data, key;
};

struct DataItem* hash_array[SIZE];
struct DataItem* deleted_item;
struct DataItem* item;

int hashCode(int key) {
  return key % SIZE;
}

struct DataItem* search(int key) {
  int hash_index = hashCode(key);

  while (hash_array[hash_index] != NULL) {
    if (hash_array[hash_index]->key == key) {
      return hash_array[hash_index];
    }
    hash_index++;
    hash_index %= SIZE;
  }
  return NULL;
}

void insertItem(int key, int data) {
  struct DataItem* item = new struct DataItem;
  item->data = data;
  item->key = key;

  int hash_index = hashCode(key);

  while (hash_array[hash_index] != NULL && hash_array[hash_index]->key != -1) {
    hash_index++;
    hash_index %= SIZE;
  }
  hash_array[hash_index] = item;
}

struct DataItem* deleteItem(struct DataItem* item) {
  int key = item->key;
  int hash_index = hashCode(key);

  while (hash_array[hash_index] != NULL) {
    if (hash_array[hash_index]->key == key) {
      struct DataItem* temp = hash_array[hash_index];
      hash_array[hash_index] = deleted_item;
      return temp;
    }
    hash_index++;
    hash_index %= SIZE;
  }
  return NULL;
}

void display() {
  int i = 0;

  for (i = 0; i < SIZE; i++) {
    if (hash_array[i] != NULL)
      cout << " (" << hash_array[i]->key << ", " << hash_array[i]->data << ")";
    else
      cout << " ~~ ";
  }
  cout << endl;
}

int main() {
  struct DataItem* deleted_item = new struct DataItem;
  deleted_item->data = -1;
  deleted_item->key = -1;

  insertItem(1, 10);
  insertItem(9, 12);
  insertItem(42, 30);
  insertItem(4, 25);
  insertItem(112, 44);
  insertItem(14, 6);
  insertItem(17, 13);
  insertItem(10, 78);

  display();
  item = search(112);
  cout << item->data << endl;
  deleteItem(item);
  item = search(2);
  cout << item;
}
