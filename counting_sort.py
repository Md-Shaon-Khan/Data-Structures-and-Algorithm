def countingSort(arr):
    max_val = max(arr)
    count = [0] * (max_val + 1)

    while len(arr) > 0:
        num = arr.pop(0)
        count[num] += 1

    # for i in range(len(count)):
    #     while count[i] > 0:
    #         arr.append(i)
    #         count[i] -= 1
    
    for i in range(len(count)):
        arr.extend([i] * count[i])
    
    return arr


myList = [5,3,6,1,7,8,4,2,0,3,2,9]
mySortedArray = countingSort(myList)
print(mySortedArray)