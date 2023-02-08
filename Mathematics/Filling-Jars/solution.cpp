long long solve(long long n, vector<vector<int>> operations)
{
	long long sum = 0;
	// this will give us another vector with a,b and k
	// where a, b are the indices startin from 1 to jars.size() inclusive
	for (size_t i = 0; i < operations.size(); i++)
	{
		vector<int> ops = operations[i];
		long long s, e, j, sz;

		s = ops[0];
		e = ops[1];
		j = ops[2];

		sum += (e - s + 1) * j;
	}

	return sum / n;
}