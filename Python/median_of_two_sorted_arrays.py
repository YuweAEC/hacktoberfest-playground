def findMedianSortedArrays(arr1, arr2):
    if len(arr1) > len(arr2):
        arr1, arr2 = arr2, arr1
    
    x, y = len(arr1), len(arr2)
    low, high = 0, x
    while low <= high:
        partitionX = (low + high) // 2
        partitionY = (x + y + 1) // 2 - partitionX
        
        maxLeftX = float('-inf') if partitionX == 0 else arr1[partitionX - 1]
        minRightX = float('inf') if partitionX == x else arr1[partitionX]
        
        maxLeftY = float('-inf') if partitionY == 0 else arr2[partitionY - 1]
        minRightY = float('inf') if partitionY == y else arr2[partitionY]
        
        if maxLeftX <= minRightY and maxLeftY <= minRightX:
            if (x + y) % 2 == 0:
                return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2
            else:
                return max(maxLeftX, maxLeftY)
        elif maxLeftX > minRightY:
            high = partitionX - 1
        else:
            low = partitionX + 1
    
    raise ValueError("Input arrays are not sorted..!!")

arr1 = list(map(int, input("Enter the first sorted array: ").split()))
arr2 = list(map(int, input("Enter the second sorted array: ").split()))
median = findMedianSortedArrays(arr1, arr2)
print(f"The median is: {median}")