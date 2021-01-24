def MergeSort(arr):
    if len(arr) > 1:
        r = len(arr)//2
        L = arr[:r]
        M = arr[r:]

        MergeSort(L)
        MergeSort(M)

        i = j = k = 0
        while i < len(L) and j < len(M):
            if L[i] < M[j]:
                arr[k] = L[i]
                i += 1
            else:
                arr[k] = M[j]
                j += 1
            k += 1

        while i < len(L):
            arr[k] = L[i]
            i += 1
            k += 1

        while j < len(M):
            arr[k] = M[j]
            j += 1
            k += 1
        return arr
