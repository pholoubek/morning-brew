def sort_count(arr, l, h):
    count = 0
    if l == h:
        return 0
    else:
        m = (h + l) / 2 #  integer division this it's rounded down
        sort_count(arr, l, m)
        sort_count(arr, m + 1, h)
        count = sort_count_cross(arr, l, m, h)
        return count
        
def sort_count_cross(arr, l, m, h):
    left = []
    for i in range(l, m + 1):
        left.append(arr[i])
    left.append(float('inf'))
    right = []
    for j in range(m + 1, h + 1):
        right.append(arr[j])
    right.append(float('inf'))
    
    i = 0
    j = 0
    count = 0
    for k in range(l, h+1):
        if right[i] < left[j]:
            arr[k] = right[i]
            count = len(left) - i
            i += 1
        else:
            arr[k] = left[j]
            j += 1
    return count
    
    
        
arr = [1,3,2,5,4,6,7,8,9]
print sort_count(arr,0,len(arr) - 1)
