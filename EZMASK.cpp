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

const double PI = acos(-1.0);

const int INF = 1e9;


bool isCurrent(const vector<int>& team, const vector<vector<bool>>& adj)
{
	forn(i, team.size())
	{
		for (int j = i + 1; j < team.size(); ++j)
		{
			int u = team[i];
			int v = team[j];

			if (adj[u][v] || adj[v][u])
			{
				return false;
			}
		}
	}

	return true;
}

void ConvertMaskToIds(int mask, vector<int>& team)
{
	int id = 0;
	while (mask)
	{
		if (mask & 1)
		{
			team.push_back(id);
		}
		++id;
		mask >>= 1;
	}
}

int main()
{
#ifdef _DEBUG
	freopen("ReadMe.txt", "r", stdin);
	//test();
#endif

	int n, m;

	cin >> n >> m;


	map<string, int> persons;
	map<int, string> ids;

	forn(i, n)
	{
		string str;
		cin >> str;

		persons.insert(make_pair(str, i));
		ids.emplace(i, str);
	}

	vector<vector<bool> > adj(n, vector<bool>(n));

	forn(i, m)
	{
		string f, s;
		cin >> f >> s;

		int fnum = persons[f];
		int snum = persons[s];

		adj[fnum][snum] = 1;
		adj[snum][fnum] = 1;
	}


	int MAX_MASK = 1 << n;
	
	vector<int> bestTeam;

	for (int mask = 0; mask < MAX_MASK; ++mask)
	{
		vector<int> team;

		ConvertMaskToIds(mask, team);

		if (isCurrent(team, adj) && team.size() > bestTeam.size())
		{
			bestTeam = team;
		}

	}

	set<string> ans;

	for (int i = 0; i < bestTeam.size(); ++i)
	{
		ans.insert(ids[bestTeam[i]]);
	}

	cout << ans.size() << endl;

	for (set<string>::iterator it = ans.begin(); it != ans.end(); ++it)
	{
		cout << *it << endl;
	}
	

	return 0;

}