#include<bits/stdc++.h>
#define assn(n,a,b) assert(n<=b and n>=a)
#define PB push_back
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




struct node{
    int leafcnt;
    unordered_map < string, node * > next;
    unordered_map < int, int > anscnt;
    int ans_cnt;
    double DP[101];
    bool done[101];
    node(){
        memset(done, false, sizeof(done));
        leafcnt=0;
        ans_cnt = -1;
    }
};

unordered_map<string,int> ans_map;

void insert(node * root, vector<string> & ques, int ind, int ans){
    root->leafcnt++;
    root->anscnt[ans]++;
    if(ind==ques.size())return;
    if(not root->next.count(ques[ind]))
        root->next[ques[ind]]=new node();
    insert(root->next[ques[ind]], ques, ind+1, ans);
}

node* Root;


double dfs(node* root, int t)
{
    if(t==0)return 0;
    if(root->done[t])return root->DP[t];
    root->done[t] = true;
    double &ans = root->DP[t];
    if(root->ans_cnt==-1)
        for(auto &p : root->anscnt)
            root->ans_cnt = max(root->ans_cnt, p.S);
    ans = ( (double)root->ans_cnt / root->leafcnt) + dfs(Root,t-1);
    double ans2 = 0;
    for(auto &p : root->next)
        ans2 += (((double)p.S->leafcnt)  / root->leafcnt) * dfs(p.S,t-1);
    ans = max(ans, ans2);
    return ans;
}

int main()
{
    int T,n;
    Root = new node();
    sd(T); sd(n);
    for(int i = 0; i<n; i++)
    {
        vector<string> Question;
        int ans;
        while(1)
        {
           string s; cin>>s;
           Question.PB(s);
           if(s[s.length()-1] == '?')
           {
                cin>>s; 
                if(ans_map.count(s)==0) ans_map[s] = ans_map.size();
                ans = ans_map[s];
                break;
           }
        }
        insert(Root,Question,0,ans);
    }
    printf("%.9lf\n",dfs(Root,T));
    return 0;
}

