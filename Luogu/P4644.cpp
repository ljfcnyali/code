/***************************************************************
	File name: P4644.cpp
	Author: ljfcnyali
	Create time: 2019年08月15日 星期四 13时03分48秒
***************************************************************/
#include<bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for ( int i = (a), _end_ = (b); i <= _end_; ++ i ) 
#define mem(a) memset ( (a), 0, sizeof ( a ) ) 
#define str(a) strlen ( a ) 
#define lson root << 1
#define rson root << 1 | 1
typedef long long LL;

const int maxn = 1000010;

int n, m, e, Min[maxn], num = 86400;
struct node
{
    int s, t, w;
    bool operator < (const node &a) const { return t < a.t; }
} a[maxn];

inline void PushUp(int root)
{
    Min[root] = min(Min[lson], Min[rson]);
}

inline void Modify(int root, int l, int r, int pos, int val)
{
    if ( l == r ) { Min[root] = min(Min[root], val); return ; }
    int Mid = l + r >> 1;
    if ( pos <= Mid ) Modify(lson, l, Mid, pos, val);
    else Modify(rson, Mid + 1, r, pos, val);
    PushUp(root);
}

inline int Query(int root, int l, int r, int L, int R)
{
    if ( L <= l && r <= R ) return Min[root];
    int Mid = l + r >> 1, sum = 0x3f3f3f3f;
    if ( L <= Mid ) sum = min(sum, Query(lson, l, Mid, L, R));
    if ( Mid < R ) sum = min(sum, Query(rson, Mid + 1, r, L, R));
    return sum;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%d%d%d", &n, &m, &e);
    e = e - m + 1;
    REP(i, 1, n) { scanf("%d%d%d", &a[i].s, &a[i].t, &a[i].w); a[i].s -= m - 1; a[i].t -= m - 1; }
    sort(a + 1, a + n + 1);
    memset(Min, 0x3f, sizeof(Min));
    Modify(1, 0, num, 0, 0);
    REP(i, 1, n)
    {
        int x = Query(1, 0, num, a[i].s - 1, a[i].t - 1);
        if ( x == 0x3f3f3f3f ) continue ;
        Modify(1, 0, num, a[i].t, x + a[i].w);
    }
    int x = Query(1, 0, num, e, e);
    printf("%d\n", x == 0x3f3f3f3f ? -1 : x);
    return 0;
}
