#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	/*
		Medium  diff .cpp problem. Most likely there's better solution but
		it's a refresher for me.
	*/

	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	string word = "";
	vector<string> changes;

	string Q;
	getline(cin, Q);
	int opNum = stoi(Q);

	for (int i = 0; i < opNum; i++)
	{
		string ops;
		getline(cin, ops);

		int end = ops.find(" ");
		int op = stoi(ops.substr(0, end));
		string op2 = ops.substr(end + 1, ops.length());

		switch (op)
		{
		case 1:
			changes.push_back(word);
			word += ops.substr(end + 1, ops.length());
			break;
		case 2:
			changes.push_back(word);
			word = word.substr(0, word.length() - stoi(op2));
			break;
		case 3:
			cout << word[stoi(op2) - 1] << endl;
			break;
		case 4:
			word = changes[changes.size() - 1];
			changes.pop_back();
			break;
		}
	}
	return 0;
}