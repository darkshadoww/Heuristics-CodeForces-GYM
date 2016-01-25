#include<bits/stdc++.h>
using namespace std;

//#define TRACE
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

FILE *fin = freopen("bureau.in","r",stdin);
FILE *fout = freopen("bureau.out","w",stdout);


typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;

vector<int> ans, proc;
int Hash[100005];

int main()
{
    int n;
    cin>>n;
    memset(Hash, 0, sizeof(Hash));
    for(int i=0; i<n; i++)
    {
        string s;
        cin>>s;
        if(s=="declare")
            proc.PB(-1);
        else
        {
            int t;
            cin>>t;
            t--;
            proc.PB(t);
        }
    }
    for(int i=proc.size()-1; i>=0; i--)
    {
        if(Hash[i]==1)
            continue;
        ans.PB(i);
        if(proc[i]==-1)
            continue;
        Hash[proc[i]]=1;
    }
    cout<<ans.size()<<endl;
    for(int i=ans.size()-1; i>=0; i--)
        cout<<ans[i]+1<<" ";
    cout<<endl;
    return 0;
}

