arr = list(map(int, input("Enter array elements separated by space: ").split()))

stack = []
nge = [-1] * len(arr)

for i in range(len(arr)-1, -1, -1):
    while stack and stack[-1] <= arr[i]:
        stack.pop()
    nge[i] = stack[-1] if stack else -1
    stack.append(arr[i])

print("Next Greater Elements:", nge)
