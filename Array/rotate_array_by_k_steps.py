def shift_array(num,arr):
    i=1
    while i<=num:
        element = arr.pop()
        arr.insert(0,element)
        i += 1
    return arr

arr = input("Enter array elements separated by space: ")
arr = list(map(int,arr.split()))

num = int(input("Enter the number of shift:"))

print("After Shifting the array:",shift_array(num,arr))