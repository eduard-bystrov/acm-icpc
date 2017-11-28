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
#include <bitset>0
#include <assert.h>
#include <conio.h>
#include <sstream>
#include <fstream>
#include <cstring>

using namespace std;

#define forn(i, k) for (int64 i = 0; i < int64(k); i++)
#define nfor(i, k) for (int64 i = int64(k) - 1; i >= 0; i--)
#define fore(i, l, r) for (int64 i = int64(l); i < int64(r); i++)
#define all(cd) (cd).begin(), (cd).end()
#define mp(x, y) make_pair((x), (y))
#define sqr(cd) ((cd) * (cd))

template <typename T> void alert(const T& t) { cout << t; exit(0); }

typedef long long int64;
typedef unsigned long long uint64;

const int A = 26;
const int ROOT = 1;
int E = 2;

struct Node
{
	int p = -1;
	int next[A] = { 0 };
	int end = 0;
	int c = 0;
	int lnk = 0;
};

const int N = 5 * 1e5;

Node bor[N];


void AddWord(const string& str)
{
	int cur = ROOT;

	for (int i = 0; i < str.size(); ++i)
	{
		int c = str[i] - 'a';

		if (!bor[cur].next[c])
		{
			bor[cur].next[c] = E++;
			bor[E - 1].p = cur;
			bor[E - 1].c = c;
		}

		cur = bor[cur].next[c];

	}

	bor[cur].end = str.size();
}

void BLinks()
{
	queue<int> q;
	q.push(ROOT);

	while (!q.empty())
	{
		int u = q.front(); q.pop();
		int c = bor[u].c;

		int w = (bor[u].p ? bor[bor[u].p].lnk : 0);

		while (w && !bor[w].next[c]) w = bor[w].lnk;

		if (w && bor[w].next[c])
		{
			bor[u].lnk = bor[w].next[c];
			bor[u].end = max(bor[bor[u].lnk].end, bor[u].end);
		}
		else if (u != ROOT) bor[u].lnk = ROOT;


		for (int i = 0; i < A; ++i)
		{
			if (bor[u].next[i]) q.push(bor[u].next[i]);
		}

	}
}


int main()
{
#ifdef _DEBUG
	freopen("ReadMe.txt", "r", stdin);
	//freopen("123.txt", "w", stdout);
	//test();
#else
	{

		//freopen("pluses.in", "r", stdin);
		//freopen("pluses.out", "w", stdout);
	}
#endif
	//srand(time(NULL));

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		reverse(all(s));
		AddWord(s);
	}

	BLinks();

	string t;
	cin >> t;
	reverse(all(t));

	int u = ROOT;

	vector<int> ans;

	for (int i = 0; i < t.size(); ++i)
	{
		int c = t[i] - 'a';

		while (u && !bor[u].next[c]) u = bor[u].lnk;

		if (u && bor[u].next[c]) u = bor[u].next[c];
		else u = ROOT;

		if (bor[u].end) ans.push_back(t.size()-i);

	}

	reverse(all(ans));

	cout << ans.size() << endl;

	for (auto& it : ans) cout << it << ' ';


	return 0;
}