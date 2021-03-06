#include<bits/stdc++.h>

#define assn(n,a,b) assert(n<=b and n>=a)
#define pb push_back
#define mp make_pair
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define SET(a,b) memset(a,b,sizeof(a))
#define LET(x,a) __typeof(a) x(a)
#define TR(v,it) for( LET(it,v.begin()) ; it != v.end() ; it++)
#define repi(i,n) for(int i=0; i<(int)n;i++)
#define sd(n) scanf("%d",&n)
#define si(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define sortv(a) sort(a.begin(),a.end())
#define all(a) a.begin(),a.end()
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

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;



int C[100];
bool E[100][100];
int N; 
bool V[100];



void process(int &x, int &y, string A)
{
    int n = A.size();
    x = 0; y = 0;
    int i = 0;
    for(i =0; i<n; i++)
    {
        if(A[i]=='-')break;
        x = x*10 + (A[i]-'0');
    }
    i++;
    for(;i<n; i++)
        y = y*10 + (A[i]-'0');
}


bool dfs(int node)
{
    if(C[node])return true;
    bool set[4] = {};
    for(int i =0 ; i<N; i++)
        if(E[node][i] and C[i])
            set[C[i]-1] = true;
    int i;
    for(i = 0; i<4; i++)
        if(set[i]==false)break;
    if(i==4)return false;
    
    for(int c =0; c<4; c++)
        if(set[c]==false)
        {
            C[node] = c+1;
            bool fail = false;
            for(int i =0 ; i<N; i++)
                if(E[node][i] and C[i]==0)
                {
                    fail |= not dfs(i);
                    if(fail)break;
                }
            if(fail==false)return true;
        }
    C[node]=0;
    return false;
}


int main()
{
    si(N);getchar();
    string A;
    while(cin>>A)
    {
        int x,y;
        process(x,y,A);
        x--; y--; E[x][y] = E[y][x] =true;
    }
    bool can = true;
    for(int i =0; i<N; i++)can &= dfs(i);
    for(int i =0; i<N; i++) cout<<i+1<<" "<<C[i]<<endl;
    return 0;
}


