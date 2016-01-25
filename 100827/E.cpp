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

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);

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

typedef unsigned long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;



LL DP[71][10][2]; // DP[length][last_digit][0] or [1] . 1 implies necessary fall.
string A; 

int main()
{
    for(int d = 0; d<10; d++)
        DP[0][d][1] = DP[0][d][0] = 1;
    for(int l = 1; l<=70; l++)
    {
        for(int d = 0; d<10; d++)
        {
            for(int nd = 0; nd<=d; nd++)
                DP[l][d][1] += DP[l-1][nd][1];
            for(int nd = 0; nd<10; nd++)
            {
                if(nd<d)
                    DP[l][d][0] += DP[l-1][nd][1];
                else
                    DP[l][d][0] += DP[l-1][nd][0];
            }
        }
    }

    int t; si(t); while(t--)
    {
        string A;
        cin>>A;
        int N = A.length();
        int fall= 0;
        int rise = 0;
        for(int i = 0; i<N-1; i++)
        {
            if(A[i+1]<A[i])fall = 1;
            if(A[i+1]>A[i] and fall)rise = 1;
        }
        if(rise) { cout<<-1<<endl; continue;}
        LL ans = 0;
        fall = 0;
        int last = 0;
        for(int i = 0; i<N; i++)
        {
            int cd = A[i]-'0';
            if(i and A[i]<last)fall = 1;
            if(fall)
            {
                for(int d = 0; d<cd; d++)
                    ans += DP[N-i-1][d][1];
            }
            else
            {
            
                for(int d = 0; d<cd; d++)
                    if(d>=last)
                        ans += DP[N-i-1][d][0];
                    else
                        ans += DP[N-i-1][d][1];
            }
            last = cd;
        }
        cout<<ans<<endl;
    }
    //ios_base::sync_with_stdio(false);
    return 0;
}


