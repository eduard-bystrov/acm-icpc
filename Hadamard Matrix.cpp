// http://codeforces.com/problemset/problem/610/C

//Матрицы формируются след. образом. Есть матрица H2
//1 1
//1 -1
//Из нее можно получить матрицу H4 умножив каждый эл-т этой матрицы на H2
//H2 H2
//H2 -H2
//То есть H4:
//1 1 1 1
//1 -1 1 -1
//1 1 -1 -1
//1 -1 -1 1
//H8 получается умножением каждого элемента на H2 итд...

#include <iostream>
#include <cmath>
typedef long long int64;
using namespace std;

int getWightOfHemming(int number)
{
	int ans = 0;
	while (number != 0)
	{
		ans += number % 2;
		number /= 2;
	}
	//cout << ans;
	return ans;
}

void HadamardMatrix(int n)
{
	for (int i = 0; i < pow(2.0,n); ++i)
	{
		for (int j = 0; j < pow(2.0, n); ++j)
		{
			if (getWightOfHemming((j&i))%2 == 0) cout << "+"; // * = -1 ; + = 1;
			else cout << "*";
		}
		cout << endl;
	}
}


int main()
{
#ifdef _DEBUG
	freopen("ReadMe.txt", "r", stdin);
#endif

	int n;

	cin >> n;

	HadamardMatrix(n);

	return 0;
}

