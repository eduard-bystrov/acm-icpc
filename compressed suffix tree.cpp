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

using namespace std;

#define all(cd) (cd).begin(), (cd).end()

template <typename T> void alert(const T& t) { cout << t; exit(0); }

typedef long long int64;
typedef unsigned long long uint64;

string s;
int n = 0;
const int ROOT = 1;

struct Node
{
	int p, l, r;
	map<char, int,greater<char>> nxt;
	int lnk;
	int id = -1;

	Node(int p = 0, int l = 0, int r = 0) : p(p), l(l), r(r), lnk(0) {};

	int Len() const
	{
		return r - l;
	}
};


vector<Node> t;

int Add(int p, int l, int r)
{
	t.push_back(Node(p, l, r));
	int k = t.size()-1;
	t[p].nxt[s[l]] = k;

	return k;
}

struct Pos
{
	int v, up;
	Pos(int v, int up) : v(v), up(up) {};
};

Pos GO(Pos e, char c)
{
	if (e.up == 0) return (t[e.v].nxt.count(c) ? Pos(t[e.v].nxt[c], t[t[e.v].nxt[c]].Len() - 1) : Pos(0, 0));

	return c == s[t[e.v].r - e.up] ? Pos(e.v, e.up - 1) : Pos(0, 0);
}


int Split(Pos e)
{
	if (e.up == 0) return e.v;

	int p = t[e.v].p;

	if (e.up == t[e.v].Len()) return p;

	int c = Add(p, t[e.v].l, t[e.v].r - e.up);

	t[e.v].p = c;
	t[e.v].l = t[e.v].r - e.up;
	t[c].nxt[s[t[e.v].l]] = e.v;

	return c;
}


Pos Jump(int u, int l, int r)
{
	if (l == r) return Pos(u, 0);

	while (true)
	{
		u = t[u].nxt[s[l]];

		if (t[u].Len() >= r - l) return Pos(u, t[u].Len() - r + l);
		else l += t[u].Len();
	}
}


int Lnk(int u)
{
	if (!t[u].lnk)
	{
		t[u].lnk = Split(Jump(Lnk(t[u].p), t[u].l + (t[u].p == ROOT ? 1 : 0), t[u].r));
	}

	return t[u].lnk;
}

Pos Expond(Pos e, int i)
{
	while (true)
	{
		Pos ne = GO(e, s[i]);

		if (ne.v) return ne;

		int u = Split(e);
		Add(u, i, n);

		e = Pos(Lnk(u), 0);

		if (u == ROOT) return e;
	}
}


map<int, pair<int, pair<int,int>>> ma;

int64 res = 0;

int64 number = 0;

int ID = 0;

void DFS(int from)
{
	t[from].id = ID++;

	for (auto it = t[from].nxt.rbegin(); it != t[from].nxt.rend();++it)
	{
		DFS(it->second);
	}
}

vector < pair<int, pair<int, int>>> ans;

void DFSMake(int from)
{
	if (t[from].id > 0)
	{
		ans[t[from].id] = { t[t[from].p].id,{t[from].l,t[from].r} };
	}

	for (const auto& it : t[from].nxt)
	{
		DFSMake(it.second);
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
	
	int64 k;
	cin >> k;
	cin >> s;


	n = s.size();
	t.assign(2, Node());
	t.reserve(1e6);
	t[ROOT].lnk = ROOT;

	Pos e(ROOT, 0);


	for (int i = 0; i < s.size(); ++i)
	{
		e = Expond(e, i);
	}


	cout << t.size() - 1 << endl;


	return 0;
}