#include<bits/stdc++.h>
 
using namespace std;
 
#define REP(i, a, b) for ( int i = (a), _end_ = (b); i <= _end_; ++ i ) 
#define mem(a) memset ( (a), 0, sizeof(a) ) 
#define str(a) strlen ( a ) 
#define pii pair<int, int>
 
const int maxn = 10010;
const int Mod = 998244353;
 
int n, m, a[maxn], b[maxn], fac[maxn], inv[maxn], ans, f[maxn], F[maxn], G[maxn];
 
inline int power(int a, int b) { int r = 1; while ( b ) { if ( b & 1 ) r = 1ll * r * a % Mod; a = 1ll * a * a % Mod; b >>= 1; } return r; } 
inline int C(int n, int m) { return n < m ? 0 : 1ll * fac[n] * inv[m] % Mod * inv[n - m] % Mod; }
 
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    n = maxn - 10; fac[0] = inv[0] = 1; REP(i, 1, n) fac[i] = 1ll * fac[i - 1] * i % Mod;
    inv[n] = power(fac[n], Mod - 2); for ( int i = n - 1; i >= 1; -- i ) inv[i] = 1ll * inv[i + 1] * (i + 1) % Mod;
    scanf("%d%d", &n, &m);
    REP(i, 1, m) scanf("%d", &a[i]);
    sort(a + 1, a + m + 1);
    while ( n -- ) 
    {
        int op; scanf("%d", &op); REP(i, 1, m) scanf("%d", &b[i]); sort(b + 1, b + m + 1);
 
        if ( op == 1 ) 
        {
            int l = 1, r = m, ans = 0;
            for ( int i = m; i >= 1; -- i ) 
                if ( a[r] > b[i] ) { -- r; ++ ans; } 
                else ++ l;
            if ( ans >= (m + 1) / 2 ) puts("1");
            else puts("0");
            continue ; 
        }
 
        REP(i, 1, m) b[i] = lower_bound(a + 1, a + m + 1, b[i]) - a;
         
        f[0] = 1; REP(i, 1, m) f[i] = 0;
        REP(i, 1, m)
        {
            int x = m - b[m - i + 1] + 1;
            for ( int j = x; j >= 1; -- j ) f[j] = (f[j] + 1ll * f[j - 1] * (x - j + 1)) % Mod;
        }
        REP(i, 0, m) F[i] = 1ll * f[i] * fac[m - i] % Mod;      
        for ( int i = m; i >= 0; -- i ) 
        {
            int ret = 0;
            REP(j, i + 1, m) ret = (ret + 1ll * C(j, i) * G[j]) % Mod;
            G[i] = (F[i] - ret) % Mod;
        }
        // REP(i, 0, m) printf("%lld ", F[i]); puts("");
        // REP(i, 0, m) printf("%lld ", G[i]); puts("");
        int ans = 0; REP(i, (m + 1) / 2, m) ans = (ans + G[i]) % Mod;
        ans = 1ll * ans * inv[m] % Mod;
        printf("%lld\n", (ans + Mod) % Mod);
    }
    return 0;
}
