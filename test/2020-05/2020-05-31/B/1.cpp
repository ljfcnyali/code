/***************************************************************
	File name: B.cpp
	Author: ljfcnyali
	Create time: 2020年05月31日 星期日 09时43分40秒
***************************************************************/
#include<bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for ( int i = (a), _end_ = (b); i <= _end_; ++ i ) 
#define mem(a) memset ( (a), 0, sizeof ( a ) ) 
#define str(a) strlen ( a ) 
#define pii pair<int, int>
#define ls(x) Tree[x].lson
#define rs(x) Tree[x].rson
typedef long long LL;

const int maxn = 2e6 + 10;

int n, Begin[maxn], Next[maxn], To[maxn], e, size[maxn];
int Root[maxn], tot, ans;
struct node { int lson, rson, sum; } Tree[maxn << 6];

inline void PushUp(int root) { Tree[root].sum = Tree[ls(root)].sum + Tree[rs(root)].sum; }

inline int Merge(int p, int q, int l, int r)
{
    if ( !p || !q ) return p + q;
    int root = ++ tot;
    if ( l == r ) { Tree[root].sum = Tree[p].sum + Tree[q].sum; return root; }
    int Mid = l + r >> 1;
    ls(root) = Merge(ls(p), ls(q), l, Mid);
    rs(root) = Merge(rs(p), rs(q), Mid + 1, r);
    PushUp(root); return root;
}

inline int Modify1(int now, int l, int r, int pos, int val)
{
    int root = ++ tot; Tree[root] = Tree[now]; Tree[root].sum += val;
    if ( l == r ) return root;
    int Mid = l + r >> 1;
    if ( pos <= Mid ) ls(root) = Modify1(ls(root), l, Mid, pos, val);
    else rs(root) = Modify1(rs(root), Mid + 1, r, pos, val);
    return root;
}

inline void Modify2(int &root, int l, int r, int pos, int val)
{
    if ( !root ) root = ++ tot; Tree[root].sum += pos;
    if ( l == r ) return ;
    int Mid = l + r >> 1;
    if ( pos <= Mid ) Modify2(ls(root), l, Mid, pos, val);
    else Modify2(rs(root), Mid + 1, r, pos, val);
}

inline int Query(int p, int q, int l, int r, int pos)
{
    // printf("%d %d %d %d %d %d %d\n", p, q, l, r, pos, Tree[p].sum, Tree[q].sum);
    if ( Tree[p].sum - Tree[q].sum == 0 ) return 0;
    if ( l == r ) return Tree[p].sum - Tree[q].sum; 
    int Mid = l + r >> 1;
    if ( pos <= Mid ) return Query(ls(p), ls(q), l, Mid, pos);
    return Query(rs(p), rs(q), Mid + 1, r, pos);
}

inline void Copy(int &root, int now, int l, int r)
{
    if ( !now ) return ; root = ++ tot;
    Tree[root].sum = Tree[now].sum;
    if ( l == r ) return ;
    int Mid = l + r >> 1;
    Copy(ls(root), ls(now), l, Mid);
    Copy(rs(root), rs(now), Mid + 1, r);
}

inline void add(int u, int v) { To[++ e] = v; Next[e] = Begin[u]; Begin[u] = e; }

inline void DFS1(int u, int fa)
{
    size[u] = 1;
    for ( int i = Begin[u]; i; i = Next[i] ) 
    {
        int v = To[i]; if ( v == fa ) continue ;
        DFS1(v, u); size[u] += size[v];
        Root[u] = Merge(Root[u], Root[v], 1, n);
    }
    Root[u] = Modify1(Root[u], 1, n, size[u], 1);
}

inline void DFS2(int u, int fa)
{
    for ( int i = Begin[u]; i; i = Next[i] ) 
    {
        int v = To[i]; if ( v == fa ) continue ;
        Root[0] = Modify1(Root[0], 1, n, size[u], -1);
        Root[0] = Modify1(Root[0], 1, n, n - size[v], 1);
        DFS2(v, u);
        int a = size[v], b = n - size[v];
        // printf("%d %d %d %d\n", u, v, a, b);
        if ( a < b && a >= ans && (Query(Root[0], Root[v], 1, n, b - a) || Query(Root[0], Root[v], 1, n, a)) ) ans = max(ans, a); 
        if ( a > b && b >= ans && (Query(Root[v], 0, 1, n, a - b) || Query(Root[v], 0, 1, n, b)) ) ans = max(ans, b);
        // Modify2(Root[0], 1, n, size[u], 1);
        // Modify2(Root[0], 1, n, n - size[v], -1);
        Root[0] = Modify1(Root[0], 1, n, size[u], 1);
        Root[0] = Modify1(Root[0], 1, n, n - size[v], -1);
    }
}

inline void read(int &x) 
{
    x = 0; char c = getchar();
    while ( c < '0' || c > '9' ) c = getchar();
    while ( c >= '0' && c <= '9' ) { x = x * 10 + c - '0'; c = getchar(); }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
#endif
    scanf("%d", &n);
    REP(i, 1, n - 1) { int u, v; read(u); read(v); add(u, v); add(v, u); }
    DFS1(1, 0); Copy(Root[0], Root[1], 1, n); DFS2(1, 0); 
    printf("%d\n", ans);
    return 0;
}
