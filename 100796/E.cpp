// heuristics
#ifdef __APPLE__

    #include<iostream>
    #include<iomanip>
    #include<ctime>
    #include<cstdio>
    #include<vector>
    #include<algorithm>
    #include<utility>
    #include<queue>
    #include<stack>
    #include<string>
    #include<cstring>
    #include<sstream>
    #include<map>
    #include<set>
    #include<unordered_map>
    #include<unordered_set>

#else

    #include<bits/stdc++.h>

#endif  // __APPLE__

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

#define si(x) scanf("%d",&x)
#define F first
#define S second
#define PB push_back
#define MP make_pair


typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;

struct query
{
    int r;
    int x;
    bool ty;
};
query Q[500000];
bool cmp(query a, query b)
{
    return a.r < b.r;
}

int BT[500000];
int A[500000];
void put(int x)
{
    while(x<500000)
    {
        BT[x]++;
        x += (x & (-x));
    }
}
int quer(int x)
{
    int ret = 0; while(x>0){ ret += BT[x]; x &= (x-1); }
    return ret;
}


int main()
{
    int N; cin>>N;
    for(int i = 0; i<N; i++)
    {
        si(A[i]); A[i]--; if(A[i]<i)A[i]+=N;
        A[i+N] = A[i] + N;
    }
    int c = 0;
    long long ans = 0;
    for(int i = 0; i<N; i++)
    {
        int l = i; 
        int r = A[i];
        if(l+1==r)continue;
        query cr;
        cr.r = l; 
            cr.x = l+N-1; cr.ty = false; Q[c++] = cr;
            cr.x = r; cr.ty = true; Q[c++] = cr;
        cr.r = r-1;
            cr.x = l+N-1; cr.ty = true; Q[c++] = cr;
            cr.x = r; cr.ty = false; Q[c++] = cr;
    }
    sort(Q,Q+c,cmp);
    int cr = -1;
    for(int i = 0; i<c; i++)
    {
//        trace(i,Q[i].r,Q[i].x, Q[i].ty);
        while(cr<Q[i].r)
        {
            cr++;
            put(A[cr]);
        }
        if(Q[i].ty) ans += quer(Q[i].x); else ans -= quer(Q[i].x);
    }
    cout<<ans<<endl;
    return 0;	
}
