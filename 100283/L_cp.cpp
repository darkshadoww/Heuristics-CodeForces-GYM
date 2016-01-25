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

char S[10000001];
char F[101];

int f(char S[])
{
    int N,a,m;
    scanf("%c %d %d %d",S,&N,&m,&a);
//    printf("%c %d %d %d\n",S[0],N,m,a);
    for(int i = 1; i<N; i++)
        S[i] = (((S[i-1]-'a')*m + i*a) % 26) + 'a';
    S[N] = 0;
//    printf("%s\n",S);
    getchar();
    return N;
}

int BIT[1<<25];
int ql,qr;
int base;
int L;

int query(int id, int cl, int cr)
{
    if(ql>=cr or qr<=cl)return 0;
    if(cl>=ql and cr<=qr)
        return BIT[id];
    int cm = (cl+cr)/2;
    return query(2*id,cl,cm) | query(2*id+1,cm,cr);
}

int find_char(int start, int c)
{
//    trace(start,c);
    ql = start;
    int l = start+1;
    int h = L;
    while(h>l)
    {
//        trace(start,c,ql,qr);
        int m = (l+h)/2;
        qr = m;
        int mask = query(1,0,base);
        if(mask & (1<<c))
            h = m;
        else l = m+1;
    }
    while(l<=L)
    {
        qr = l;
        if( query(1,0,base) & (1<<c))
            return l;
        l++;
    }
    return l;
}


int main()
{
    int t; si(t); int T = t; getchar();
    while(t--)
    {
        L = f(S);
        base = 1;
        while(base<L)base*=2;
        memset(BIT,0,sizeof(BIT));
        for(int i =0; i<L; i++)
            BIT[base+i] = 1<<(S[i]-'a');
        for(int i = base-1; i>0; i--)
            BIT[i] = (BIT[2*i] | BIT[2*i+1]);
        printf("Case %d:\n",T-t);
        int N;
        si(N); getchar();
//        trace(L,N);
        while(N--)
        {
            int l = f(F);
            int st = 0;
            for(int i =0; i<l; i++)
            {
                st = find_char(st,F[i]-'a');
//                trace(st);
                if(st>L)break;
            }
            if(st>L) printf("REPEAT\n"); else printf("BRAVO\n");
        }
    }
    return 0;	
}
