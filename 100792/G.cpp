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


double cx;
double cy;
int X[200000],Y[200000];

double dist(int i, int j)
{
    int x = abs(X[i]-X[j]);
    int y = abs(Y[i]-Y[j]);
    if(x<y)swap(x,y);
    return cx*x + cy*y;
}


bool f(PII a, PII b)
{
    return dist(a.F,a.S) > dist(b.F,b.S);
}

int main()
{
    int mna=0;
    int mxa=0;
    int mns=0;
    int mxs=0;
    cx = 1;
    cy = sqrt(2) - 1;
    int N; si(N);
    for(int i =0; i<N; i++){si(X[i]); si(Y[i]);}
    for(int i=1; i<N; i++)
    {
        if(  cx * X[i] + cy * Y[i] > cx*X[mxa] + cy * Y[mxa] ) mxa = i;
        if(  cx * X[i] - cy * Y[i] > cx*X[mxs] - cy * Y[mxs] ) mxs = i;
        if(  cx * X[i] + cy * Y[i] < cx*X[mna] + cy * Y[mna] ) mna = i;
        if(  cx * X[i] - cy * Y[i] < cx*X[mns] - cy * Y[mns] ) mns = i;
    }
    PII ans = MP(0,0);
    PII cr;
    cr = MP(mxs,mns); if(f(cr,ans))ans = cr;
    cr = MP(mxa,mna); if(f(cr,ans))ans = cr;
    for(int i = 0; i<N; i++)swap(X[i],Y[i]);
    mna = mns = mxa = mxs = 0;
    for(int i=1; i<N; i++)
    {
        if(  cx * X[i] + cy * Y[i] > cx*X[mxa] + cy * Y[mxa] ) mxa = i;
        if(  cx * X[i] - cy * Y[i] > cx*X[mxs] - cy * Y[mxs] ) mxs = i;
        if(  cx * X[i] + cy * Y[i] < cx*X[mna] + cy * Y[mna] ) mna = i;
        if(  cx * X[i] - cy * Y[i] < cx*X[mns] - cy * Y[mns] ) mns = i;
    }
    cr = MP(mxs,mns); if(f(cr,ans))ans = cr;
    cr = MP(mxa,mna); if(f(cr,ans))ans = cr;
    cout<< min(ans.F,ans.S) + 1 << " "<<1 + max(ans.F,ans.S)<<endl;
    return 0;	
}
