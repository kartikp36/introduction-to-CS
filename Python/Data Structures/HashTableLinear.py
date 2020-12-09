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

class HashTableLinear:                      

    def __init__(self, size=7919, base=31415):
        self.count = 0
        self.table_size = size
        self.a = base
        self.array = build_array(self.table_size)

    def __len__(self):
        return self.count

    def hash_value(self, key):
        h = 0
        for i in range(len(key)):
            h = (h*self.a + ord(key[i])) % self.table_size
        return h

    def __setitem__(self, key, value):
        position = self.hash_value(key)
        for _ in range(self.table_size):
            if self.array[position] is None:
                self.array[position] = (key, value)
                self.count += 1
                return
            elif self.array[position][0] == key:
                self.array[position] = (key, value)
                return
            else:
                position = (position+1) % self.table_size
        raise ValueError("Table is Full!")

    def __getitem__(self, key):
        position = self.hash_value(key)
        for _ in range(self.table_size):
            if self.array[position] is None:
                raise KeyError("{} not found".format(key))
            elif self.array[position][0] == key:
                return self.array[position][1]
            else:
                position = (position + 1) % self.table_size
        raise KeyError("{} not found".format(key))

    def __str__(self):
        ans = "{"
        delimeter = ""
        for item in self.array:
            if item is not None:
                (key,value) = item
                ans +=  delimeter + str(key) + ":" + str(value)
                delimeter = ","
        ans += "}"
        return ans


def main():
    my_table = HashTableLinear()
    my_table["a"] = 1
    my_table["b"] = 2
    print(my_table)
    print(my_table['b'])


if __name__ == "__main__":
    main()

