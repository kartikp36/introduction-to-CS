def InsertionSort(arr):
    for i in range(len(arr)):
        key = arr[i]
        j = i
        while j-1 >= 0 and arr[j-1] > key:
            arr[j] = arr[j-1]
            j -= 1
        arr[j] = key
    return(arr)
    