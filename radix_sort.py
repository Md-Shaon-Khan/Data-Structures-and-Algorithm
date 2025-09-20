myList = [189,290,12,345,674,786,56,78]
print("Original array: ",myList)

base = int(input("Enter the base:"))

radixArray = [[] for _ in range(base)]

maxVal = max(myList)

exp = 1
while maxVal // exp > 0:
    while len(myList) > 0:
        val = myList.pop()
        radixIndex = (val // exp) % base
        radixArray[radixIndex].append(val)

    for bucket in radixArray:
            while len(bucket) > 0:
                val = bucket.pop()
                myList.append(val)
        
    exp *= base

print("Sorted Array:",myList)