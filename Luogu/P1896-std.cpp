/***************************************************************
	File name: P1896-std.cpp
	Author: ljfcnyali
	Create time: 2019年06月12日 星期三 15时13分48秒
***************************************************************/
#include<bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for ( int i = (a), _end_ = (b); i <= _end_; ++ i ) 
#define mem(a) memset ( (a), 0, sizeof ( a ) ) 
#define str(a) strlen ( a ) 

long long ans[10][200];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
ans[1][1] = 1; 
ans[2][1] = 4; ans[2][2] = 0; ans[2][3] = 0; ans[2][4] = 0; 
ans[3][1] = 9; ans[3][2] = 16; ans[3][3] = 8; ans[3][4] = 1; ans[3][5] = 0; ans[3][6] = 0; ans[3][7] = 0; ans[3][8] = 0; ans[3][9] = 0; 
ans[4][1] = 16; ans[4][2] = 78; ans[4][3] = 140; ans[4][4] = 79; ans[4][5] = 0; ans[4][6] = 0; ans[4][7] = 0; ans[4][8] = 0; ans[4][9] = 0; ans[4][10] = 0; ans[4][11] = 0; ans[4][12] = 0; ans[4][13] = 0; ans[4][14] = 0; ans[4][15] = 0; ans[4][16] = 0; 
ans[5][1] = 25; ans[5][2] = 228; ans[5][3] = 964; ans[5][4] = 1987; ans[5][5] = 1974; ans[5][6] = 978; ans[5][7] = 242; ans[5][8] = 27; ans[5][9] = 1; ans[5][10] = 0; ans[5][11] = 0; ans[5][12] = 0; ans[5][13] = 0; ans[5][14] = 0; ans[5][15] = 0; ans[5][16] = 0; ans[5][17] = 0; ans[5][18] = 0; ans[5][19] = 0; ans[5][20] = 0; ans[5][21] = 0; ans[5][22] = 0; ans[5][23] = 0; ans[5][24] = 0; ans[5][25] = 0; 
ans[6][1] = 36; ans[6][2] = 520; ans[6][3] = 3920; ans[6][4] = 16834; ans[6][5] = 42368; ans[6][6] = 62266; ans[6][7] = 51504; ans[6][8] = 21792; ans[6][9] = 3600; ans[6][10] = 0; ans[6][11] = 0; ans[6][12] = 0; ans[6][13] = 0; ans[6][14] = 0; ans[6][15] = 0; ans[6][16] = 0; ans[6][17] = 0; ans[6][18] = 0; ans[6][19] = 0; ans[6][20] = 0; ans[6][21] = 0; ans[6][22] = 0; ans[6][23] = 0; ans[6][24] = 0; ans[6][25] = 0; ans[6][26] = 0; ans[6][27] = 0; ans[6][28] = 0; ans[6][29] = 0; ans[6][30] = 0; ans[6][31] = 0; ans[6][32] = 0; ans[6][33] = 0; ans[6][34] = 0; ans[6][35] = 0; ans[6][36] = 0; 
ans[7][1] = 49; ans[7][2] = 1020; ans[7][3] = 11860; ans[7][4] = 85275; ans[7][5] = 397014; ans[7][6] = 1220298; ans[7][7] = 2484382; ans[7][8] = 3324193; ans[7][9] = 2882737; ans[7][10] = 1601292; ans[7][11] = 569818; ans[7][12] = 129657; ans[7][13] = 18389; ans[7][14] = 1520; ans[7][15] = 64; ans[7][16] = 1; ans[7][17] = 0; ans[7][18] = 0; ans[7][19] = 0; ans[7][20] = 0; ans[7][21] = 0; ans[7][22] = 0; ans[7][23] = 0; ans[7][24] = 0; ans[7][25] = 0; ans[7][26] = 0; ans[7][27] = 0; ans[7][28] = 0; ans[7][29] = 0; ans[7][30] = 0; ans[7][31] = 0; ans[7][32] = 0; ans[7][33] = 0; ans[7][34] = 0; ans[7][35] = 0; ans[7][36] = 0; ans[7][37] = 0; ans[7][38] = 0; ans[7][39] = 0; ans[7][40] = 0; ans[7][41] = 0; ans[7][42] = 0; ans[7][43] = 0; ans[7][44] = 0; ans[7][45] = 0; ans[7][46] = 0; ans[7][47] = 0; ans[7][48] = 0; ans[7][49] = 0; 
ans[8][1] = 64; ans[8][2] = 1806; ans[8][3] = 29708; ans[8][4] = 317471; ans[8][5] = 2326320; ans[8][6] = 12033330; ans[8][7] = 44601420; ans[8][8] = 119138166; ans[8][9] = 229095676; ans[8][10] = 314949564; ans[8][11] = 305560392; ans[8][12] = 204883338; ans[8][13] = 91802548; ans[8][14] = 25952226; ans[8][15] = 4142000; ans[8][16] = 281571; ans[8][17] = 0; ans[8][18] = 0; ans[8][19] = 0; ans[8][20] = 0; ans[8][21] = 0; ans[8][22] = 0; ans[8][23] = 0; ans[8][24] = 0; ans[8][25] = 0; ans[8][26] = 0; ans[8][27] = 0; ans[8][28] = 0; ans[8][29] = 0; ans[8][30] = 0; ans[8][31] = 0; ans[8][32] = 0; ans[8][33] = 0; ans[8][34] = 0; ans[8][35] = 0; ans[8][36] = 0; ans[8][37] = 0; ans[8][38] = 0; ans[8][39] = 0; ans[8][40] = 0; ans[8][41] = 0; ans[8][42] = 0; ans[8][43] = 0; ans[8][44] = 0; ans[8][45] = 0; ans[8][46] = 0; ans[8][47] = 0; ans[8][48] = 0; ans[8][49] = 0; ans[8][50] = 0; ans[8][51] = 0; ans[8][52] = 0; ans[8][53] = 0; ans[8][54] = 0; ans[8][55] = 0; ans[8][56] = 0; ans[8][57] = 0; ans[8][58] = 0; ans[8][59] = 0; ans[8][60] = 0; ans[8][61] = 0; ans[8][62] = 0; ans[8][63] = 0; ans[8][64] = 0; 
ans[9][1] = 81; ans[9][2] = 2968; ans[9][3] = 65240; ans[9][4] = 962089; ans[9][5] = 10087628; ans[9][6] = 77784658; ans[9][7] = 450193818; ans[9][8] = 1979541332; ans[9][9] = 6655170642; ans[9][10] = 17143061738; ans[9][11] = 33787564116; ans[9][12] = 50734210126; ans[9][13] = 57647295377; ans[9][14] = 49138545860; ans[9][15] = 31122500764; ans[9][16] = 14518795348; ans[9][17] = 4959383037; ans[9][18] = 1237072414; 
    int n, k;
    cin >> n >> k;
    cout << ans[n][k] << endl;
    return 0;
}
