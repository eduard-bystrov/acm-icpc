struct SingleHash
{
	vector<int64> suf, b;
	int64 mod;
 
	SingleHash(string s, int64 base = 630911, int64 _mod = 933494437)

//int64 base = 20147, int64 _mod = 933494437)
	{
		int n = s.length();
		suf.assign(n + 1, 0); // suf[n] = 0
		b.assign(n + 1, 0);
		b[0] = 1;
		b[1] = base;
		mod = _mod;
		for (int i = n - 1; i >= 0; --i) {
			suf[i] = (s[i] + suf[i + 1] * b[1]) % mod;
		}
		for (int i = 2; i <= n; ++i) {
			b[i] = (b[i - 1] * b[1])%mod;
		}
	}
 
	int64 substr(int l, int len) const
	{
		int r = l + len;
		int64 v = (suf[l] - (suf[r] * b[r - l])%mod)%mod;
		v %= mod;
		v += mod;
		v %= mod;
 
		return v;
	}
};