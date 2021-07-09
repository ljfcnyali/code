/***************************************************************
	File name: w.cpp
	Author: ljfcnyali
	Create time: 2020年11月19日 星期四 10时07分26秒
***************************************************************/
#include<bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for ( int i = (a), _end_ = (b); i <= _end_; ++ i ) 
#define mem(a) memset ( (a), 0, sizeof ( a ) ) 
#define str(a) strlen ( a ) 
#define pii pair<int, int>
#define x first
#define y second
typedef long long LL;

const int maxn = 2e5 + 10;
const int INF = 1e9;

int n, m, Begin[maxn], Next[maxn], To[maxn], e, W[maxn];
pii f[maxn][2];

inline pii operator + (pii a, pii b) { return pii(a.x + b.x, a.y + b.y); }
inline pii min(pii a, pii b) 
{
    if ( a.x != b.x ) return a.x < b.x ? a : b;
    return a.y < b.y ? a : b;
}

inline void add(int u, int v, int w) { To[++ e] = v; Next[e] = Begin[u]; Begin[u] = e; W[e] = w; }

inline void DFS(int u, int fa)
{
    f[u][1] = pii(1, 0);
    for ( int i = Begin[u]; i; i = Next[i] ) 
    {
        int v = To[i]; if ( v == fa ) continue ;
        DFS(v, u);

        pii x = f[u][0], y = f[u][1];
        if ( W[i] == 0 ) { f[u][0] = x + f[v][0]; f[u][1] = y + f[v][0]; }
        if ( W[i] == 1 ) { f[u][0] = y + f[v][1] + pii(-1, 0); f[u][1] = x + f[v][1]; }
        if ( W[i] == -1 ) 
        {
            f[u][0] = x + f[v][0]; f[u][1] = y + f[v][0];
            f[u][0] = min(f[u][0], y + f[v][1] + pii(-1, 0));
            f[u][1] = min(f[u][1], x + f[v][1]);
        }
    }
    ++ f[u][1].y;
}

int main()
{
    freopen("w.in", "r", stdin);
    freopen("w.out", "w", stdout);
    scanf("%d", &n);
    REP(i, 1, n - 1)
    {
        int u, v, a, b; scanf("%d%d%d%d", &u, &v, &a, &b);
        if ( b == 2 ) { add(u, v, -1); add(v, u, -1); }
        else { add(u, v, a != b); add(v, u, a != b); }
    }
    DFS(1, 0);
    pii ans = min(f[1][0], f[1][1]);
    printf("%d %d\n", ans.x, ans.y);
    return 0;
}
