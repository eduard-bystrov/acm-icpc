#include <iostream>
#include <cmath>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <set>
#include <math.h>
#include <map>
#include <iomanip>
#include <functional>
#include <list>
#include <random>
#include <queue>
#include <stdio.h>
#include <regex>
#include <bitset>
#include <numeric>
#include <bitset>
#include <assert.h>
#include <sstream>
#include <fstream>
#include <cstring>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <stack>

using namespace std;

#define all(cd) (cd).begin(), (cd).end()
#define sqr(cd) ((cd) * (cd))

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd

template <typename T> void alert(const T& t) { cout << t << endl; exit(0); }

typedef long long int64;
typedef unsigned long long uint64;
typedef array<uint64, 2> hv;

struct FT
{
	vector<int64> vec;
	FT(int n) : vec(n) {}

	void Update(int i, int64 val)
	{
		for (; i < vec.size(); i = (i | (i + 1)))
		{
			vec[i] += val;
		}		
	}

	int64 Sum(int r)
	{
		int res = 0;
		for (; r >= 0; r = (r & (r + 1)) - 1)
			res += vec[r];
		return res;
	}

	int64 Sum(int l, int r)
	{
		return Sum(r) - Sum(l - 1);
	}
};





int main()
{

#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	//freopen("123.txt", "w", stdout);
	//test();
#else
	{

		//freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
		//freopen("ReadMe.txt", "r", stdin);
	}
#endif
	//srand(time(NULL));

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<pair<int64, int64>> vec;
	map<int64, int64> ma;
	for (int i = 0; i < n; ++i)
	{
		int a;
		cin >> a;
		vec.push_back({ a,i });
		ma[a]++;
	}

	sort(all(vec),greater<pair<int64,int64>>());

	int64 ans = 0;
	
	FT tree(n);

	for(int i = 0;i < n;++i)
	{
		int f = vec[i].first;
		int s = vec[i].second;
		ans += (n - vec[i].second - 1) - tree.Sum(s,n-1);

		tree.Update(s, 1);
	}

	cout << ans << endl;

	return 0;
}
