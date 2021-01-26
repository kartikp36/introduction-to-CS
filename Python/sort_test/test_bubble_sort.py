from random import sample
from bubble_sort import bubble_sort

for _ in range(1000):

    array = sample(range(1, 101), 10)

    bubble_sorted_array = bubble_sort(array[:])
    inbuilt_sorted_array = sorted(array[:])

    for i in range(len(array)):
        if bubble_sorted_array[i] != inbuilt_sorted_array[i]:
            raise Exception("Array not sorted.")
