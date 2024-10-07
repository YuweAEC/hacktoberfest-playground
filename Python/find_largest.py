def find_largest(arr):
    largest = arr[0]  # Assume the first element is the largest

    for num in arr:
        if num > largest:
            largest = num  # Update largest if current element is greater

    return largest

# Example usage
arr = [12, 45, 23, 67, 34, 89, 11]
largest = find_largest(arr)
print("The largest element in the list is:", largest)
