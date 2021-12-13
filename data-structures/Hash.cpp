// Linear Hash Table implementation in C++

#include <iostream>
using namespace std;
const int SIZE = 10;

struct DataItem {
 public:
  int data, key;
};

struct DataItem* hashArray[SIZE];
struct DataItem* deletedItem;
struct DataItem* item;

int hashCode(int key) {
  return key % SIZE;
}

struct DataItem* search(int key) {
  int hashIndex = hashCode(key);

  while (hashArray[hashIndex] != NULL) {
    if (hashArray[hashIndex]->key == key) {
      return hashArray[hashIndex];
    }
    hashIndex++;
    hashIndex %= SIZE;
  }
  return NULL;
}

void insertItem(int key, int data) {
  struct DataItem* item = new struct DataItem;
  item->data = data;
  item->key = key;

  int hashIndex = hashCode(key);

  while (hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1) {
    hashIndex++;
    hashIndex %= SIZE;
  }
  hashArray[hashIndex] = item;
}

struct DataItem* deleteItem(struct DataItem* item) {
  int key = item->key;
  int hashIndex = hashCode(key);

  while (hashArray[hashIndex] != NULL) {
    if (hashArray[hashIndex]->key == key) {
      struct DataItem* temp = hashArray[hashIndex];
      hashArray[hashIndex] = deletedItem;
      return temp;
    }
    hashIndex++;
    hashIndex %= SIZE;
  }
  return NULL;
}

void display() {
  int i = 0;

  for (i = 0; i < SIZE; i++) {
    if (hashArray[i] != NULL)
      cout << " (" << hashArray[i]->key << ", " << hashArray[i]->data << ")";
    else
      cout << " ~~ ";
  }
  cout << endl;
}

int main() {
  struct DataItem* deletedItem = new struct DataItem;
  deletedItem->data = -1;
  deletedItem->key = -1;

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
