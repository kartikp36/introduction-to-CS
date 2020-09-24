from random import sample
from insertionSort import insertionSort

for _ in range(1000):

    array = sample(range(1, 101), 10)

    insertionSortedArray = insertionSort(array[:])
    inbuiltSortedArray = sorted(array[:])

    for i in range(len(array)):
        if insertionSortedArray[i] != inbuiltSortedArray[i]:
            raise Exception("Array not sorted.")
