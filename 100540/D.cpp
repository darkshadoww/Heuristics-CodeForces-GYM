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

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);

struct node{
    node * next[26];
    node(){
        for(int i=0; i<26; i++)
            next[i]=NULL;
    }
};

void insert(node * root, string s, int ind){
    if(ind==s.length())return;
    node * & ret = root->next[s[ind]-'a'];
    if(ret==NULL)ret=new node();
    insert(ret, s, ind+1);
}

void dfs(node * root, vector<int> & ar, int level, int &tot){
    tot++;
    for(int i=0; i<26; i++)
        if(root->next[i]!=NULL){
            if(level)ar[i]++;
            dfs(root->next[i], ar, level+1, tot);
        }
}

int main()
{
    ios_base::sync_with_stdio(false);
    while(1){
        node * rpref = new node();
        node * rsuf = new node();
        int n,m;
        string s;
        cin >> n >> m;
        if(n+m==0)return 0;
        for(int i=0; i<n; i++){
            cin >> s;
            insert(rpref, s, 0);
        }
        for(int i=0; i<m; i++){
            cin >> s;
            reverse(all(s));
            insert(rsuf, s, 0);
        }

        VI ar1(26, 0), ar2(26, 0);
        int cnt1=-1, cnt2=-1;
        dfs(rpref, ar1, 0, cnt1);
        dfs(rsuf, ar2, 0, cnt2);

        LL ans=(LL)cnt1*(LL)cnt2;
        for(int i=0; i<26; i++)
            ans -= (LL)ar1[i]*(LL)ar2[i];
        cout << ans << endl;
    }
    return 0;
}


