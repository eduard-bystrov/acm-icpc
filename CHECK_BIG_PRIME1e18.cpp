#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll pows[70];
const ll INF = 1e10 + 89;
void fil() {
    pows[0] = 1ll;
    for (int i = 1; i <= 63; ++i)
        pows[i] = pows[i - 1] * 2ll;
}
ll mul_mod(ll a, ll b, ll mod) {
    ll res = 0;
    while (b) {
        if (b & 1)
            res = (res + a) % mod;
        a = (a * 2ll) % mod;
        b >>= 1;
    }
    return res;
}
ll powm(ll p, ll n, ll mod) {
    ll res = 1;
    while (n) {
        if (n & 1)
            res = mul_mod(res, p, mod);
        p = mul_mod(p, p, mod);
        n >>= 1;
    }
    return res;
}
bool mrt(ll p) {
    if (p == 1)
        return false;
    ll s = 0, d = p - 1;
    while (!(d & 1)) {
        d = d / 2;
        s++;
    }
    srand(time(NULL)); /// Генерируем действительно случайные и разные a
    for (int i = 1; i <= 5; ++i) { /// Те самые 5 проверок
        ll a = rand() % p;
        if (a == 0)
            a++;
        bool flag1 = false, flag2 = false;
        if (powm(a % p, d, p) == 1) /// Первая проверка
            flag1 = true;
        if (!flag1)
            for (int r = 0; r < s; ++r) /// Вторая проверка
                if (powm(a % p, pows[r] * d, p) == p - 1)
                    flag2 = true;
        if (!flag1 && !flag2)
                return false;
    }
    return true;
}
 
int main() {
    ll m, n;
    fil();
    cin >> m;
    if (mrt(m))
        cout << "YES" << '\n';
    else
        cout << "NO";
}