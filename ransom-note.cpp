#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'checkMagazine' function below.
 *
 * The function accepts following parameters:
 *  1. STRING_ARRAY magazine
 *  2. STRING_ARRAY note
 */

void checkMagazine(vector<string> magazine, vector<string> note)
{
	map<string, int> mp;

	for (string w : magazine)
	{
		if (mp[w] == 0)
		{
			mp[w] = 1;
		}
		else
		{
			mp[w]++;
		}
	}

	bool ok = true;
	for (string w : note)
	{
		if (mp[w] == 0)
		{
			ok = false;
			break;
		}
		else
		{
			mp[w]--;
		}
	}

	string verdict = ok ? "Yes" : "No";
	cout << verdict << endl;
}