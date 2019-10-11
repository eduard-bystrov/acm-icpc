#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <functional>
 
#define all(x) (x).begin(), (x).end()
#define ALL(x) (x).begin(), (x).end()
 
#define int long long
 
using namespace std;
 
int n, m;
map<pair<int, int>, int> ids;
set<int> ans;
struct Node
{
	int in, lowLink;
	vector<int> e;
};
 
vector<Node> g;
 
void In()
{
	cin >> n >> m;
	g.assign(n, Node());
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		--a; --b;
		g[a].e.push_back(b);
		g[b].e.push_back(a);
 
		ids[{a, b}] = i;
		ids[{b, a}] = i;
	}
}
 
int TIME = 0;
void DFS_T(int v, int p)
{
	g[v].in = g[v].lowLink = ++TIME;
 
	for (int i = 0; i < g[v].e.size(); ++i)
	{
		int to = g[v].e[i];
 
		if (to == p) continue;
 
		if (g[to].in == 0)
		{
			DFS_T(to, v);
			g[v].lowLink = min(g[v].lowLink, g[to].lowLink);
 
			if (g[v].in < g[to].lowLink)
			{
				ans.insert(ids[{v, to}]);
			}
		}
		else
		{
			g[v].lowLink = min(g[v].lowLink, g[to].in);
		}
	}
}
 
void Solve()
{
	for (int i = 0; i < n; ++i)
	{
		if (g[i].in == 0)
		{
			DFS_T(i, -1);
		}
	}
 
	cout << ans.size() << endl;
	for (const auto& it : ans)
	{
		cout << it + 1 << " ";
	}
	cout << endl;
}
 
 
signed main()
{
#ifdef _DEBUG
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
	freopen("bridges.in", "r", stdin);
	freopen("bridges.out", "w", stdout);
#endif // _DEBUG
 
	//srand(NULL);
 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin.tie(NULL);
 
	In();
	Solve();
	
	return 0;
}
