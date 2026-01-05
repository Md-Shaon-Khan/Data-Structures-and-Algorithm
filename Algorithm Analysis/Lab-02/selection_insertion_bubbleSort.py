import time

# Selection Sort
def selectionSort(arr):
    n = len(arr)
    for i in range(n-1):
        min_index = i
        for j in range(i+1, n):
            if arr[j][0] < arr[min_index][0]:
                min_index = j
        arr[i], arr[min_index] = arr[min_index], arr[i]
    return arr

# Insertion Sort
def insertionSort(arr):
    n = len(arr)
    for i in range(1, n):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j][0] > key[0]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
    return arr

# Bubble Sort
def bubbleSort(arr):
    n = len(arr)
    for i in range(n - 1):
        for j in range(n - i - 1):
            if arr[j][0] > arr[j + 1][0]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
    return arr

# Dataset
arr = [
    (1025, 4),(1011, 2),(1033, 5),(1008, 1),(1042, 7),
    (1018, 3),(1055, 2),(1002, 6),(1021, 8),(1038, 1),
    (1015, 4),(1049, 5),(1029, 2),(1006, 9),(1052, 3),
    (1031, 6),(1012, 2),(1004, 7),(1040, 5),(1023, 4),
    (1010, 3),(1050, 8),(1009, 1),(1035, 9),(1027, 2)
]

arrSelectionSort = arr.copy()
arrInsertionSort = arr.copy()
arrBubbleSort = arr.copy()

def printArr(arr, times):
    for i in arr:
        print(f"({i[0]}:{i[1]}),", end=" ")
    print(f"\nTime needed: {times:.10f} seconds\n")

print("Before sorting:")
for i in arr:
    print(f"({i[0]}:{i[1]}),", end=" ")
print("\n\n")

# Selection Sort
start = time.perf_counter()
arrSelectionSort = selectionSort(arrSelectionSort)
selectionSortTime = time.perf_counter() - start
print("Selection Sort,")
printArr(arrSelectionSort, selectionSortTime)

# Insertion Sort
start = time.perf_counter()
arrInsertionSort = insertionSort(arrInsertionSort)
insertionSortTime = time.perf_counter() - start
print("Insertion Sort,")
printArr(arrInsertionSort, insertionSortTime)

# Bubble Sort
start = time.perf_counter()
arrBubbleSort = bubbleSort(arrBubbleSort)
bubbleSortTime = time.perf_counter() - start
print("Bubble Sort,")
printArr(arrBubbleSort, bubbleSortTime)