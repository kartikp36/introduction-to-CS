class Node:
    def __init__(self, item=None, link=None):
        self.item = item
        self.next = link
    def __str__(self):
        return str(self.item)


class LinkedList:

    def __init__(self):
        self.head = None
        self.count = 0

    def is_empty(self):
        return self.count == 0

    def is_full(self):
        return False

    def reset(self):
        self.__init__()

    def __len__(self):
        return self.count

    def _get_node(self, index):
        assert 0 <= index < self.count, "Index should be in range"
        node = self.head
        for _ in range(index):
            node = node.next
        return node

    def append(self, item):
        index = len(self)
        if index == 0:
            self.head = Node(item, self.head)
        else:
            node = self._get_node(index-1)
            node.next = Node(item, node.next)
        self.count += 1

    def pop(self,*index):
        if index:
            index = index[0]
            pass
        else:
            index = len(self)-1
        if self.is_empty():
            raise ValueError("List is empty")
        if index == 0:
            self.head = self.head.next
        else:
            node = self._get_node(index-1)
            node.next = node.next.next
        self.count -= 1
    def remove(self, key): 
        temp = self.head  
        if (temp is not None):  
            if (temp.item == key):  
                self.head = temp.next
                temp = None
                return
        while(temp is not None):  
            if temp.item == key:  
                break
            prev = temp  
            temp = temp.next
        if(temp == None):  
            return
        prev.next = temp.next
        temp = None

    def __iter__(self):
        return MyLinkedListIterator(self.head)

class MyLinkedListIterator:

    def __init__(self, head):
        self.current = head

    def __next__(self):
        if self.current is None:
            raise StopIteration
        else:
            item_required = self.current.item
            self.current = self.current.next
            return item_required

    def __iter__(self):
        return self


def main():
    my_list = LinkedList()
    my_list.append(1)
    print([i for i in my_list])
    my_list.append(5)
    my_list.append(6)
    my_list.append(7)
    print([i for i in my_list])
    my_list.pop()
    print([i for i in my_list])
    my_list.pop(1)
    print([i for i in my_list])
    my_list.remove(6)
    print([i for i in my_list])


if __name__ == "__main__":
    main()


