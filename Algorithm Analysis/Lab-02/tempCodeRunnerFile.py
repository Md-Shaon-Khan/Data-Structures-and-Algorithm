import time

# Sequential Search
def sequentialSearch(arr, number):
    result = []
    for order in arr:
        if order[1] > number:
            result.append(order)
    return result

# Binary Search (for demonstration, assuming we search specific order_ID)
# We’ll use it to find the quantity of a given order_ID
def binarySearch(arr, order_id):
    low, high = 0, len(arr) - 1
    while low <= high:
        mid = (low + high) // 2
        if arr[mid][0] == order_id:
            return arr[mid]
        elif arr[mid][0] < order_id:
            low = mid + 1
        else:
            high = mid - 1
    return None

# Printing helper
def printArr(arr, times):
    for i in arr:
        print(f"({i[0]}:{i[1]}),", end=" ")
    print(f"\tTime needed: {times:.10f} seconds\n")

print("Orders eligible for 50% discount (quantity > 3):\n")


# Sorted order list (from your previous sorting)
orders = [
    (1002, 6),(1004, 7),(1006, 9),(1008, 1),(1009, 1),
    (1010, 3),(1011, 2),(1012, 2),(1015, 4),(1018, 3),
    (1021, 8),(1023, 4),(1025, 4),(1027, 2),(1029, 2),
    (1031, 6),(1033, 5),(1035, 9),(1038, 1),(1040, 5),
    (1042, 7),(1049, 5),(1050, 8),(1052, 3),(1055, 2)
]

# Sequential Search Timing
start = time.perf_counter()
discountSequential = sequentialSearch(orders, 3)
sequentialTime = time.perf_counter() - start
print("Sequential Search:")
printArr(discountSequential, sequentialTime)

# Binary Search Timing (we search for each order_ID to simulate lookups)
start = time.perf_counter()
discountBinary = []
for order in orders:
    found = binarySearch(orders, order[0])
    if found and found[1] > 3:
        discountBinary.append(found)
binaryTime = time.perf_counter() - start

print("Binary Search:")
printArr(discountBinary, binaryTime)