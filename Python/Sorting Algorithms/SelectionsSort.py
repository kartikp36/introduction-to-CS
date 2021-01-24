def SelectionSort(arr):
    n = len(arr)
    for i in range(n):
        minind = i
        for j in range(i+1, n):
            if arr[j] < arr[minind]:
                minind = j
        arr[i], arr[minind] = arr[minind], arr[i]
    return arr
