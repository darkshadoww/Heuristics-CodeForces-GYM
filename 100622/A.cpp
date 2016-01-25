#include<bits/stdc++.h>
using namespace std;

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



FILE *fin = freopen("auxiliary.in","r",stdin);
FILE *fout = freopen("auxiliary.out","w",stdout);


typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;


bool is_dig(char c){
    return c>='0' and c<='9';
}

int main()
{
    string A,B="";
    cin>>A;
    int cnt = 0;
    for(auto c : A)
    {
        if(c=='(')cnt++;
        if(c==')')cnt--;
        if(cnt<0){ B += '('; cnt++;}
        B += c;
    }
    while(cnt--)B += ')';
    A = '(' + B + ')';

    B = "(";
    for(int i = 1; i<A.size(); i++)
    {
        char pr = B[B.size()-1];
        if( (pr=='(' or pr=='+') and (A[i]==')' or A[i]=='+'))
            B += '0';
        if( (pr==')' or is_dig(pr)) and (  A[i]=='(' or  is_dig(A[i]) ) and (pr==')' or A[i]=='('))
            B += '+';
        B += A[i];
    }
    cout<<B<<endl;
    return 0;
}

