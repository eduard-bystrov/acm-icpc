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

#define mp(x,y)  make_pair((x),(y))
#define pb(x)  push_back(x)


template <typename T>
class SegmentTree
{
private:
	int nMax;      //maximum number of elements in the array
	T* a;          // segment tree as array
				   // a[i] has 2 sons: left - a[2*i], right - a[2*i+1]
	T(*f)(T, T);   //function:  a[i]= f(a[2*i],a[2*i+1])
				   //by default:   f(x,y)= x+y
	T zero;        //zero value
				   //by default:   zero = 0


				   //constructors:
public:
	SegmentTree()//+
	{//empty constructor.     !!!! never use it
		nMax = 0;
		a = NULL;
		f = NULL;
		zero = T();
	}


	SegmentTree(int n)//+
	{//constructor for tree with not more than n (nMax) elements
		zero = T();
		f = &_F;
		initialization(n);
	}

	SegmentTree(int n, T zero0)//+
	{//constructor for tree with not more than n (nMax) elements and zero value zero0
		zero = zero0;
		f = &_F;
		initialization(n);
	}


	SegmentTree(int n, T* b)//+
	{//constructor for array b with n elements
		zero = T();
		f = &_F;
		initialization(n);
		leafsFill(n, b);
		build();
	}

	SegmentTree(int n, T* b, T zero0)//+
	{//constructor for array b with n elements and zero value zero0
		zero = zero0;
		f = &_F;
		initialization(n);
		leafsFill(n, b);
		build();
	}


	SegmentTree(int n, T(*F)(T, T))//+
	{//constructor for tree with not more than n (nMax) elements, function - F
		zero = T();
		f = F;
		initialization(n);
	}

	SegmentTree(int n, T(*F)(T, T), T zero0)//+
	{//constructor for tree with not more than n (nMax) elements, function - F, and zero value zero0
		zero = zero0;
		f = F;
		initialization(n);
	}


	SegmentTree(int n, T* b, T(*F)(T, T))//+
	{//constructor for array b with n elements, function - F
		zero = T();
		f = F;
		initialization(n);
		leafsFill(n, b);
		build();
	}

	SegmentTree(int n, T* b, T(*F)(T, T), T zero0)//+
	{//constructor for array b with n elements, function - F
		zero = zero0;
		f = F;
		initialization(n);
		leafsFill(n, b);
		build();
	}



	//main methods:
public:
	void update(int i, T value)//+
	{ // change value of element with index i to "value"
		if (i >= nMax) return; //incorrect value
		a[nMax + i] = value;
		refresh(nMax + i);
	}

	T value(int i)//+
	{// return value of element with index i
		if (i >= nMax) return T(); //incorrect value
		return a[nMax + i];
	}

	T query(int l, int r)//+
	{// return value function f on the segment [l;r]
		return query(max(l, 0), min(r, nMax - 1), 0, nMax - 1, 1);
	}

	void clear()//+
	{// clear segment tree. set zero value for all elements in the tree
		arrayFillZero();
	}



private:
	void initialization(int n)//+
	{// initializes nMax and a
	 // n - number of elements in the array
	 // calculate nMax
	 // and create array for segment tree
		nMax = 1;
		while (nMax<n) nMax <<= 1;

		a = new T[nMax * 2];
		arrayFillZero();
	}

	void arrayFillZero()//+
	{// set zero value for all elements in the array
		for (int i = 2 * nMax - 1; i >= 0; i--)
			a[i] = zero;
	}

	void leafsFill(int n, T* b)//+
	{ // array b from n elements copping to the leafs
		for (int i = 0; i<n; i++)
			a[nMax + i] = b[i];
	}



	static T _F(T _a, T _b)//+
	{// default value of function f
		return _a + _b;
	}

	void build()//+
	{// build segment tree from leafs
		for (int i = nMax - 1; i>0; i--)
			a[i] = f(a[2 * i], a[2 * i + 1]);
	}

	void refresh(int i)//+
	{// calculate new values for parents
	 // i - leaf
		while (i>1)
		{
			i /= 2;
			a[i] = f(a[2 * i], a[2 * i + 1]);
		}
	}

	T query(int l, int r, int leftPosition, int rightPosition, int v) //+
	{// return value function f on the intersection segments [l;r] and [leftPosition;rightPosition]
	 // l - left side of segment
	 // r - right side of segment
	 // v - vertex of segment tree
	 // [leftPosition; rightPosition] - segment that corresponds v
		if (r<l) return zero;
		if (l == leftPosition && r == rightPosition) return a[v];
		int middle = (leftPosition + rightPosition) / 2;

		return f(query(l, min(middle, r), leftPosition, middle, v * 2), query(max(l, middle + 1), r, middle + 1, rightPosition, v * 2 + 1));
	}

	void print() //for debug
	{//print tree to the output
		for (int i = 1; i<nMax; i++)
			cout << a[i] << " ";
		cout << endl << endl;
		for (int i = 0; i<nMax; i++)
			cout << a[nMax + i] << " ";
		cout << endl;
	}
};



int funct(int a, int b)
{
	return max(a, b);
}

typedef pair<int, int> pii;

int gcd(int a, int b)
{
	if (a == 0) return b;
	return gcd(b%a, a);
}


const int MaxN = 5 * 100 * 1000;
int a[MaxN + 5];


int main()
{
#ifdef _DEBUG
	freopen("ReadMe.txt", "r", stdin);
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

	int n, q;
	cin >> n;
	for (int i = 0; i<n; i++)
		cin >> a[i];
	cin >> q;

	SegmentTree<int> st(n, a, gcd);
	char c;
	int l, r;
	int i, d;

	for (int Q = 0; Q<q; Q++)
	{
		cin >> c;
		if (c == '1')
		{
			cin >> l >> r;
			int64 inpect;
			cin >> inpect;
			cout << gcd(st.query(l - 1, r - 1),inpect) << endl;
		}
		else
		{ //c== '2'
			cin >> i >> d;
			st.update(i - 1, d);
		}
	}
	

	return 0;
}
