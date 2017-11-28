#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

typedef long long int64;

int64 MID(int64 l, int64 r) { return (l + r) / 2; }
int64 LSON(int64 u) { return u * 2; }
int64 RSON(int64 u) { return u * 2 + 1; }

struct SegmentTree
{
	SegmentTree(int64 size) : sum(size * 4) {}

	void Set(int64 u, int64 sl, int64 sr, int64 pos, int64 val)
	{
		if (sl == sr)
		{
			sum[u] = val;
			return;
		}

		int64 mid = MID(sl, sr);
		if (pos <= mid) Set(LSON(u), sl, mid, pos, val);
		else Set(RSON(u), mid + 1, sr, pos, val);

		sum[u] = sum[LSON(u)] + sum[RSON(u)];
	}

	int64 GetSum(int64 u, int64 sl, int64 sr, int64 l, int64 r)
	{
		if (sl == l && sr == r) return sum[u];

		int64 mid = MID(sl, sr);

		if (r <= mid) return GetSum(LSON(u), sl, mid, l, r);
		else if (l > mid) return GetSum(RSON(u), mid + 1, sr, l, r);
		else
		{
			return GetSum(LSON(u), sl, mid, l, mid) +
				GetSum(RSON(u), mid + 1, sr, mid + 1, r);
		}
	}

	vector<int64> sum;
};


int main()
{
	freopen("sum.in", "r", stdin);
	freopen("sum.out", "w", stdout);

	int64 n, m;
	cin >> n >> m;

	SegmentTree tree(n);

	for (int64 q = 0; q < m; ++q)
	{
		char c;
		int64 a, b;
		cin >> c >>  a >> b;


		if (c == 'Q') cout << tree.GetSum(1, 0, n - 1, a - 1, b - 1) << endl;
		else tree.Set(1, 0, n - 1, a - 1, b);
	}

	return 0;
}