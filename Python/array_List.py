import ctypes

def build_array(size):
    """
    This function creates an array of references to Python Objects.
    Args:
        size (int): A positive integer, the size of the array.
    Returns:
        An array of python references with the given size.
    """
    if size <= 0:
        raise ValueError("Array size should be larger than 0.")
    if not isinstance(size,  int):
        raise ValueError("Array size should be an integer.")
    array = (size * ctypes.py_object)()
    array[:] = size * [None]
    return array



class List:
    def __init__(self, max_capacity):
        assert max_capacity > 0, "Size should be positive."
        self.count = 0
        self.array = build_array(max_capacity)

    def __len__(self):
        return self.count

    def is_empty(self):
        return self.count == 0

    def is_full(self):
        self.count >= len(self.array)

    def add(self, item):
        has_space_left = not self.is_full()
        if has_space_left:
            self.array[self.count] = item
            self.count += 1
        return has_space_left

    def pop(self, *index):
        if index:
            index = index[0]
            pass
        else:
            index = len(self)-1
        if self.is_empty():
            raise ValueError("List is empty")

        valid_index = index >= 0 and index < self.count
        
        if valid_index:
            for i in range(index, self.count - 1):
                self.array[i] = self.array[i+1]
            self.count -= 1
        return valid_index

    def __str__(self):
        ans = "["
        delimeter = ""
        for i in range(self.count):
            ans += delimeter + str(self.array[i])
            delimeter = ","
        ans += ']'
        return ans


def main():
    a_list = List(1000)
    a_list.add("Hello")
    a_list.add("User")
    print(a_list)
    a_list.add("World")
    a_list.pop(1)
    print(a_list)
    print(len(a_list))


if __name__ == "__main__":
    main()

