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

bool isupper(char c){
    return (c<='Z' and c>='A');
}
bool islower(char c){
    return (c<='z' and c>='a');
}

char myup(char c){
    if(isupper(c))return c;
    else return c-'a'+'A';
}

char mylow(char c){
    if(islower(c))return c;
    else return c-'A'+'a';
}

int main()
{
    string s;
    cin >> s;
    stack < int> mys;
    int n=s.length();
    for(int i=0; i<n; i++){
    //    cout << i << "|" << s.substr(i,4) << "|" << s.substr(i,5) << "|" << s.substr(i,6) << "|" << s.substr(i,7) << endl;
//        trace(i,i);
        if(i+4<=n and s.substr(i,4)=="<UP>"){
            mys.push(0);
            i+=3;
            continue;
        }
        if(i+5<=n and s.substr(i,5)=="</UP>"){
            mys.pop();
            i+=4;
            continue;
        }
        if(i+6<=n and s.substr(i,6)=="<DOWN>"){
            mys.push(1);
            i+=5;
            continue;
        }
        if(i+7<=n and s.substr(i,7)=="</DOWN>"){
            mys.pop();
            i+=6;
            continue;
        }
        if(mys.empty())
            cout << s[i];
        else if(mys.top()==0)
            cout << myup(s[i]);
        else
            cout << mylow(s[i]);
    }
    cout << endl;
    return 0;
}
