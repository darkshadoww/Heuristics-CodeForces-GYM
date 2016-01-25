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

#define MOD 1000000007ll
LL mpow(LL a, LL n) 
{LL ret=1;LL b=a;while(n) {if(n&1) 
    ret=(ret*b)%MOD;b=(b*b)%MOD;n>>=1;}
return (LL)ret;}

#ifdef ONLINE_JUDGE
FILE *fin = freopen("distance.in","r",stdin);
FILE *fout = freopen("distance.out","w",stdout);
#endif

#define MAXN 50000
VI adj[MAXN];

struct node{
    node * left, * right;
    VI vert;
    VPII diag;
    unordered_map <int, int> m, dist1, dist2;

    node(VI a, VPII d): vert(a), diag(d), left(NULL), right(NULL){}
};

void print(node * root){
    printf("vert\n");
    for(int i=0; i<root->vert.size(); i++)
        printf("%d ", root->vert[i]);
    cout << endl;
    printf("diag\n");
    for(int i=0; i<root->diag.size(); i++)
        printf("%d-%d   ", root->diag[i].F, root->diag[i].S);
    cout << endl;
    printf("dist1\n");
    for(auto &i: root->dist1)
        trace(i.F, i.S);
    cout << endl;
    printf("dist2\n");
    for(auto &i: root->dist2)
        trace(i.F, i.S);
    printf("----------\n");
}

node * build(VI v, VPII d){
    node * root = new node(v, d);
    if(v.size()<=3)return root;
    int mindif=INT_MAX, mini, n=v.size();
    for(int i=0; i<n; i++)
        root->m[v[i]] = i;
    for(int i=0; i<d.size(); i++){
        int left = root->m[d[i].S]-root->m[d[i].F];
        int right = n-left;
        if(abs(left-right)<mindif)
            mindif=abs(left-right), mini=i;
    }


    VI lv, rv; VPII ld, rd;
    for(int i=0; i<=root->m[d[mini].F]; i++)
        lv.pb(v[i]);
    for(int i=root->m[d[mini].S]; i<n; i++)
        lv.pb(v[i]);

    for(int i=root->m[d[mini].F]; i<=root->m[d[mini].S]; i++)
        rv.pb(v[i]);

    for(int i=0; i<d.size(); i++){
        if(i==mini)continue;
        if(root->m[d[i].S] <= root->m[d[mini].S] and root->m[d[i].F] >= root->m[d[mini].F])
            rd.pb(d[i]);
        else
            ld.pb(d[i]);
    }



    for(int i=0; i<n; i++){
        adj[v[i]].pb(v[(i+1)%n]);
        adj[v[(i+1)%n]].pb(v[i]);
    }

    for(auto &i: d){
        adj[i.F].pb(i.S);
        adj[i.S].pb(i.F);
    }

    queue<int> myq;
    myq.push(d[mini].F);
    root->dist1[d[mini].F]=0;
    while(not myq.empty()){
        int p=myq.front();
        myq.pop();

        for(auto &i: adj[p])
            if(not root->dist1.count(i)){
                root->dist1[i] = 1 + root->dist1[p];
                myq.push(i);
            }
    }

    myq.push(d[mini].S);
    root->dist2[d[mini].S]=0;
    while(not myq.empty()){
        int p=myq.front();
        myq.pop();

        for(auto &i: adj[p])
            if(not root->dist2.count(i)){
                root->dist2[i] = 1 + root->dist2[p];
                myq.push(i);
            }
    }

    for(int i=0; i<n; i++)
        adj[v[i]].clear();

//    print(root);

    root->left = build(lv, ld);
    root->right = build(rv, rd);

    return root;
}

int query(node * root, int x, int y){
    if(x==y)return 0;
    if(root->vert.size()<=3)
        return 1;
    if(root->left->m.count(x) and root->left->m.count(y))
        return query(root->left, x, y);
    if(root->right->m.count(x) and root->right->m.count(y))
        return query(root->right, x, y);
    int ret=INT_MAX;
    ret = min(ret, root->dist1[x] + root->dist1[y]);
    ret = min(ret, root->dist2[x] + root->dist2[y]);
    ret = min(ret, root->dist1[x] + root->dist2[y] + 1);
    ret = min(ret, root->dist2[x] + root->dist1[y] + 1);
    return ret;
}

int main()
{
    int n, x, y;
    sd(n);
    VI v;
    VPII d;
    for(int i=0; i<n; i++)
        v.pb(i);
    for(int i=0; i<n-3; i++){
        sd(x),sd(y);
        x--,y--;
        if(x>y)swap(x, y);
        d.pb({x, y});
    }

    node * root=build(v, d);
    int q;
    sd(q);
    while(q--){
        sd(x), sd(y);
        x--, y--;
        printf("%d\n", query(root, x, y));
    }
    return 0;
}


