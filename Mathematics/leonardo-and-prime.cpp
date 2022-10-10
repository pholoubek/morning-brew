#include <bits/stdc++.h>

using namespace std;

vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

int primeCount(long n)
{
	/*
		counts the maximum number of distinct prime factors of any number in the inclusive range [1,n]
		Difficulty: easy
		Comment: solution was obvious immediately but the issue came from data type.. some prod were overflowing.
	*/

	int idx, count = 0;
	unsigned long prod = primes[idx];
	while (prod <= n)
	{
		prod *= primes[idx + 1];
		idx++;
		count++;
	}

	return count;
}