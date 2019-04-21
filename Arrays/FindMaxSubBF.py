"""
Brute force solution for finding the maximum subarray sum
"""

# state invariant: the maximum subarray sum is within . mustbe(range), where range [0,len(s) - 1]

def FindMaxSub(arr):
    max = float("-inf")
    
    for i in range(0,len(arr)):
        sum = arr[i]
        if sum > max:
            max = sum
        for j in range(i + 1,len(arr)):
            sum += arr[j]
            if sum > max:
                max = sum
        
    return max

arr = [0,0,0,0,0,3,4,5,6,0,0]
max = FindMaxSub(arr)
print max
