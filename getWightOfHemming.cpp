int getWightOfHemming(int number) // кол-во 1 в 2ом 
{
	int ans = 0;
	while (number != 0)
	{
		ans += number % 2;
		number /= 2;
	}
	//cout << ans;
	return ans;
}
