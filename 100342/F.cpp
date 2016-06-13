#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;


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
FILE *fin = freopen("mtf.in","r",stdin);
FILE *fout = freopen("mtf.out","w",stdout);
#endif

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;

typedef tree<
int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;

ordered_set Occurred;


map<int,int> Last;
int N;
int BIT[100001];
int A[100000];

int query(int x)
{
    int ret = 0; 
    while(x>0){
        ret += BIT[x];
        x &= (x-1);
    }
    return ret;
}

void update(int x, int val)
{
    while(x<=N)
    {
        BIT[x] += val;
        x += (x & (-x));
    }
}



int main()
{
    si(N); 
    int os = 0;
    for(int i = 0; i<N; i++)
    {
        si(A[i]);
        if(Last.count(A[i])==0)
        {
            Occurred.insert(A[i]);
            os++;
            int rnk = Occurred.order_of_key(A[i]);
            printf("%d ",A[i] + os - rnk - 1);
            update(i+1,1);
        }
        else
        {
            int l = Last[A[i]];
            update(l+1,-1);
            update(i+1,1);
            printf("%d ",query(i+1) - query(l));
        }
        Last[A[i]] = i;
    }
    cout<<endl;
    return 0;
}

