"""
Linear search for second to max element within the given array

Complexity:
    Loop goes always through n element, thus Theta(n) + constants
"""
def secondLargest(arr):
    p = float("-inf")
    max = float("-inf")
    for index in range(0, len(arr), 1):
        if arr[index] > max:
            p = max
            max = arr[index]
        elif arr[index] >  p:
            p = arr[index]
    return p

arr = [-1,-2]
print(secondLargest(arr))

