## Queue

Queue is a linear data structure that follows the principle of First In First Out (FIFO). This means the first element inserted inside the queue is removed first.

### Basic Operations

- **Enqueue**: Add an element to the end of the queue
- **Dequeue**: Remove an element from the front of the queue
- **IsEmpty**: Check if the queue is empty
- **IsFull**: Check if the queue is full
- **Peek**: Get the value of the front of the queue without removing it

### Time Complexity

For the array-based implementation of a queue, all the operations mentioned above have **O(1)** ie. constant time complexity.

### There are four different types of queues:

- Simple Queue
- Circular Queue - In a circular queue, the last element points to the first element making a circular link (better memory utilization)
- Priority Queue - each element is served according to its priority.
- Deque (Double Ended Queue) - In a double ended queue, insertion and removal of elements can be performed from either from the front or rear. Thus, it does not follow the FIFO (First In First Out) rule.

#### Deque

##### Types of Deque

- **Input Restricted Deque**: In this deque, input is restricted at a single end but allows deletion at both the ends.
- **Output Restricted Deque**: In this deque, output is restricted at a single end but allows insertion at both the ends.
