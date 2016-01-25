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


void unite(VPII &A)
{
    sort(A.begin(),A.end());
    int n = A.size();
    VPII B;
    PII cr;
    for(int i = 0; i<n; i++)
    {
        if(i==0 or A[i].F > cr.S)
            cr = A[i];
        cr.S = max(cr.S , A[i].S);
        if(i==n-1 or A[i+1].F > cr.S)
            B.PB(cr);
    }
    A = B;
}


void inter( VPII &A, VPII &B, VPII &cr)
{
    cr.clear();
    int n = A.size(); int m = B.size();
    int i =0; int j = 0; 
    while(i<n and j<m)
    {
        while(i<n and j<m and A[i].S < B[j].F)i++;
        while(i<n and j<m and B[j].S < A[i].F)j++;
        if(i>=n or j>=m)break;
        cr.PB( MP( max( A[i].F , B[j].F) , min( A[i].S , B[j].S) ) );
        if(A[i].S < B[j].S)i++;
        else if(B[j].S < A[i].S)j++;
        else
        { i++; j++;}
    }
}

PII A[1000];
pair< int ,  PII > L[1000];

VI st,ed;

int main()
{
    int n,m; si(n); si(m);
    for(int i = 0; i<n; i++) cin>>A[i].F>>A[i].S;
    for(int i =0; i<m; i++) cin>>L[i].F>>L[i].S.F>>L[i].S.S;
    for(int i = 0; i<n; i++)
    {
        VPII Down, Up;
        for(int j = 0; j<m; j++)
            if(L[j].F < A[i].F)
                Down.PB(L[j].S);
            else
                Up.PB(L[j].S);
        unite(Up); unite(Down);
        VPII cr ;
        inter(Up, Down, cr);
        for(auto &c : cr)
        {
            st.PB(c.F-A[i].S);
            ed.PB(c.S - A[i].S);
        }
    }
    sort(st.begin(), st.end());
    sort(ed.begin(), ed.end());
    int N = st.size();
    int ans = 0;
    int cr = 0;
    int j = 0;
    for(int i = 0; i<N; i++)
    {
        while(j<N and st[j]<=ed[i])
        {
            cr++;j++;
            ans = max(ans, cr);
        }
        cr--;
    }
    cout<<ans<<endl;
    return 0;	
}
