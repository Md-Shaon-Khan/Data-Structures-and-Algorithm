def binary_search(arr,targetValue):
    start = 0
    end = len(arr) - 1

    while start <= end:
        mid = (start+end) / 2

        if arr[mid] == targetValue:
            return mid
        elif arr[mid] < targetValue:
            start = mid + 1
        else:
            end = mid - 1
    return -1

mylist = [1, 3, 5, 7, 9, 11, 13, 15, 17, 19]
x = 11

result = binary_search(mylist, x)

if result != -1:
  print("Found at index", result)
else:
  print("Not found")