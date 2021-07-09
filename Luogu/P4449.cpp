/***************************************************************
	File name: P4449.cpp
	Author: ljfcnyali
	Create time: 2019年09月06日 星期五 21时28分26秒
***************************************************************/
#include<bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for ( int i = (a), _end_ = (b); i <= _end_; ++ i ) 
#define mem(a) memset ( (a), 0, sizeof ( a ) ) 
#define str(a) strlen ( a ) 
#define int long long
typedef long long LL;

const int Mod = 1000000007;
const int maxn = 10000010;

int Max = 5000000, n, m, T, k;
int g[maxn], f[maxn], prime[maxn], tot;
bool vis[maxn];

inline int power(int a, int b)
{
    int r = 1;
    while ( b ) { if ( b & 1 ) r = (r * a) % Mod; a = (a * a) % Mod; b >>= 1; }
    return r;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%lld%lld", &T, &k);
    f[1] = 1;
    REP(i, 2, Max)
    {
        if ( !vis[i] ) { prime[++ tot] = i; g[i] = power(i, k); f[i] = (g[i] - 1 + Mod) % Mod; }
        for ( int j = 1; j <= tot && i * prime[j] <= Max; ++ j )
        {
            vis[i * prime[j]] = true;
            if ( i % prime[j] == 0 ) { f[i * prime[j]] = f[i] * g[prime[j]] % Mod; break ; }
            f[i * prime[j]] = f[i] * (g[prime[j]] - 1 + Mod) % Mod;
        }
    }
    REP(i, 1, Max) f[i] = (f[i - 1] + f[i]) % Mod;
    while ( T -- ) 
    {
        scanf("%lld%lld", &n, &m);
        int i = 1, ans = 0;
        while ( i <= min(n, m) )
        {
            int j = min(n / (n / i), m / (m / i));
            int sum = ((f[j] - f[i - 1]) % Mod + Mod) % Mod;
            int s = ((n / i) * (m / i)) % Mod;
            ans = (ans + ((sum * s) % Mod)) % Mod;
            i = j + 1;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
