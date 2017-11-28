// http://codeforces.com/problemset/problem/510/B
//
//
//
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e+9;

struct Node
{
	Node() : color('w') {}
	char c;
	char color;
	pair<int, int> prev;

};

int di[] = { -1,1,0,0 };
int dj[] = { 0,0,-1,1 };

int n, m;
vector<vector<Node>> graph;


bool CheckPos(pair<int, int> p)
{
	return p.first >= 0 && p.first < n && p.second >= 0 && p.second < m;
}


void DFS(pair<int,int> cur,int h)
{
	graph[cur.first][cur.second].color = 'g';

	for (int step = 0; step < 4; ++step)
	{
		pair<int, int> next(cur.first + di[step], cur.second + dj[step]);
		if (!CheckPos(next) || next == graph[cur.first][cur.second].prev) continue;

		graph[next.first][next.second].prev = cur;

		if (graph[next.first][next.second].color == 'w' && graph[next.first][next.second].c == graph[cur.first][cur.second].c)
		{
			++h;
			DFS(next,h);
		}
		else
		{
			if (graph[next.first][next.second].color == 'g' && graph[next.first][next.second].c == graph[cur.first][cur.second].c && h + 1 > 3)
			{
				cout << "Yes";
				exit(0);
			}
		}
	}
	graph[cur.first][cur.second].color = 'b';
}


int main()
{
#ifdef _DEBUG
	freopen("ReadMe.txt", "r", stdin);
#endif

	cin >> n >> m;
	graph.assign(n, vector<Node>(m));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> graph[i][j].c;
		}
	}
	
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (graph[i][j].color == 'w')
			{
				DFS(make_pair(i, j), 0);
			}
		}
	}


	cout << "No";

	return 0;
}

