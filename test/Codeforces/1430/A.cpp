/***************************************************************
	File name: A.cpp
	Author: ljfcnyali
	Create time: 2020年10月11日 星期日 17时05分29秒
***************************************************************/
#include<bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for ( int i = (a), _end_ = (b); i <= _end_; ++ i ) 
#define mem(a) memset ( (a), 0, sizeof ( a ) ) 
#define str(a) strlen ( a ) 
#define pii pair<int, int>
typedef long long LL;

const int maxn = 1e5 + 10;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t, n; scanf("%d", &t);
    while ( t -- ) 
    {
        scanf("%d", &n);
        if ( n % 3 == 0 ) printf("%d %d %d\n", n / 3, 0, 0);
        else if ( n % 3 == 2 ) 
        {
            if ( n <= 4 ) puts("-1");
            else printf("%d %d %d\n", (n - 5) / 3, 1, 0);
        }
        else 
        {
            if ( n <= 6 ) puts("-1");
            else printf("%d %d %d\n", (n - 7) / 3, 0, 1);
        }
    }
    return 0;
}
