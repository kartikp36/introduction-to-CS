from random import sample
from insertion_sort import insertion_sort

for _ in range(1000):

    array = sample(range(1, 101), 10)

    insertion_sorted_array = insertion_sort(array[:])
    inbuilt_sorted_array = sorted(array[:])

    for i in range(len(array)):
        if insertion_sorted_array[i] != inbuilt_sorted_array[i]:
            raise Exception("Array not sorted.")
