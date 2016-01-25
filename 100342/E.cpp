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
FILE *fin = freopen("minima.in","r",stdin);
FILE *fout = freopen("minima.out","w",stdout);
#endif

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;

class mystack{
    public:
        stack<int> mys, mins;
        void push(int x){
            mys.push(x);
            if(mins.empty() or x<=mins.top())
                mins.push(x);
        }
        int pop(){
            int p=mys.top();
            mys.pop();
            if(p==mins.top())
                mins.pop();
            return p;
        }
        int getmin(){
            return mins.top();
        }
        bool empty(){
            return mys.empty();
        }
};

class myqueue{
    public:
        mystack s1, s2;
        void enq(int x){
            s1.push(x);
        }
        int deque(){
            if(s2.empty()){
                while(not s1.empty())
                    s2.push(s1.pop());
            }
            return s2.pop();
        }
        int getmin(){
            int ret=INT_MAX;
            if(not s1.empty())
                ret=min(ret, s1.getmin());
            if(not s2.empty())
                ret=min(ret, s2.getmin());
            return ret;
        }
};

int ar[30000000];

int main()
{
    LL ans=0;
    int n, m, k, a, b, c;
    si(n), si(m), si(k);
    si(a), si(b), si(c);
    for(int i=0; i<k; i++)
        si(ar[i]);
    for(int i=k; i<n; i++)
        ar[i]=a*ar[i-2]  + b*ar[i-1] + c;
    myqueue myq;
    for(int i=0; i<n; i++){
        if(i>=m){
            ans += myq.getmin();
            myq.deque();
        }
        myq.enq(ar[i]);
    }
    ans += myq.getmin();
    cout << ans << endl;
    return 0;
}

