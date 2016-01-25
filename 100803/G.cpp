#include<bits/stdc++.h>
#define assn(n,a,b) assert(n<=b and n>=a)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define SET(a,b) memset(a,b,sizeof(a))
#define LET(x,a) __typeof(a) x(a)
#define TR(v,it) for( LET(it,v.begin()) ; it != v.end() ; it++)
#define repi(i,n) for(int i=0; i<(int)n;i++)
#define sd(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define sortv(a) sort(a.begin(),a.end())
#define all(a) a.begin(),a.end()
#define DRT()  int t; cin>>t; while(t--)
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

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;

#define MOD 1000000007ll
LL mpow(LL a, LL n) 
{LL ret=1;LL b=a;while(n) {if(n&1) 
    ret=(ret*b)%MOD;b=(b*b)%MOD;n>>=1;}
return (LL)ret;}

#define MAXN 300009
int tree[6*MAXN];
int lazy[6*MAXN];
int ar[MAXN];
char str[MAXN];

void build_tree(int node, int a, int b) {
    if(a > b) return;

    if(a == b) {
        tree[node] = ar[a];
        return;
    }

    build_tree(node*2, a, (a+b)/2);
    build_tree(node*2+1, 1+(a+b)/2, b);

    tree[node] = min(tree[node*2], tree[node*2+1]);
}

void update_tree(int node, int a, int b, int i, int j, int value) {

    if(lazy[node] != 0) {
        tree[node] += lazy[node];

        if(a != b) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }

        lazy[node] = 0;
    }

    if(a > b || a > j || b < i)
        return;

    if(a >= i && b <= j) {
        tree[node] += value;

        if(a != b) {
            lazy[node*2] += value;
            lazy[node*2+1] += value;
        }

        return;
    }

    update_tree(node*2, a, (a+b)/2, i, j, value);
    update_tree(1+node*2, 1+(a+b)/2, b, i, j, value);

    tree[node] = min(tree[node*2], tree[node*2+1]);

int query_tree(int node, int a, int b, int i, int j) {

    if(a > b || a > j || b < i) return INT_MAX;

    if(lazy[node] != 0) {
        tree[node] += lazy[node];

        if(a != b) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }

        lazy[node] = 0;
    }

    if(a >= i && b <= j)
        return tree[node];

    int q1 = query_tree(node*2, a, (a+b)/2, i, j);
    int q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j);

    int res = min(q1, q2);

    return res;
}


int main()
{
    int n,q;
    set < int > close;
    set<int > ::iterator it;
    sd(n),sd(q);
    scanf(" %s\n",str);
    for(int i=0; i<n; i++){
        if(i)ar[i]=ar[i-1];
        if(str[i]=='(')ar[i]++;
        else{
            ar[i]--;
            close.insert(i);
        }
    }
    build_tree(1,0,n-1);
    while(q--){
        int q;
        sd(q);
        q--;
        if(str[q]=='('){
            str[q]=')';
            close.insert(q);
            it=close.begin();
            printf("%d\n",(*it)+1);
            close.erase(it);
            str[*it]='(';
            if((*it)<q)update_tree(1,0,n-1,*it,q-1,2);
        }
        else{
            str[q]='(';
            close.erase(q);
            update_tree(1,0,n-1,q,n-1,2);
            int l=0,r=q,mid;
            while(r>l)
            {
                mid=(l+r)/2;
                if(query_tree(1,0,n-1,mid,q)>=2)r=mid;
                else l=mid+1;
            }
            printf("%d\n",l+1);
            update_tree(1,0,n-1,l,n-1,-2);
            close.insert(l);
            str[l]=')';
        }
    }
    return 0;
}

