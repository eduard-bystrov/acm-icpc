int ans = 0;

void diameterTree(int from,int p = -1)
{
	int mx1 = 0;
	int mx2 = 0;

	for (const int& it : zipGraph[from])
	{
		if (it == p) continue;
		diameterTree(it, from);

		int v = dp[it] + 1;
		mx2 = max(mx2, v);

		if (mx1 < mx2) swap(mx1, mx2);
	}

	dp[from] = mx1;

	ans = max(ans, mx1 + mx2);
}