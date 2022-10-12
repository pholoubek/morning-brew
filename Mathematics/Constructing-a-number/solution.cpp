string canConstruct(vector<int> a)
{
	// Return "Yes" or "No" denoting whether you can construct the required number.
	vector<int> arr;

	// first, we need to split all numbers into digits and store.
	// the order of the digits doesn't matter bcs addition is commutative!
	for (int d : a)
	{
		int t = d;
		while (t >= 10)
		{
			arr.push_back(t % 10);
			t /= 10;
		}

		arr.push_back(t);
	}

	// we sum all the digits
	int sumToCheck = 0;
	for (int d : arr)
	{
		sumToCheck += d;
	}

	// we test if the sum of the digits is divisble by 3 or not
	return sumToCheck % 3 == 0 ? "Yes" : "No";
}
