//karanaggarwal
#include<bits/stdc++.h>
using namespace std;

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

#define si(x) scanf("%d",&x)
#define F first
#define S second
#define x first
#define y second
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;


#ifdef ONLINE_JUDGE
FILE *fin = freopen("kids.in","r",stdin);
FILE *fout = freopen("kids.out","w",stdout);
#endif

PII P[10000];
PII DP2[5000][5000];
int N; 

LL area(int i, int j, int k)
{
    return abs( 
              (LL)P[i].x * (P[j].y - P[k].y) 
            + (LL)P[j].x * (P[k].y - P[i].y) 
            + (LL)P[k].x * (P[i].y - P[j].y)  
            );
}

int main()
{
    si(N);
    for(int i =0; i<N; i++)
    {
        cin>>P[i].x>>P[i].y;
        P[i+N] = P[i];
    }
    for(int i = 0; i<N; i++)
    {
        int k = i+1;
        DP2[i][(i+2)%N] = MP(i+1,i+2);
        for(int j = i+3; j<i+N-1; j++)
        {
            while(k<j-1 and area(i,j,k) <= area(i,j,k+1))k++;
            DP2[i][j%N] = DP2[i][(j-1)%N];
            if(area(i,DP2[i][j%N].F,DP2[i][j%N].S) <= area(i,k,j))
                DP2[i][j%N] = MP(k,j);
        }
    }
    LL ans =  area(2 , DP2[2][0].F , DP2[2][0].S) - area(0,1,2);
    VI Ts(3); VI Tl(3);
    Ts[0] = 0; Ts[1] = 1; Ts[2] = 2;
    Tl[0] = 2; Tl[1] = DP2[2][0].F; Tl[2] = DP2[2][0].S;

    for(int i = 0; i<N; i++)
    {
        for(int s = i+2; s+2<=i+N; s++)
        {
            int ns = s;
            if(ns>=N)ns-=N;
            int ed = i; if(ed<ns)ed+=N; ed%=N;
            LL narea = area(ns, DP2[ns][ed].F, DP2[ns][ed].S) - area(i,i+1,i+2);
            if(narea > ans)
            {
                ans = narea;
                Ts[0] = i; Ts[1] = i+1; Ts[2] = i+2;
                Tl[0] = ns; Tl[1] = DP2[ns][ed].F; Tl[2] = DP2[ns][ed].S;
            }
        }
    }
    bool odd = false; if(ans&1)odd = true;
    cout<<ans/2; if(odd)printf(".5\n"); else printf(".0\n");
    cout<<(Tl[0]%N) + 1<<" "<<(Tl[1]%N) + 1<<" "<<(Tl[2]%N) + 1<<endl;
    cout<<(Ts[0]%N)+1<<" "<<(Ts[1]%N)+1<<" "<<(Ts[2]%N)+1<<endl;

    return 0;	
}
