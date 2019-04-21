import sys

#  Given the assumption, this solution has the following cute propety:
def marsExploration(s):
    # Complete this function
    count = 0
    st = 'SOS'
    for i in range(len(s)):
        if s[i] != st[i % 3]:
            count += 1
    return count
