//karanaggarwal
//
#include<bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d",&x)
#define F first
#define S second
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;

#ifdef ONLINE_JUDGE
FILE *fin = freopen("road.in","r",stdin);
#endif

int P[100000];
VPII E[1001];
vector<pair<int,PII>> L[100000];

void merge(int x, int y, int cl)
{
    if(L[x].size()>L[y].size())swap(x,y);
    int s1 = L[x].size();
    int s2 = L[y].size();
    L[x].front().S.F += s2*cl;
    L[x].back().S.S += s2*cl;
    L[y].front().S.F += s1*cl;
    L[y].back().S.S += s1*cl;
    for(auto c : L[x])
    {
        P[c.F] = y;
        L[y].PB(c);
    }
}

int ANS[100000];

int main()
{
    int t; si(t); int T = t; 
    while(t--)
    {
        int N,M; si(N); si(M);
        for(int i =0; i<N; i++)
        {
            P[i] = i; 
            L[i].clear(); 
            L[i].PB(MP(i,MP(0,0)));
        }
        for(int i =0; i<=1000; i++) E[i].clear();
        for(int i =0; i<M; i++)
        {
            int x,y; si(x); si(y); int c; si(c); x--; y--; E[c].PB(MP(x,y));
        }
        for(int c = 0; c<=1000; c++)
        {
            for(auto p : E[c])
            {
               int x  =p.F; int y = p.S;
               x = P[x]; y = P[y];
               if(x==y)continue;
               merge(x,y,c);
            }
        }
        int root = P[0];
        int csum = 0;
        for(auto c : L[root])
        {
            csum += c.S.F;
            ANS[c.F] = csum;
            csum -= c.S.S;
        }
        printf("Case %d:\n",T-t);
        for(int i =0; i<N; i++)
            printf("%d\n",ANS[i]);
    }
    return 0;	
}
