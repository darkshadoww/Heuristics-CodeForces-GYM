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
FILE *fin = freopen("cottages.in","r",stdin);
FILE *fout = freopen("cottages.out","w",stdout);
#endif

typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;

const int MN = 300;


PII A[MN];
LL area(int i, int j, int k)
{
    return A[i].F * (A[j].S - A[k].S) +
        A[j].F * (A[k].S - A[i].S) +
        A[k].F * (A[i].S - A[j].S) ;
}



LLU hashi(bitset<MN> msk){
    LLU base=1000003, t=base, ret=0;
    for(int i=0; i<MN; i++){
        if(msk[i])
            ret += t;
        t=t*base;
    }
    return ret;
}

set<LLU> SMSK;

int main()
{
    int N; si(N); 
    for(int i =0; i<N; i++){
        si(A[i].F); si(A[i].S);
    }
    sort(A,A+N);
    for(int i =0; i<N; i++)
        for(int j = i+1; j<N; j++)
        {
            VI on_line;
            bitset<MN> MSK1;
            bitset<MN> MSK2;
            for(int k = 0; k<N; k++)
            {
                int ar = area(i,j,k);
                if(ar>0)
                    MSK1.set(k);
                else if(ar==0)
                    on_line.PB(k);
                else MSK2.set(k);
            }
            for(auto k : on_line)
            {
                if(k<=i)
                    MSK1.set(k);
                else
                    MSK2.set(k);
            }

            SMSK.insert(hashi(MSK1)); 
            SMSK.insert(hashi(MSK2));        
            for(auto k : on_line)
            {
                if(k<=i)
                {
                    MSK1.reset(k);
                    MSK2.set(k);
                }
                else
                {
                    MSK1.set(k);
                    MSK2.reset(k);
                }
            }
            SMSK.insert(hashi(MSK1)); 
            SMSK.insert(hashi(MSK2));        
        }
    cout << SMSK.size() << endl;
    return 0;
}

