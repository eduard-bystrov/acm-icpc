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
 
template <typename T> void alert(const T& t) { cout << t; exit(0); }
 
typedef long long int64;
typedef unsigned long long uint64;
typedef array<int64, 2> hv;
 
 
 
struct Node
{
	int pre = 0;
	int lowlink = 0;
	int cycle = 0;
	vector<int> idEdges;
};
 
vector<Node> graph;
 
struct Edge
{
	Edge(int v, int u) : u(u), v(v) {}
	int u, v;
	int used = false;
 
};
 
int n, m;
vector<Edge> edges;
 
void AddEdge(int v,int u)
{
	edges.push_back(Edge(v, u));
	graph[v].idEdges.push_back(edges.size() - 1);
}
 
 
vector<int> stackT;
int TIMER = 0;
int CYCLE = 0;
void DFS_TARJAN(int v)
{
	graph[v].pre = graph[v].lowlink = ++TIMER;
	stackT.push_back(v);
 
	for (int i = 0; i < graph[v].idEdges.size(); ++i)
	{
		Edge& e = edges[graph[v].idEdges[i]];
		if (e.used) continue;
		edges[graph[v].idEdges[i] ^ 1].used ^= 1;//ÏÅÐÅÊËÞ×ÀÅÌ ÕÎÁÀ
		if (!graph[e.u].pre)
		{
			DFS_TARJAN(e.u);
			graph[v].lowlink = min(graph[v].lowlink, graph[e.u].lowlink);
		}
		else if (!graph[e.u].cycle)
		{
			graph[v].lowlink = min(graph[v].lowlink, graph[e.u].pre);
		}
	}
 
	if (graph[v].lowlink == graph[v].pre)
	{
		CYCLE++;
 
		for (;;)
		{
			int x = stackT.back(); stackT.pop_back();
			graph[x].cycle = CYCLE;
			if (x == v) break;
		}
	}
}
 
 
void FIND_FUCKING_CYCLES()
{
	for (int i = 0; i < n; ++i)
	{
		if (!graph[i].pre) DFS_TARJAN(i);
	}
}
 
vector<vector<int>> tree;
vector<int> dist;
 
void Init()
{
	cin >> n >> m;
 
	graph.assign(n, Node());
	tree.assign(n+1, vector<int>());
	dist.assign(n+1, 0);
 
	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		--u; --v;
		AddEdge(u, v);
		AddEdge(v, u);
	}
}
 
 
void BuildTree()
{
	for (const auto& e : edges)
	{
		if (e.used) continue;//DA ETO JESKA
		int u = graph[e.u].cycle;
		int v = graph[e.v].cycle;
		if (u != v)
		{
			tree[u].push_back(v);
			tree[v].push_back(u);
		}
	}
}
 
void TREE_DFS(int u, int h = 0, int p = -1)
{
	dist[u] = h;
	for (auto& e : tree[u])
	{
		if (e == p) continue;
		TREE_DFS(e, h + 1, u);
	}
}
 
int FindMax()
{
	int mx = 0;
	int id = 0;
	for (int i = 0; i < tree.size(); ++i)
	{
		if (mx < dist[i])
		{
			mx = dist[i];
			id = i;
		}
	}
 
	return id;
}
 
pair<int,int> LONG_PATH_IN_TREE()
{
	for (int i = 0; i < tree.size(); ++i)
	{
		if (dist[i] == 0) TREE_DFS(i);
	}
	int v = FindMax();
	TREE_DFS(v);
	int u = FindMax();
	return { v,u };
}
 
int main()
{
#ifdef _DEBUG
	freopen("ReadMe.txt", "r", stdin);
	//freopen("123.txt", "w", stdout);
	//test();
#else
	{
 
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
#endif
	//srand(time(NULL));
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 
	Init();
	FIND_FUCKING_CYCLES();
	BuildTree();
 
	pair<int,int> se = LONG_PATH_IN_TREE();
 
	pair<int, int> xD;
 
	for (int i = 0; i < n; ++i)
	{
		if (graph[i].cycle == se.first) xD.first = i;
		if (graph[i].cycle == se.second) xD.second = i;
	}
 
	cout << xD.first + 1 << " " << xD.second + 1 << endl;
 
	return 0;
 
}