/***************************************************************
	File name: gen.cpp
	Author: ljfcnyali
	Create time: 2019年10月30日 星期三 15时54分10秒
***************************************************************/
#include<bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for ( int i = (a), _end_ = (b); i <= _end_; ++ i ) 
#define mem(a) memset ( (a), 0, sizeof ( a ) ) 
#define str(a) strlen ( a ) 
#define pii pair<int, int>
typedef long long LL;

int main()
{
    srand(time(0));
    freopen("Slowset.in", "w", stdout);
    int n = 8, m = 5;
    printf("%d %d\n", n, m);
    REP(i, 2, n) printf("%d %d\n", rand() % (i - 1) + 1, i);
    REP(i, 1, m) printf("%d ", rand() % n + 1); puts("");
    return 0;
}
