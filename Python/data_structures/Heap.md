## Heap

Heaps are balanced binary trees, filled top to bottom, left to right and max/min are at root or leaves.
It can be implemented in array, 0th index is left (may have length of the heap)
elements are filled from 1st index such that :

- Root at k
- Parent position : k, Children at 2*k and 2*k +1.
  or parent of element at k is at k//2.

> Heap Implementation :
> https://github.com/Kartikp2002/IntroductionToCS/blob/master/Python/data_structures/heap.py

### Max Heap :

Root node is the greatest, children are less than or equal to parent node.

### Min Heap :

Root node is the smallest, children are greater than or equal to parent node.

### Methods :

- rise : rise (swap) until parent is greater or equal.
- sink : sink (swap) until parent is greater or equal.
- add T O(logN) - Put at bottom , rise.
- get_max T O(logN) - (max heap) swap root with last item, last item is max so remove it, rise.
  > _Process of rise and sink can be called heapify._
