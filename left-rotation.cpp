#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'rotLeft' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER d
 */

vector<int> slicing(const vector<int> &a, int x, int y)
{
	/*
		Aux function to abstract logic behind slicing arrays
	**/
	auto start = a.begin() + x;
	auto end = a.begin() + y;

	vector<int> result(y - x);
	copy(start, end, result.begin());

	return result;
}

vector<int> rotLeft(vector<int> a, int d)
{
	vector<int> temp;
	vector<int> base;

	temp = slicing(a, 0, d);
	base = slicing(a, d, a.size());

	for (size_t i = 0; i < temp.size(); i++)
	{
		base.push_back(temp[i]);
	}

	return base;
}