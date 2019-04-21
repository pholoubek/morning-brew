"""
Level: Easy
Project:    Given string composed of words s.a. "helloWorld"
            it returns number of words separated by a Upper letter
Complexity: O(n)
"""

import sys

def camelcase(s):
    # Complete this function
    if len(s) == 0:
        return 0
    else:
        count = 1
        index = 0
        while index < len(s):
            if ord(s[index]) <= 90:
                count += 1
            index += 1
    return count
