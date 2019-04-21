#include <string>
#include <iostream>
#include <cmath>
using namespace std;

/**
    Finds all prime numbers of the n number
*/

void findPrimes(int n) {
    // even composite number 
    while(n % 2 == 0) {
        cout << 2 << " ";
        n = n / 2;
    }
    //  we have odd num. either composite or prime
    //  the i = 3 is because the first prime num. of odd comp. num is strictly > 2; i += 2 to keep odd index
    int m = sqrt(n);
    for(int i = 3; i <= m; i = i + 2) {
        while(n % i == 0) {
            n = n / i;
            if(n != 1) {cout << n << " ";};
        }
    }
    if(n > 2) {
        cout << n << endl; 
    }
}

int main () {
    int n = 123456;
    findPrimes(n);
    return 0;
}
