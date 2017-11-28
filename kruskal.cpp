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

using namespace std;

typedef long long int64;
typedef vector<int64> VI;
typedef pair<int64, int64> PII;

#define forn(i, n) for (int64 i = 0; i < int64(n); i++)
#define nfor(i, n) for (int64 i = int64(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int64 i = int64(l); i < int64(r); i++)
#define all(a) (a).begin(), (a).end()
#define mp(x, y) make_pair((x), (y))
#define sqr(a) ((a) * (a))
#define sz(a) int64(a.size())

void NO()
{
	cout << "Impossible";
	exit(0);
}

void YES()
{
	cout << "FHTAGN!";
	exit(0);
}

const double PI = acos(-1.0);

const int64 INF = 1e18;

struct Edge
{
	Edge(int a, int b, int c)
		: v(a),u(b),cost(c)
	{

	}

	int v;
	int u;
	int cost;

	bool operator<(const Edge& obj) const
	{
		return cost < obj.cost;
	}
};

int m, n;

vector<Edge> edges;

vector<int> p;

int64 ans = 0;

int dsu_get(int v)
{
	return (v == p[v]) ? v : (p[v] = dsu_get(p[v]));
}

void dsu_unite(int v, int u)
{
	if (rand() & 1) swap(v, u);

	if (v != u) p[v] = u;
}



map<int, int> ids;

int id = 0;

int main()
{
#ifdef _DEBUG
	freopen("ReadMe.txt", "r", stdin);
	//test();
#endif

	cin >> n >> m;

	p.assign(n, 0);

	forn (i, n) p[i] = i;

	forn(i, m)
	{
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		
		if (ids.find(a) == ids.end())
		{
			ids.insert(make_pair(a, ids.size()));
		}

		if (ids.find(b) == ids.end())
		{
			ids.insert(make_pair(b, ids.size()));
		}

		edges.push_back(Edge(a, b, c));
	}

	sort(all(edges));

	forn(i, m)
	{
		int v = ids.find(edges[i].v)->second;
		int u = ids.find(edges[i].u)->second;
		int cost = edges[i].cost;


		if (dsu_get(v) != dsu_get(u))
		{
			ans += cost;
			dsu_unite(dsu_get(v), dsu_get(u));
		}
	}

	cout << ans;

	return 0;

}