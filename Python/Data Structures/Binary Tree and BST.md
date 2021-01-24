## Binary Trees :

Balanced : Each node has 2 children, all leaves at same level.
For N nodes height = logN
`height = h, leaves = 2 ^ h, nodes = (2^h+1) -1 `
Unbalanced : For N nodes height = N

### Methods :

- add - by using bitstring (0-left, 1-right)
- leaves - if left and right are none
  > Binary Tree Implementation : https://github.com/Kartikp2002/IntroductionToCS/blob/master/Python/BinaryTree.py

## Binary Search Tree :

- It is a Binary Tree where every node has a key.
- All keys in the left subtree of a node are smaller than it's own.
- All keys in the right subtree of a node are greater than it's own.

### Methods :

- **search Avg. T O(logn)** - starting with root node, till not found, go left if target is smaller else right, and if None not in here.
- **insert Avg. T O(logn)** - (keys are unique, so if already not in BST ) same as search till None
- **delete Avg. T O(logn)** :
  If node has no children : point parent to None
  If 1 child : point parent to the child
  If 2 children : successor(next larger key) is the new parent of the (orphan) children
- **get_max Avg. T O(N) & O(logN) for Balanced BST** - go right till None.
