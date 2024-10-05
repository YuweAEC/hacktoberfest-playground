def binary_search(arr, target):
    low = 0
    high = len(arr) - 1

    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1

    return -1

if __name__ == "__main__":
    sorted_list = [45, 62, 40, 72, 70, 95, 23]
    
    sorted_list.sort()

    target = 72
    result = binary_search(sorted_list, target)

    if result != -1:
        print(f"Element found at index {result}")
    else:
        print("Element not found in the list")
