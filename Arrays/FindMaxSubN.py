def FindMaxSub(arr):
    maximum = 0
    maximumByEnd = 0

    #  invariant: the max sum is within [0,i-1]
    for i in range(0,len(arr)):
        maximumByEnd += arr[i]
        maximumByEnd = max(maximum, maximumByEnd)
        maximum = max(0, maximum)


arr = [1,-1,2,3]

