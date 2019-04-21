#include <string>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

//  Sieve's method for finding prime numbers up to Nth number
//  Running Complexity O(sqrt(n)*nlog(log(n)) + O(n)

void sieve (int n) {
    //  holds prime dict.
    //  assume the seq. up to n is prime
    vector<bool> vs (n + 1, true);
    vs[0] = false;
    vs[1] = false;
    
    // Proof: Let m = sqrt(n), then n = m * m. Assume that n is not prime. Then n can be written as n = a * b. Note that
    // m is element of R and a,b,n are elements of N. Now we can write a * b = m * m. Next, we have 3 scenarios:
    // 1) a > m && b < m
    // 2) a = m && b = m
    // 3) a < m && b > m
    // Thus, we have this inequality: min(a,b) <= m. Thus we're bound to find either a or b up to the sqrt(n).
    
    int m = sqrt(n);
    for(size_t i = 2; i <= m; i++) {  //  O(sqrt(n))
        if(vs[i] == true) {
            for(size_t k = i * i; k <= n; k += i) {  // sum(1/i) = n * sum(1/i), and since sum(1/i) = log(log(n)). Thus O(n+log(log(n)))   
                vs[k] = false;
            }
        }
    } 
    int prime = 0;
    for(bool i : vs) {
        if(i == true) { cout << prime << " "; }
        ++prime;
    }
    cout << endl;  
}

int main () {
    int n = 1913;
    sieve(n);
    return 0;

}
