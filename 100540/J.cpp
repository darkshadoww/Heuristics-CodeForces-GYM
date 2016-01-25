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
#define sd(n) scanf("%lld",&n)
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

LL mpow(LL a, LL n, LL MOD)
{LL ret=1;LL b=a;while(n) {if(n&1) 
    ret=(ret*b)%MOD;b=(b*b)%MOD;n>>=1;}
return (LL)ret;}

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);

#define int long long

#define MaxVal 100009
int tree[MaxVal];
int p;

void add(int &x, int y){
    x += y;
    if(x>=p)x-=p;
}

void update(int idx ,int val){
    idx+=2;
    while (idx <= MaxVal){
        add(tree[idx] , val);
        idx += (idx & -idx);
    }
}


int read(int idx){
    idx+=2;
    int sum = 0;
    while (idx > 0){
        add(sum, tree[idx]);
        idx -= (idx & -idx);
    }
    return sum;
}

#undef int
int main()
#define int long long
{
    while(1){
        memset(tree, 0, sizeof(tree));
        int b,l,n;
        sd(b),sd(p),sd(l),sd(n);
        getchar();
        if(b==0 and p==0 and l==0 and n==0)return 0;
        while(n--){
            char ccc;
            int x, y;
            scanf("%c %lld %lld",&ccc, &x, &y);
            getchar();
            x--,y--;
            if(ccc=='E'){
                y++;
                int curval=read(x)-read(x-1);
                update(x, (((mpow(b, l-x-1, p)*y)%p) - curval + p)%p);
            }
            else{
                int val = (read(y) - read(x-1) + p)%p;
                int div = mpow(b, l-y-1, p);
                div = mpow(div, p-2, p);
                val = (val*div)%p;
                printf("%lld\n", val);
            }
        }
        printf("-\n");
    }
    return 0;
}


