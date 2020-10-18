## Sorting Algorithms 
  

### Selection Sort : *Find minimum, put where it belongs.*
Best Time : O(N2)
Worst Time : O(N2)
Avg. Time : O(N2)
Stable : No
In-Place : Yes

### Heap Sort : *Take out the root from a max heap replacing it with the last element of heap, heapify.*
Best Time : O(NlogN)
Worst Time : O(NlogN) (root to leaf swap)
Avg. Time : O(NlogN)
Stable : No
In-Place : Yes

###  Insertion Sort : *Take last, put where it belongs.*
Best Time : O(N)( N comparisions)
Worst Time : O(N2)
Avg. Time : O(N2)
Stable : Yes
In-Place : Yes
  
### Bubble Sort : *If >, swap. Smaller bubble to front, larger sink to end.*
Best Time : O(N)
Worst Time : O(N2)
Avg. Time : O(N2)
Stable : No
In-Place : Yes

### Merge Sort :  *Split into 2, sort split, merge.*
Best Time : O(N log N)
Worst Time : O(N log N)
Avg. Time : O(N log N)
Stable : Yes
In-Place : No
  

### Quick Sort : *Pivot, <=> keep breaking.*
Best Time : O(N log N)
Worst Time : O(N2) – can be made O(N log N)
Avg. Time : O(N log N)
Stable : Depends
In-Place : No

### Counting Sort : 
Intialize 0s in array of size max(array), count frequency.
Best, Worst, Avg. Time : O(N+D) N-size of input array, D- size of count array ie. max(input array)
Stable : No, Yes if implemented in Linked List.
In-Place : No

### Radix Sort : 
Sort array of words alphabetically from ith to 1st column ie. right to left.

Best, Worst, Avg. Time : O((N+D)*M) N-size of input array, D- base, M - max length.
Stable : No, Yes if implemented in Linked List.
In-Place : No

## Searching Algorithms

### Linear Search : *Search through, linearly.*
Best Time : O(1)
Worst Time : O(N)
Avg. Time : O(N)

### Binary Search : *On sorted array check middle, if target is less than it-go left, else go right*
Best Time : O(1)
Worst Time : O(logN)
Avg. Time : O(logN)

### Depth First Search (DFS):
1.  Start by putting any one of the graph's vertices on top of a stack.
2.  Take the top item of the stack and add it to the visited list.
3.  Create a list of that vertex's adjacent nodes. Add the ones which aren't already in the visited list to the top of the stack.
4.  Keep repeating steps 2 and 3 until the stack is empty.
Time : O(V+E)
Space : O(V+E)

### Breadth First Search (BFS):
1.  Start by putting any one of the graph's vertices at the back of a queue.
2.  Take the front item of the queue and add it to the visited list.
3.  Create a list of that vertex's adjacent nodes. Add the ones which aren't in the visited list to the back of the queue.
4.  Keep repeating steps 2 and 3 until the queue is empty.
Time : O(V+E)
Space : O(V+E)

## Graph algorithms

> Abdul Bari YT

#### Dijkstra's Algorithm : 
Used for Shortest path.
Works on non negative numbers only.
### Bellman-Ford Algorithm :
Can work with negative weights.
Cannot find negative cycles.
### Floyd-Warshall Algorithm :
Can find negative cycles.
