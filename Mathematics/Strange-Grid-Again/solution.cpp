long strangeGrid(long r, long c)
{

	long ar, ac;

	ar = r - 1;
	ac = c - 1;

	long base = (ar / 2) * 10;

	// even
	if (ar % 2 == 0)
	{
		base += ac * 2;
	}
	else
	{
		base += 1 + (ac * 2);
	}

	return base;
}