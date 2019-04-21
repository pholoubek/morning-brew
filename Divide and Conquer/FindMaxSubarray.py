"""
Finding Max Subarray - Recursive
Recurisively finds maximum subarray within array which has the highest sum of all
First, it divides the task into atomic cells where arr has only 1 element
Second, it compares the subarrays to the left of the mid, to the right of the mid + 1 and finally in between such that low <= i <= mid < j <= high
Third, compares 3 cases: if strictly left sub-arr is greatest, if right sub-arr is greatest or in between

Recursively, if sub-array crosses mid, then it has left sub-arr and right sub-arr

Complexitt:
    findMaxSubarray: if n = 1 then Theta(1)
                        n > 1 then T(n) = 2T(n/2) + Theta(n) // plus constants which we don't show
    By solving the recurrence we get T(n) = Theta(n*lg(n)) //  simplyfing assumption that the input is power of two. 
"""
def findMaxSubarray(arr, low, high):
    if high == low:
        return (low, high, arr[low]) #  base case: 1 element in arr
    else:
        mid = (low + high) / 2
        (leftLow, leftHigh, leftSum) = findMaxSubarray(arr, low, mid) #  solves n/2 
        (rightLow, rightHigh, rightSum) = findMaxSubarray(arr, mid + 1, high) #  solves n/2
        (crossLow, crossHigh, crossSum) = findMaxCrossingSubarray(arr, low, mid, high) #  solves n

    if leftSum >= rightSum and leftSum >= crossSum:
        return (leftLow, leftHigh, leftSum)
    elif rightSum >= leftSum and rightSum >= crossSum:
        return (rightLow, rightHigh, rightSum)
    else:
        return (crossLow, crossHigh, crossSum)
    
def findMaxCrossingSubarray(arr, low, mid, high):
    leftSum = float("-inf")
    maxLeft = mid
    sum = 0
    for i in range(mid, low - 1, -1):
        sum += arr[i]
        if sum > leftSum:
            leftSum = sum
            maxLeft = i

    rightSum = float("-inf")
    sum = 0
    maxRight = mid + 1
    for j in range(mid + 1, high, 1):
        sum += arr[j]
        if sum > rightSum:
            rightSum = sum
            maxRight = j

    return (maxLeft, maxRight, leftSum + rightSum)


arr = [0,0,0,0,0,3,4,5,6,0,0]
(low, high, sum) = (findMaxSubarray(arr, 0, len(arr)-1))
print arr[low:high+1]
print sum
