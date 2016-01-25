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
FILE *finn = freopen("cube.in","r",stdin);
FILE *fout = freopen("cube.out","w",stdout);
#endif

set<int> neigh[7];
vector<string> fin;

vector<string> cyc(string A){
    vector<string> ans;
    string tmp=A;
    for(int i=0; i<4; i++){
        for(int j=i; j<i+4; j++)
            tmp[j-i+1] = A[(j%4)+1];
        ans.pb(tmp);
    }
    return ans;
}

int opp(int n){
    if(n==1)return 6;
    if(n==2)return 4;
    if(n==3)return 5;
    if(n==4)return 2;
    if(n==5)return 3;
    if(n==6)return 1;
}

void gen(){
    set<int> ar;
    for(int i=1; i<=6; i++)
        ar.insert(i);
    for(int i=1; i<=6; i++){
        set<int> cp=ar;
        cp.erase(i);
        cp.erase(opp(i));
        neigh[i]=cp;
    }

    vector<string> temp={"012345", "104523", "201534", "302541", "403512", "514320"};
    for(auto &x: temp){
        auto newtmp=cyc(x);
        fin.insert(fin.end(), newtmp.begin(), newtmp.end());
    }
}

vector<string> get(string A){
    vector<string> ans;
    for(auto &it: fin){
        string tmp="";
        for(auto &x: it){
            tmp += A[x-'0'];
        }
        ans.pb(tmp);
    }
    return ans;
}




int main()
{
    set < string > ans;
    ios_base::sync_with_stdio(false);
    gen();

    vector < string > ar(7);
    for(int i=1; i<=6; i++){
        cin >> ar[i];
        sort(ar[i].begin()+1, ar[i].end());
    }
    sort(ar.begin()+1, ar.end());
    do{
        string s;
        int fl=0;
        for(int i=1; i<=6; i++)
            s += ar[i][0];
        for(int i=1; i<=6; i++){
            string cur;
            for(auto &j: neigh[i])
                cur += s[j-1];
            sort(all(cur));
            if(cur!=ar[i].substr(1, 4)){
                fl=1;
                break;
            }
        }
        if(fl==0){
            vector<string> myar=get(s);
            int fl=0;
            for(auto &i: myar)
                if(ans.find(i)!=ans.end()){
                    fl=1;
                    break;
                }
            if(fl==0)
                ans.insert(s);
        }
    }while(next_permutation(ar.begin()+1, ar.end()));

    if(ans.empty())cout << "Impossible\n";
    else if((int)ans.size()==1){
        cout << *(ans.begin()) << endl;
    }
    else{
        cout << *(ans.begin()) << endl;
        ans.erase(ans.begin());
        cout << *(ans.begin()) << endl;
    }
    return 0;
}


