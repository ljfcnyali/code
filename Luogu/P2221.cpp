/***************************************************************
	File name: P2221.cpp
	Author: ljfcnyali
	Create time: 2019年08月07日 星期三 16时24分19秒
***************************************************************/
#include<bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for ( int i = (a), _end_ = (b); i <= _end_; ++ i ) 
#define mem(a) memset ( (a), 0, sizeof ( a ) ) 
#define str(a) strlen ( a ) 
#define lson root << 1
#define rson root << 1 | 1
#define int long long

const int maxn = 400010;

int n, m, sum1, sum2, sum3;

struct node
{
    int l, r, sum1, sum2, sum3, sum4, sum5, lazy;
} Tree[maxn];

inline void Update(int root, int val)
{
    Tree[root].sum1 += (Tree[root].r - Tree[root].l + 1) * val;
    Tree[root].sum2 += Tree[root].sum4 * val;
    Tree[root].sum3 += Tree[root].sum5 * val;
    Tree[root].lazy += val;
}

inline void Push_down(int root)
{
    if ( !Tree[root].lazy ) return ;
    Update(lson, Tree[root].lazy);
    Update(rson, Tree[root].lazy);
    Tree[root].lazy = 0;
}

inline void Push_up(int root)
{
    Tree[root].sum1 = Tree[lson].sum1 + Tree[rson].sum1;
    Tree[root].sum2 = Tree[lson].sum2 + Tree[rson].sum2;
    Tree[root].sum3 = Tree[lson].sum3 + Tree[rson].sum3;
}

inline void Build(int root, int l, int r)
{
    // cerr << root << " " << l << " " << r << endl;
    Tree[root].l = l; Tree[root].r = r;
    if ( l == r ) { Tree[root].sum4 = l; Tree[root].sum5 = l * l; return ; }
    int Mid = l + r >> 1;
    Build(lson, l, Mid); Build(rson, Mid + 1, r);
    Tree[root].sum4 = Tree[lson].sum4 + Tree[rson].sum4;
    Tree[root].sum5 = Tree[lson].sum5 + Tree[rson].sum5;
}

inline void Modify(int root, int l, int r, int L, int R, int val)
{
    if ( L <= l && r <= R ) 
    {
        Update(root, val);
        return ;
    }
    Push_down(root);
    int Mid = l + r >> 1;
    if ( L <= Mid ) Modify(lson, l, Mid, L, R, val);
    if ( Mid < R ) Modify(rson, Mid + 1, r, L, R, val);
    Push_up(root);
}

inline void Query(int root, int l, int r, int L, int R)
{
    if ( L <= l && r <= R ) 
    {
        sum1 += Tree[root].sum1;
        sum2 += Tree[root].sum2;
        sum3 += Tree[root].sum3;
        return ;
        // return (R - L + 1 - R * L) * Tree[root].sum1 + (L + R) * Tree[root].sum2 - Tree[root].sum3;
    }
    Push_down(root);
    int Mid = l + r >> 1;
    if ( L <= Mid ) Query(lson, l, Mid, L, R);
    if ( Mid < R ) Query(rson, Mid + 1, r, L, R);
    return ;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%lld%lld", &n, &m);
    Build(1, 1, n);
    REP(i, 1, m)
    {
        char s[10]; scanf("%s", s);
        if ( s[0] == 'C' ) 
        {
            int l, r, val; scanf("%lld%lld%lld", &l, &r, &val);
            Modify(1, 1, n, l, r - 1, val);
        }
        else
        {
            int l, r; scanf("%lld%lld", &l, &r); -- r;
            sum1 = sum2 = sum3 = 0;
            Query(1, 1, n, l, r);
            int ans1 = (r - l + 1 - l * r) * sum1 + (l + r) * sum2 - sum3, ans2 = (r - l + 1) * (r - l + 2) / 2;
            int x = __gcd(ans1, ans2);
            printf("%lld/%lld\n", ans1 / x, ans2 / x);
        }
    }
    return 0;
}
