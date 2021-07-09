/***************************************************************
	File name: P4719.cpp
	Author: ljfcnyali
	Create time: 2019年08月28日 星期三 15时42分10秒
***************************************************************/
#include<bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for ( int i = (a), _end_ = (b); i <= _end_; ++ i ) 
#define mem(a) memset ( (a), 0, sizeof ( a ) ) 
#define str(a) strlen ( a ) 
#define lson root << 1
#define rson root << 1 | 1
typedef long long LL;

const int maxn = 500010;
const int INF = 0x3f3f3f3f;

int Begin[maxn], Next[maxn], To[maxn], e, n, m;
int size[maxn], son[maxn], top[maxn], fa[maxn], dis[maxn], p[maxn], id[maxn], End[maxn];
int cnt, tot, a[maxn], f[maxn][2];

struct matrix
{
    int g[2][2];
    matrix() { memset(g, 0, sizeof(g)); }
    matrix operator * (const matrix &b) const 
    {
        matrix c;
        REP(i, 0, 1) REP(j, 0, 1) REP(k, 0, 1) c.g[i][j] = max(c.g[i][j], g[i][k] + b.g[k][j]);
        return c;
    }
} Tree[maxn], g[maxn];

inline void PushUp(int root) { Tree[root] = Tree[lson] * Tree[rson]; }

inline void Build(int root, int l, int r)
{
    if ( l == r ) { Tree[root] = g[id[l]]; return ; }
    int Mid = l + r >> 1;
    Build(lson, l, Mid); Build(rson, Mid + 1, r);
    PushUp(root);
}

inline matrix Query(int root, int l, int r, int L, int R)
{
    if ( L <= l && r <= R ) return Tree[root];
    int Mid = l + r >> 1;
    if ( R <= Mid ) return Query(lson, l, Mid, L, R);
    if ( Mid < L ) return Query(rson, Mid + 1, r, L, R);
    return Query(lson, l, Mid, L, R) * Query(rson, Mid + 1, r, L, R);
}

inline void Modify(int root, int l, int r, int pos)
{
    if ( l == r ) { Tree[root] = g[id[l]]; return ; }
    int Mid = l + r >> 1;
    if ( pos <= Mid ) Modify(lson, l, Mid, pos);
    else Modify(rson, Mid + 1, r, pos);
    PushUp(root);
}

inline void Update(int x, int val)
{
    g[x].g[1][0] += val - a[x]; a[x] = val;
    while ( x ) 
    {
        matrix last = Query(1, 1, n, p[top[x]], End[top[x]]);
        Modify(1, 1, n, p[x]);
        matrix now = Query(1, 1, n, p[top[x]], End[top[x]]);
        x = fa[top[x]];
        g[x].g[0][0] += max(now.g[0][0], now.g[1][0]) - max(last.g[0][0], last.g[1][0]); 
        g[x].g[0][1] = g[x].g[0][0];
        g[x].g[1][0] += now.g[0][0] - last.g[0][0];
    }
}

inline void add(int u, int v) { To[++ e] = v; Next[e] = Begin[u]; Begin[u] = e; }

inline void DFS1(int u)
{
    size[u] = 1; int Max = 0; f[u][1] = a[u];
    for ( int i = Begin[u]; i; i = Next[i] ) 
    {
        int v = To[i]; if ( v == fa[u] ) continue ;
        dis[v] = dis[u] + 1; fa[v] = u;
        DFS1(v); size[u] += size[v];
        if ( size[v] > Max ) { Max = size[v]; son[u] = v; }
        f[u][1] += f[v][0];
        f[u][0] += max(f[v][0], f[v][1]);
    }
}

inline void DFS2(int u, int t)
{
    top[u] = t; p[u] = ++ cnt; id[cnt] = u; End[t] = cnt;
    g[u].g[1][0] = a[u]; g[u].g[1][1] = -INF;
    if ( !son[u] ) return ;
    DFS2(son[u], t);
    for ( int i = Begin[u]; i; i = Next[i] ) 
    {
        int v = To[i]; if ( v == fa[u] || v == son[u] ) continue ;
        DFS2(v, v);
        g[u].g[0][0] += max(f[v][0], f[v][1]);
        g[u].g[1][0] += f[v][0];
    }
    g[u].g[0][1] = g[u].g[0][0];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    REP(i, 1, n) scanf("%d", &a[i]);
    REP(i, 1, n - 1) { int u, v; scanf("%d%d", &u, &v); add(u, v); add(v, u); }
    dis[1] = 1; DFS1(1); DFS2(1, 1);
    Build(1, 1, n);
    REP(i, 1, m)
    {
        int x, val; scanf("%d%d", &x, &val);
        Update(x, val);
        matrix ans = Query(1, 1, n, 1, End[1]);
        printf("%d\n", max(ans.g[0][0], ans.g[1][0]));
    }
    return 0;
}
