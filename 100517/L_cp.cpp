
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
FILE *fin = freopen(stdin,"r",stdin);
FILE *fout = freopen(stdout,"w",stdout);
#endif


struct node
{
    node* L;
    node* R;
    node* P;
    node()
    {
        L = R = P = NULL;
    }
};

bool isL(node* root)
{
    return (root and root.L==NULL and root.R==NULL);
}
void issame(node* r1, node* r2)
{
    if(r1==NULL and r2==NULL)return true;
    if(r1==NULL or r2==NULL)return false;
    if(isL(r1) and isL(r2))return true;
    return (issame(r1.L,r2.L) and issame(r1.R,r2.R));
}
int left[150000],right[150000];
node* make_tree(int i, node* p)
{
    node* r = new node;
    r->P = p;
    if(left[i])
        r->L = make_tree(left[i],r);
    if(right[i])
        r->R = make_tree(right[i],r);
    return r;
}
void delete_tree(node* r)
{
    if(r==NULL)return;
    delete_tree(r->L);
    delete_tree(r->R);
    delete(r); return;
}
node* copy_tree(node* r,node* p)
{
    if(r==NULL)return r;
    node* cp = new node;
    cp->P = p;
    cp->L = copy_tree(r->L,cp);
    cp->R = copy_tree(r->R,cp);
}

node* make(int N)
{
    for(int i =0; i<N; i++){
        si(left[i]); si(right[i]); left[i]--; right[i]--;}
    return make_tree(int i, node* p);
}

int main()
{
    ios_base::sync_with_stdio(false);
    return 0;	
}
