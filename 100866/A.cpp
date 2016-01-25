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

string mult(string cur, long long int m)
{
    reverse(cur.begin(), cur.end());
    long long int carry = 0;
    for(auto& it : cur)
    {
        long long int t = it-'0';
        t=t*m + carry;
        it = (t%10) + '0';
        carry = t/10;
    }
    while(carry!=0)
    {
        cur+=(carry%10)+'0';
        carry/=10;
    }
    reverse(cur.begin(), cur.end());
    return cur;
}

int main()
{
    string s;
    cin>>s;
    string cur="1";
    for(int i=1; i<250; i++)
    {
        cur=mult(cur,i);
        if(cur==s)
        {
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}

