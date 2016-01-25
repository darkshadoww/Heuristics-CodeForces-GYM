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
#define REP(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define all(v) (v).begin(),(v).end()

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;

const int mod = 1000000007;
inline void add(int &x, int y){x+=y; if(x>=mod)x-=mod; if(x<0)x+=mod;}
inline int mul(int x, int y){ return ((LL)x * y)%mod;}
int gcd(int a, int b){ if(b)return gcd(b,a%b); return a;}
int power(int a ,int p){int ret = 1; while(p){if(p&1)ret=mul(ret,a); a=mul(a,a); p/=2;}return ret;}
int phi(int n){ int ret=n; int i = 2; 
    if(n%i==0){ ret-=ret/i; while(n%i==0)n/=i;}
    for(i=3; i*i<=n; i++)if(n%i==0){ ret-=ret/i; while(n%i==0)n/=i;}
    if(n>1)ret-=ret/n;return ret;
}

#ifdef ONLINE_JUDGE
FILE *fin = freopen("lca.in","r",stdin);
FILE *fout = freopen("lca.out","w",stdout);
#endif

class tree
{
    public:
        VI P,L,R,IN;
        VI nL,nR;
        int N;
        int tm;
        void dfs(int x, int p)
        {
            IN[x] = ++tm;
            P[IN[x]] = p;
            nL[IN[x]] = nR[IN[x]] = 0;
            if(L[x])
            {
                dfs(L[x],IN[x]);
                dfs(R[x],IN[x]);
                nL[IN[x]] = IN[L[x]];
                nR[IN[x]] = IN[R[x]];
            }
        }
        void generalize()
        {
            nL.resize(N+1);
            nR.resize(N+1);
            P.resize(N+1);
            tm = 0;
            dfs(1,0);
            L.resize(N+1);
            R.resize(N+1);
            IN.resize(N+1);
            for(int i =1; i<=N; i++)
            {
                L[i] = nL[i];
                R[i] = nR[i];
                IN[i] = i;
            }
        }
        tree() {}
        tree(int n)
        {
            N = n;
            L.resize(N+1); 
            R.resize(N+1);
            IN.resize(N+1);
            for(int i =1; i<=N; i++)
            {
                si(L[i]); si(R[i]);
            }
            generalize();
        }
        bool isleaf(int i)
        {
            return (i and L[i]+R[i]==0);
        }
        void print()
        {
            printf("%d\n",N);
            for(int i =1; i<=N; i++) 
                printf("%d %d\n",L[i],R[i]);
        }
        void remove(int x)
        {
            priority_queue<int> PQ;
            for(int i =1; i<=N; i++)
                if(isleaf(L[i]) and isleaf(R[i]))
                    PQ.push(i);
            while(x--)
            {
                int y = PQ.top(); PQ.pop();
                L[y] = R[y] = 0;
                N-=2;
                y = P[y];
                if(y>0 and isleaf(L[y]) and isleaf(R[y]))
                    PQ.push(y);
            }
            generalize();
        }
};

bool same(tree &T1, tree &T2)
{
    int N = T1.N;
    for(int i = 1; i<=N; i++)
        if(T1.L[i] != T2.L[i] or T1.R[i] != T2.R[i])return false;
    return true;
}



int main()
{
    while(1)
    {
        int N1; si(N1); if(N1==0)return 0;
        tree T1(N1); 
        int N2; si(N2); 
        tree T2(N2);
        if(N1 > N2)
            T1.remove((N1-N2)/2);
        else if(N2>N1)
            T2.remove((N2-N1)/2);
        int N = min(N1,N2);
        int rl = 0;
        int rh = N/2;
        while(rh>rl)
        {
            int rm = (rl+rh)/2;
            tree cT1(T1);
            tree cT2(T2);
            cT1.remove(rm);
            cT2.remove(rm);
            if(same(cT1,cT2))
                rh = rm;
            else
                rl = rm+1;
        }
        T1.remove(rl);
        T1.print();
    }
    return 0;	
}
