def max_subarray_sum(arr):
    current_max = max_sum = arr[0]

    for i in range(1,len(arr)):
        current_max = max(arr[i],current_max+arr[i])
        max_sum = max(current_max,max_sum)

    return max_sum

arr = input("Enter array elements separated by space: ")
arr = list(map(int,arr.split()))

print("Maximum Subarray Sum:",max_subarray_sum(arr))