"""
Level: Easy
Project:    given string, it returns reduced string such that 
            no two even adjacent characters are next to each other
            For example, aaabb returns a because we have two a and two b to reduce
            
Running Complexity: Theta(n) + Theta(n) for print
"""

import sys

def super_reduced_string(s):
    stack = []
    i = 0
    stack.append(s[i])
    i = i + 1
    while i < len(s):
        if not stack:
            stack.append(s[i])
        else:
            temp = stack.pop()
            if temp != s[i]:
                stack.append(temp)
                stack.append(s[i])
        i = i + 1
    
    str = ""
    if not stack:
        str = "Empty String"
    else:
        for x in stack:
            str += x
    return str

