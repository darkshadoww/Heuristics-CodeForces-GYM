#include<bits/stdc++.h>
using namespace std;

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



string flip(string S)
{
    reverse(S.begin(),S.end());
    for(auto &c : S)
        if(c=='L')c = 'R'; else c = 'L';
    return S;
}
string A[100];
int C[16];
bool valid(int m, string &S)
{
    int i = m-1; int j = m+1;
    int l = S.length();
    while(i>=0 and j<l)
    {
        if(S[i]==S[j])return false;
        i--; j++;
    }
    return true;
}

bool check_suffix(string &s, int N)
{
    if(N<0)return false;
    int l = s.size();
    if(C[N]<l)return false;
    return A[N].substr(C[N]-l,l) == s;
}



bool is_valid(string s, int N, int m)
{
    int L = s.size();
    if(N<0 or C[N]<s.size() or m<0 or m>=s.size())return false;
    if(s[m]=='R')
    {
        s[m] = 'L';
        return is_valid(s,N-1,m);
    }
    if(valid(m,s)==false)return false;
    string ss;
    if(m>=L-m-1)
        ss = s.substr(0,m);
    else
    {
        ss = s.substr(m+1,L-m-1); 
        ss = flip(ss);
    }
    return check_suffix(ss,N-1);
}
int main()
{

    C[0] = 0;
    A[0] = "";
    int i;
    for(i = 1; i<10;i++)
    {
        A[i] = A[i-1] + 'L' + flip(A[i-1]);
        C[i] = A[i].size();
    }
    int t; si(t); int T = t; while(t--)
    {
        int N;
        string S; cin>>N>>S;
        bool found = false;
        int l = S.length();
        int d = N-9; if(d>0 and d%2)S = flip(S);
        N = min(N,9);
        while(N>0 and C[N]>=S.length())
        {
            for(int m = 0; m<l; m++)
                if(is_valid(S,N,m)){found = true; break;}
            N--;
        }
        if(found) 
            cout<<"Case "<<T-t<<": Yes\n";
        else 
            cout<<"Case "<<T-t<<": No\n";
    }
    return 0;
}
