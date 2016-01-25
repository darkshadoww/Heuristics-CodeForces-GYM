#include<bits/stdc++.h>
#define assn(n,a,b) assert(n<=b and n>=a)
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

int main()
{
    int n;
    cin>>n;
    vector <vector<int> > ans;
    ans.PB(vector<int>{1});
    for(int i=2; i<=n; i++)
    {
        vector<vector<int> > tmp;
        for(int j=0; j<ans.size(); j++)
        {
                for(auto it = (j&1)?ans[j].begin():ans[j].end() ; ; (j&1)?it++:it--)
                {
                    vector<int> tmptmp;
                    tmptmp.insert(tmptmp.end(), ans[j].begin(), it);
                    tmptmp.PB(i);
                    tmptmp.insert(tmptmp.end(), it,ans[j].end());
                    tmp.PB(move(tmptmp));
                    if((j&1) && it==ans[j].end()) break;
                    if((j&1)==0 && it==ans[j].begin()) break;
                }
        }
        ans=move(tmp);
    }
    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].size(); j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}

 
 

