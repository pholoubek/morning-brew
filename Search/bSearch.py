"""
Binary Search

precondition: 
    a[0] <= a[1] <= a[2] <= ... <= a[n-1]
postcondition:
    result == -1    ->  t result not in a
    0 <= result < n ->  a[result] = t

Complexity:

"""
#  define invariant: the result is within the range which is defined by condition mustbe(range) -> inclusive
#  invariant: the result mustbe(range)
def bSearch(a, target):
    l = 0
    h = len(a) - 1
    while l <= h:               #  preserving the intial invariant: mustbe(l,h) since l..h is the range
        mid = (l + h) // 2 
        if a[mid] > target:
            h = mid - 1         #  preserving invariant: if a[m] > t -> range [m+1, h]
        elif a[mid] < target:
            l = mid + 1         #  preserving invariant: if a[m] < t -> range [l, m - 1]
        elif a[mid] == target:
            return mid          #  termination: if a[m] == t -> return and abort the search

    #  termination: if l > h -> mid + 1 up to h and mid - 1 down to l. Thus we're guranteed l > h
    return -1

        


a = [4,35,4,6,5,4,6,-53,32,-5,45,65,65,7,6,8,78,5,-74,4,63,432,25,54,6,-6,57,-67,8,7,9,74,6,-3,6,35,3,542,56,65,-767,878,-79,9,86]
a.sort()

i = bSearch(a,-5)
print "output: " + str(a[i]) + " " + str(i)

i = bSearch(a,0)
print "output: " + str(a[i]) + " " + str(i)

i = bSearch(a,32)
print "output: " + str(a[i]) + " " + str(i)
