/***************************************************************
	File name: P3648.cpp
	Author: ljfcnyali
	Create time: 2019年08月08日 星期四 16时11分09秒
***************************************************************/
#include<bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for ( int i = (a), _end_ = (b); i <= _end_; ++ i ) 
#define mem(a) memset ( (a), 0, sizeof ( a ) ) 
#define str(a) strlen ( a ) 
#define int long long 

const int maxn = 100010;

int dp[maxn][2], n, k, sum[maxn], Q[maxn], pre[maxn][210], o;

inline double slope(int i, int j) 
{ 
    if ( sum[j] == sum[i] ) return 0x3f3f3f3f;
    return (dp[j][o ^ 1] - dp[i][o ^ 1] - sum[j] * sum[j] + sum[i] * sum[i]) * 1.0 / (sum[i] - sum[j]); 
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%lld%lld", &n, &k);
    REP(i, 1, n) { int x; scanf("%lld", &x); sum[i] = sum[i - 1] + x; }
    REP(p, 1, k)
    {
        int head = 1, tail = 1;
        REP(i, 1, n)
        {
            while ( head < tail && slope(Q[head], Q[head + 1]) <= sum[i] ) ++ head;
            dp[i][o] = dp[Q[head]][o ^ 1] + (sum[i] - sum[Q[head]]) * sum[Q[head]];
            pre[i][p] = Q[head];
            while ( head < tail && slope(Q[tail - 1], Q[tail]) >= slope(Q[tail - 1], i) ) -- tail;
            Q[++ tail] = i;
        }
        o ^= 1;
    }
    printf("%lld\n", dp[n][o ^ 1]);
    int x = n;
    for ( int i = k; i >= 1; -- i ) { x = pre[x][i]; printf("%lld ", x); } puts("");
    return 0;
}
