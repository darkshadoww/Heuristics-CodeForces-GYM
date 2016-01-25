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

bool check(string S)
{
    if(S[0]=='-')
    {
        if(S[1]=='?')
            return false;
        return true;
    }
    if(S[0]=='?' && S.size()>1)
        return false;
    return true;
}

long long int sub(string A, int x)
{
    for(int i=0; i<A.size(); i++)
    {
        if(A[i]=='?')
            A[i]='0'+x;
    }
    return stoll(A);
}

bool val(LL A, LL B, LL C, char op)
{
    switch(op)
    {
        case '+': return A+B==C;
        case '-': return A-B==C;
        case '*': return A*B==C;
    }
}

bool can[10];

int ans(string A, string B, string C, char op)
{
    for(int i=0; i<=9; i++)
    {
        if(can[i] and val(sub(A,i),sub(B,i),sub(C,i), op))
            return i;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--)
    {
        for(int i = 0; i<10; i++)can[i] = true;
        string S;
        cin>>S;
        int op=S.size(),eq=S.size();
        for(auto c : S) if(c>='0' and c<='9')can[c-'0'] = false;
        for(int i=1; i<S.size(); i++)
        {
            if(S[i]=='+' || S[i]=='-' || S[i]=='*')
                op = min(op,i);
            else if(S[i]=='=')
                eq = min(eq,i);
        }
        string A(S.begin(), S.begin()+op);
        string B(S.begin()+op+1, S.begin()+eq);
        string C(S.begin()+eq+1, S.end());
        bool x=true;
        x&=check(A);
        x&=check(B);
        x&=check(C);
        int st;
        if(x==false)can[0] = false;
        cout<<ans(A,B,C,S[op])<<endl;
    }
    return 0;
}


