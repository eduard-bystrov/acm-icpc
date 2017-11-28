//http://codeforces.com/gym/101252/problem/D

//2009-2010 ACM-ICPC, NEERC, Южный четвертьфинал D ЗАДАЧА

//https://ru.wikipedia.org/wiki/%D0%97%D0%B0%D0%B4%D0%B0%D1%87%D0%B0_%D0%BD%D0%B0%D1%85%D0%BE%D0%B6%D0%B4%D0%B5%D0%BD%D0%B8%D1%8F_%D1%86%D0%B8%D0%BA%D0%BB%D0%B0


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
typedef array<int64, 2> hv;

int64 a, b, c;

int64 f(int64 x)
{
	return (a*x + x%b) % c;
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
		//freopen("ReadMe.txt", "r", stdin);
	}
#endif
	//srand(time(NULL));

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> a >> b >> c;

	int64 x0 = 1;
	int64 tortoise = f(x0);
	int64 hare = f(f(x0));

	for (int64 i = 0; i < 2e7; ++i)
	{
		if (tortoise == hare)
		{
			int64 len = 0;
			tortoise = x0;

			while (tortoise != hare)
			{
				tortoise = f(tortoise);
				hare = f(hare);
				len++;
			}

			int64 lam = 1;
			hare = f(tortoise);
			while (tortoise != hare)
			{
				hare = f(hare);
				lam += 1;
			}
			

			alert(lam+len);
		}
		else
		{
			tortoise = f(tortoise);
			hare = f(f(hare));
		}
	}
	

	cout << -1 << endl;

	return 0;
}
