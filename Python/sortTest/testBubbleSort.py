from random import sample
from bubbleSort import bubbleSort

for _ in range(1000):

    array = sample(range(1, 101), 10)

    bubbleSortedArray = bubbleSort(array[:])
    inbuiltSortedArray = sorted(array[:])

    for i in range(len(array)):
        if bubbleSortedArray[i] != inbuiltSortedArray[i]:
            raise Exception("Array not sorted.")
