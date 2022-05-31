#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'summingSeries' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts LONG_INTEGER n as parameter.
 */

int Q = pow(10, 9) + 7;

/**
	T_n = n^2 - (n-1)^2
	... n^2 - ((n-1)*(n-1))
	... n^2 - (n^2 - n - n + 1)
	... n^2 - n^2 + 2n - 1
	... 2n - 1 -> is the T_n sum

	then we can see that sum(T_n) = 1 + 3 + 5 + ... + 2n - 1 = (2n - 1 + 1) * (n / 2) OR just sum(T_n) = n ^ 2;
	this is just arit summation of odd numbers here simplified...
*/

int summingSeries(long n)
{
	// % arith states (a%Q) * (b%Q) * Q = (ab%Q)
	// here we had an issue with outright n^2 % Q even for unsigned long ....
	return (n % Q) * (n % Q) % Q;
}
