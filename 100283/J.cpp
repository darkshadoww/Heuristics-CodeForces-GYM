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
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;

#ifdef ONLINE_JUDGE
FILE *fin = freopen("gift.in","r",stdin);
#endif

int A[5];
int B[5];
bitset<10000> DP[11][11][11][11][11];

void f()
{
    bitset<10000> ret;
    for(int i = 0; i<32; i++)
            ret ^= 
                DP[ (i>>0)%2 ? A[0] : B[0]   ][ (i>>1)%2 ? A[1] : B[1]   ][ (i>>2)%2 ? A[2] : B[2]   ][ (i>>3)%2 ? A[3] : B[3]   ][ (i>>4)%2 ? A[4] : B[4]   ];
    printf("%d\n",ret.count());
}


void prefix()
{
    for(int j =0; j<5; j++) B[j] = A[j]-1;
    for(int i = 0; i<31; i++)
                DP[A[0]][A[1]][A[2]][A[3]][A[4]] ^=DP[ (i>>0)%2 ? A[0] : B[0]   ][ (i>>1)%2 ? A[1] : B[1]   ][ (i>>2)%2 ? A[2] : B[2]   ][ (i>>3)%2 ? A[3] : B[3]   ][ (i>>4)%2 ? A[4] : B[4]   ];
}


int V[10000][5];
map<int,int> Values[5];

int main()
{
    int t; si(t); int T =t; while(t--)
    {
        printf("Case %d:\n",T-t);        
        for(int i =0; i<5; i++) Values[i].clear();
        int N,q; si(N); si(q);
        for(auto &a : DP)for(auto &b: a)for(auto &c: b)for(auto &d: c)for(auto &e: d)e.reset();
        for(int i =0; i<N; i++)
            for(int j = 0; j<5; j++)
            {
                double x; cin>>x; x*=1000;
                V[i][j] = x;
                Values[j][V[i][j]];
            }
        
        for(int i =0; i<5; i++)
        {
            int cnt = 0;
            for(auto &c : Values[i])
                c.S = ++cnt;
        }
        for(int i =0; i<N; i++){
            for(int j = 0; j<5; j++){
                V[i][j] = Values[j][V[i][j]];
            }
            DP[V[i][0]][V[i][1]][V[i][2]][V[i][3]][V[i][4]].set(i);
        }


        for(int i = 1; i<=Values[0].size();i++)
        for(int j = 1; j<=Values[1].size();j++)
        for(int k = 1; k<=Values[2].size();k++)
        for(int l = 1; l<=Values[3].size();l++)
        for(int m = 1; m<=Values[4].size();m++)
        {
            A[0] =i; A[1] = j; A[2] = k; A[3] = l; A[4] = m;prefix();
        }

        while(q--)
        {
            double x;
            int L[5],R[5];
            for(int i = 0; i<5; i++){cin>>x; x*=1000; L[i] = x;}
            for(int i = 0; i<5; i++){cin>>x; x*=1000; R[i] = x;}
            for(int i = 0; i<5; i++)
            {
                A[i] = B[i] = 0;
                for(auto c : Values[i])
                    if(c.F <= R[i])A[i]++;
                for(auto c : Values[i])
                    if(c.F < L[i])B[i]++;
            }

            f();
        }

    }
    return 0;	
}
