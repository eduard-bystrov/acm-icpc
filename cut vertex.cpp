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
#include <conio.h>
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
typedef array<int64, 2> hv;

int TIME = 0;

struct Node
{
	int in = 0;
	int lowLink = 0;
	bool inStack = false;
	vector<int> e;
};
map<pair<int, int>, int> ma;
set<int> ans;
vector<Node> g;
vector<int> st;
void DFS_T(int f,int p)
{
	g[f].in = g[f].lowLink = ++TIME;
	g[f].inStack = true;
	st.push_back(f);
	int child = 0;
	for (auto& t : g[f].e)
	{
		if (t == p) continue;
		if (g[t].in == 0)
		{
			child++;
			DFS_T(t, f);
			g[f].lowLink = min(g[f].lowLink, g[t].lowLink);
			if (g[t].lowLink >= g[f].in && p != -1)
			{
				ans.insert(f);
			}
		}
		else if (g[f].inStack)
		{
			g[f].lowLink = min(g[f].lowLink, g[t].in);
		}
	}


	if (g[f].lowLink == g[f].in)
	{
		int x;
		do
		{
			x = st.back(); st.pop_back();
			g[x].inStack = false;
		} while (x != f);
	}

	if (child > 1 && p == -1) ans.insert(f);
}

int main()
{
#ifdef _DEBUG
	freopen("ReadMe.txt", "r", stdin);
	//freopen("123.txt", "w", stdout);
	//test();
#else
	{

		freopen("points.in", "r", stdin);
		freopen("points.out", "w", stdout);
	}
#endif
	//srand(time(NULL));
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	g.assign(n, Node());

	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		--a; --b;
		g[a].e.push_back(b);
		g[b].e.push_back(a);
		ma[{a, b}] = i+1;
		ma[{b, a}] = i + 1;
	}

	for (int i = 0; i < n; ++i)
	{
		if (g[i].in == 0)
		{
			DFS_T(i,-1);
		}
	}

	cout << ans.size() << endl;
	for (const auto& it : ans) cout << it + 1 << endl;

	return 0;
}