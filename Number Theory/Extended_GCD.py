"""
Extended GCD
Lemma: If int d divides int a and int b and d = ax + by for int x and int y, then d = gcd(a,b).
Proof: 
    d is common divisor of a and b, hence d <= gcd(a,b).
    gcd(a,b) divides both a and b, hence it also divides d = ax + by. Thus, gcd(a,b) <= d. 

Small note here: notice that x or y is not neccessarily positive!

Derivation:
    Assume that d = gcd(b, a mod b) and that d = bp + (a mod b)q.
    Then d = bp + (a mod b)q
           = dp + (a - floor(a/b) * b)q >> note:  floor(a/b) * b is nothing else then just a count how many times did we substracted b from a
           = aq + b(p-floor(a/b)q)
"""

def extended_gcd(a, b):
  assert a >= b and b >= 0 and a + b > 0
  if b == 0:
    d, x, y = a, 1, 0
  else:
    (d, p, q) = extended_gcd(b, a % b)
    x = q
    y = p - q * (a // b)
  assert a % d == 0 and b % d == 0
  assert d == a * x + b * y
  return (d, x, y)

print(extended_gcd(849375975,4850498))
