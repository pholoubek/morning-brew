"""
Complexity: Theta(n)  //  the second loop is bounded by a constant since we iterate through finite sequence of chars
"""
#!/bin/python
import sys

def minimumNumber(n, password):
    count = 0
    checkList = [0,0,0,0]
    for i in password:
        if i.isupper() and checkList[0] == 0:
            checkList[0] = 1
            count += 1
        elif i.islower() and checkList[1] == 0:
            checkList[1] = 1
            count += 1
        elif i.isdigit() and checkList[2] == 0:
            checkList[2] = 1
            count += 1
        else:
            for j in '!@#$%^&*()-+':
                if i == j and checkList[3] == 0:
                    checkList[3] = 1
                    count += 1
    return max(4 - count, 6 - n)
