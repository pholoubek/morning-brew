#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Waiter - Intermediate Problem.. again more of a refresher of c++ lang
 */

vector<int> waiter(vector<int> number, int q)
{
	vector<int> numbers = number;
	vector<int> not_prime_arr;
	vector<int> prime_arr;
	vector<int> answers;

	vector<int> primes;
	int count = 0;
	int num = 2;

	// we can use sieve method using construct on primes vector init
	// and to use the square root
	while (count != q)
	{					   // while count!= number of prime numbers entered keep searching..
		bool prime = true; // assume it's prime here...
		for (int i = 2; i <= sqrt(num); i++)
		{ // efficiency matters
			if (num % i == 0)
			{
				prime = false; // if number divides any other number its not a prime so set prime to false and break the loop.
				break;
			}
		}

		if (prime)
		{
			count++;
			primes.push_back(num);
		}
		num++;
	}

	int idx = 0;
	for (int i = 0; i < q; i++)
	{
		int prime = primes[idx];
		not_prime_arr.clear();

		for (int j = numbers.size() - 1; j >= 0; j--)
		{
			if (numbers[j] % prime == 0)
			{
				prime_arr.push_back(numbers[j]);
			}
			else
			{
				not_prime_arr.push_back(numbers[j]);
			}
		}

		while (!prime_arr.empty())
		{
			answers.push_back(prime_arr.back());
			prime_arr.pop_back();
		}

		numbers = not_prime_arr;
		idx++;
	}

	while (!numbers.empty())
	{
		answers.push_back(numbers.back());
		numbers.pop_back();
	}

	return answers;
}