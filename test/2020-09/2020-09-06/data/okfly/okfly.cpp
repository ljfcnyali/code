//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,u) for(int i=start[u];i;i=e[i].next)
#define fi first
#define se second
#define mkr(a,b) make_pair(a,b)
#define SZ(A) ((int)A.size())
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
inline int read()
{
    int s=0,f=1; char ch=getchar();
    while(!isdigit(ch) && ch!='-')ch=getchar();
    if(ch=='-')ch=getchar(),f=-1;
    while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
    return ~f?s:-s;
}

const int maxn=2e5+20;

struct Edge {
    int u,v,w;
    Edge(int _u=0,int _v=0,int _w=0){ u=_u; v=_v; w=_w;}
};
Edge E[maxn];
int vis[maxn];

vector<int>ed[maxn];

int ff[maxn];
int fin(int x){ return x==ff[x]?x:ff[x]=fin(ff[x]);}
inline void merge(int x,int y){ x=fin(x); y=fin(y); ff[y]=x;}

int n,m;
int fa[maxn],deep[maxn],fai[maxn];

void dfs(int u)
{
    for(int i:ed[u])
	if(i!=fai[u])
	{
	    int v=u^E[i].u^E[i].v;
	    fai[v]=i;
	    fa[v]=u;
	    deep[v]=deep[u]+1;
	    dfs(v);
	}
}

int sz[maxn][32][2],size[maxn];

inline void init()
{
    n=read();m=read();
    REP(i,1,n)ed[i].clear(),ff[i]=i;
    memset(vis,0,sizeof(int)*(m+1));
    REP(i,1,m)
    {
	int u=read(),v=read(),w=read();
	E[i]=Edge(u,v,w);
    }
    sort(E+1,E+m+1,[](Edge a,Edge b){ return a.w>b.w;});
    REP(i,1,m)
    {
	int u=E[i].u,v=E[i].v;
	if(fin(u)==fin(v))continue;
	vis[i]=1;
	merge(u,v);
	ed[u].push_back(i);
	ed[v].push_back(i);
    }
    fai[1]=0; deep[1]=1; dfs(1);
    REP(i,1,m)if(!vis[i])
    {
	int u=E[i].u,v=E[i].v,w=E[i].w;
	while(u!=v)
	{
	    if(deep[u]>deep[v])swap(u,v);
	    E[fai[v]].w+=w;
	    v=fa[v];
	}
    }
}

unsigned ll ans=0;

inline void Merge(int u,int v,int w)
{
    u=fin(u); v=fin(v);
    REP(j,0,20)
    {
	unsigned ll num=0;
	int val=w>>j&1;
	REP(op,0,1)num+=(unsigned ll)sz[u][j][op]*sz[v][j][op^val^1];
	ans+=(1<<j)*num;
	REP(op,0,1)sz[u][j][op]+=sz[v][j][op];
    }
    w&=~((1<<21)-1);
    ans+=(unsigned ll)size[u]*size[v]*w;
    
    ff[v]=u; size[u]+=size[v];
}

inline void doing()
{
    ans=0;
    REP(i,1,n)
    {
	size[i]=1;
	memset(sz[i],0,sizeof(sz[i]));
	ff[i]=i;
	REP(j,0,20)sz[i][j][i>>j&1]++;
    }
    int num=0;
    REP(i,1,m)if(vis[i])E[++num]=E[i];
    sort(E+1,E+num+1,[](Edge a,Edge b){ return a.w>b.w;});
    REP(i,1,num)
    {
	int u=E[i].u,v=E[i].v,w=E[i].w;
	Merge(u,v,w);
    }
    printf("%llu\n",ans);
}

int main()
{
    int t=read();
    while(t--)
    {
	init();
	doing();
    }
    return 0;
}
