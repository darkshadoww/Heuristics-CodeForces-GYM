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

const int mod = 1000000007;
inline void add(int &x, int y){x+=y; if(x>=mod)x-=mod; if(x<0)x+=mod;}
inline int mul(int x, int y){ return ((LL)x * y)%mod;}
int gcd(int a, int b){ if(b)return gcd(b,a%b); return a;}
int power(int a ,int p){int ret = 1; while(p){if(p&1)ret=mul(ret,a); a=mul(a,a); p/=2;}return ret;}

#ifdef ONLINE_JUDGE
FILE *fin = freopen("mahdi.in","r",stdin);
#endif

char F[101];
VI POS[26];
char S[10000001];
int f(char S[])
{
    int N,a,m;
    scanf("%c %d %d %d",S,&N,&m,&a);
    for(int i = 1; i<N; i++)
        S[i] = (((S[i-1]-'a')*m + i*a) % 26) + 'a';
    S[N] = 0;
    getchar();
    return N;
}


int main()
{
    int t; si(t); int T = t; getchar();
    while(t--)
    {
        int L = f(S);
        printf("Case %d:\n",T-t);
        int N;
        si(N); getchar();
        for(int i =0; i<26; i++)POS[i].clear();
        for(int i =0; i<L; i++) POS[S[i]-'a'].PB(i);
        while(N--)
        {
            int l = f(F);
            int st = 0;
            for(int i =0; i<l; i++)
            {
                F[i]-='a';
                auto it = lower_bound( POS[F[i]].begin() , POS[F[i]].end(), st);
                if(it==POS[F[i]].end()){st = L+1;break;}
                else st = (*it) + 1;
            }
            if(st>L) printf("REPEAT\n"); else printf("BRAVO\n");
        }
    }
    return 0;	
}
