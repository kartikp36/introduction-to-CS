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


class Heap:

    def __init__(self):
        self.count = 0
        self.array = build_array(100)

    def __str__(self):
        ans = "["
        delimeter = ""
        for item in self.array:
            if item is not None:
                key, value = item
                ans += delimeter + str(value)
                delimeter = ","
        ans += "]"
        return ans

    def swap(self, i, j):
        self.array[i], self.array[j] = self.array[j], self.array[i]

    def rise(self, k):
        while k > 1 and self.array[k] > self.array[k//2]:
            self.swap(k, k//2)
            k //= 2

    def add(self, key, value):
        item = (value, key)
        if self.count + 1 < len(self.array):
            self.array[self.count+1] = item
        else:
            self.resize()
            self.array[self.count+1] = item
        self.count += 1
        self.rise(self.count)

    def _resize(self):
        new_array = build_array(2*len(self.array))
        for i in range(len(self.array)):
            new_array[i] = self.array[i]
        self.array = new_array


def main():
    my_heap = Heap()
    my_heap.add("fourth", 5)
    my_heap.add("sixth", -7)
    my_heap.add("third", 10)
    my_heap.add("fifth", -3)
    my_heap.add("second", 13)
    my_heap.add("max", 20)
    print(my_heap)


if __name__ == "__main__":
    main()
