"""
Lemma: int d divides int a and int b, iff d divides a - b and b. 
Proof: let a = dp and b = dq, then a - b = d(p-q)
    
More efficient since each iteration decreases the input by factor of 2
Lemma: Let int a >= int b > 0. Then (a mod b) < a/2. 
Proof: 
    Case 1: if b <= a/2, then (a mod b) < b <= a/2
    case 2: if b > a/2, then (a mod b) a - b < a/2
"""
def gcd(a,b):
    assert a >= 0 and b >=0 and a + b > 0
    print("gcd({}, {})=").format(a,b)
    while a > 0 and b > 0:
        if a >= b:
            a = a - b   #  even better solution is a = a % b
        else:
            b = b - a   #  likewise here b = b % a
        print("gcd({}, {})=").format(a,b)
    return max(a,b)

def recGcd(a,b):
    assert a>= 0 and b >=0 and a + b > 0
    print("gcd({}, {})=").format(a,b)
    return recGcd(b, a % b) if b > 0 else a

print(gcd(4098408,540804))
print(recGcd(7,540804))

