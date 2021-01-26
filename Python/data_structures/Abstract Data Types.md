## Arrays :

Array is a data structure which can store multiple values in a single variable.
Arrays store elements at a _0(zero)-based_ unique index (0,1,2 ... n-1). So the last element for an array of length **n** is at index **n-1**.
There are 4 data types of array :

### Lists :

A list is **ordered** and **mutable** (changeable). In Python lists are written with _square brackets_.

> My list implementation : https://github.com/kartikp36/IntroductionToCS/blob/master/Python/data_structures/array_list.py

### Tuples :

A tuple is **ordered** and **immutable** (you cannot change element in a tuple once created). So any in-built methods for deleting or changing do not exist. In Python tuples are written with _round brackets_.

### Sets :

A set is is **unordered** (you cannot be sure in which order the items will appear) and **unindexed**. In Python, sets are written with _curly brackets_. It cannot have duplicates ie. same element multiple time. In other words all elements of a set are unique. It has many in-built methods like union, intersection, difference, symmetric difference, issubset, etc.

### Dictionaries :

Dictionary is unordered, changeable and indexed. In Python, dictionaries are written with curly brackets, and they have keys and values.

> Python dictionaries are implemented as **hash tables**.

## Stack :

- Follows LIFO.
- Instance variable: 'top'.

### Methods :

- push - O(1)
- pop - O(1)
- peek - O(1)

## Queue :

- Follows FIFO.
- Instance variable: 'rear' and 'front'.

### Methods :

- enqueue - O(1)
- dequeue - O(1)
- front - O(1)
- rear - O(1)

## LinkedList :

- Instance variable: 'head node'.

### Methods :

- insert - O(1)
- remove - O(1)
  > LinkedList Implementation : https://github.com/Kartikp2002/IntroductionToCS/blob/master/Python/data_structures/linked_list.py
