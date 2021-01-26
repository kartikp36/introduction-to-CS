from random import sample
from selection_sort import selection_sort

for _ in range(1000):

    array = sample(range(1, 101), 10)

    selection_sorted_array = selection_sort(array[:])
    inbuilt_sorted_array = sorted(array[:])

    for i in range(len(array)):
        if selection_sorted_array[i] != inbuilt_sorted_array[i]:
            raise Exception("Array not sorted.")
