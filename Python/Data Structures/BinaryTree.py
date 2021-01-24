
class Node:
    def __init__(self, item=None, link=None):
        self.item = item
        self.next = link

    def __str__(self):
        return str(self.item)


def print_structure(node):
    current_node = node
    print("[", end="")
    while current_node is not None:
        print(current_node, end=", ")
        current_node = current_node.next
    print("]")


class Stack:
    def __init__(self):
        self.top = None

    def is_empty(self):
        return self.top is None

    def push(self, item):
        self.top = Node(item, self.top)

    def pop(self):
        assert not self.is_empty(), "Nothing to pop"
        item = self.top.item
        self.top = self.top.next
        return item


class TreeNode:

    def __init__(self, item=None, left=None, right=None):
        self.item = item
        self.left = left
        self.right = right

    def __str__(self):
        return str(self.item) + 'left: ' + str(self.left)

    def is_leaf(self):
        return self.left is None and self.right is None


class BinaryTree:

    def __init__(self):
        self.root = None

    def is_empty(self):
        return self.root is None

    def add(self, item, location_bitstring):
        bitstring_iterator = iter(location_bitstring)
        self.root = self.add_aux(self.root, item, bitstring_iterator)

    def add_aux(self, current, item, bitstring_iterator):
        if current is None:
            current = TreeNode()
        try:
            bit = next(bitstring_iterator)
            if bit == "0":
                current.left = self.add_aux(
                    current.left, item, bitstring_iterator)
            elif bit == "1":
                current.right = self.add_aux(
                    current.right, item, bitstring_iterator)
            else:
                raise ValueError("Bitstring location is not a bitstring")
        except StopIteration:
            current.item = item
        return current

    def print_preorder(self):
        self.print_preorder_aux(self.root)

    def print_preorder_aux(self, current):
        if current is not None:
            print(current, end=", ")
            self.print_preorder_aux(current.left)
            self.print_preorder_aux(current.right)

    def print_inorder(self):
        self.print_inorder_aux(self.root)

    def print_inorder_aux(self, current):
        if current is not None:
            self.print_inorder_aux(current.left)
            print(current, end=", ")
            self.print_inorder_aux(current.right)

    def __iter__(self):
        return PreOrderIterator(self.root)

    def __len__(self):
        return self._len_aux(self.root)

    def _len_aux(self, current):
        if current is None:
            return 0
        return 1 + self._len_aux(current.left) + self._len_aux(current.right)

    def get_leaves(self):
        a_list = []
        self._get_leaves_aux(self.root, a_list)
        return a_list

    def _get_leaves_aux(self, current, a_list):
        if current is not None:
            if current.is_leaf():
                a_list.append(current.item)
            else:
                self._get_leaves_aux(current.left, a_list)
                self._get_leaves_aux(current.right, a_list)


class PreOrderIterator:

    def __init__(self, root):
        self.current = root
        self.stack = Stack()
        self.stack.push(root)

    def __iter__(self):
        return self

    def __next__(self):
        if self.stack.is_empty():
            raise StopIteration
        self.current = self.stack.pop()
        if self.current.right is not None:
            self.stack.push(self.current.right)
        if self.current.left is not None:
            self.stack.push(self.current.left)
        return self.current.item


def main():
    my_tree = BinaryTree()
    my_tree.add(1, '')
    my_tree.add(2, '1')
    my_tree.add(3, '0')
    print(my_tree.get_leaves())
    my_tree.add(4, '01')
    print(my_tree.get_leaves())


if __name__ == "__main__":
    main()
