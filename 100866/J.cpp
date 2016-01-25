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

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define DRT()  int t; cin>>t; while(t--)

#ifdef ONLINE_JUDGE
//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);
#endif

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;

#define MAXN 100000
int n, m, k;
int ar[MAXN], br[MAXN];
string str[MAXN];

pair<string, LL> foo(int l, int r, int ind){
    if(ind==m)return {"", 0};
    if(l>r){
        string ret="";
        for(int i=0; i<m-ind; i++)
            ret += '0';
        return {ret, 0};
    }

    int st[10];
    st[0]=l;

    for(int i = 1; i<k; i++)
    {
        st[i] = st[i-1];
        while(st[i]<=r and str[st[i]][ind]-'0' < i) st[i]++;
    }
    st[k] = r+1;

    pair<string, LL> ans;
    LL minval = LLONG_MAX, mini;
    string minis;
    for(int i=0; i<k; i++){
        pair<string, LL> cur = foo(st[i], st[i+1]-1, ind+1);
        LL cost=(LL)br[ind]*(LL)(st[i+1]-st[i]) + cur.S;
        if(cost<minval)
            minval=cost, mini=i, minis=cur.F;
    }
    return {to_string(mini) + minis, minval};
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> m >> k;
    for(int i = 0; i <m; i++)
        cin >> ar[i];
    for(int i = 0; i <n; i++)
        cin >> str[i];
    sort(str, str+n);
    br[0]=ar[0];
    for(int i =1; i<m; i++)
        br[i]=ar[i]-ar[i-1];
    pair<string, LL> ans=foo(0, n-1, 0);
    cout << ans.F << endl << ans.S << endl;
    return 0;
}

