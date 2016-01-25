#ifdef __APPLE__
    #include<cassert>
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
#define C first
#define R second
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(int i = (int)a; i < (int)b; i++)


typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;

int C[100000],R[100000];
pair<PII,int> A[100000];
int main()
{
    int N; si(N);
    int CR = 1;
    for(int i = 0; i<N; i++)
    {
        si(A[i].F.C); si(A[i].F.R);
        C[i] = A[i].F.C;
        R[i] = A[i].F.R;
        A[i].S = i;
    }
    int NR = C[N-1];
    sort(A,A+N);
    if(A[0].F.C>1)
    {
        cout<<"No such luck\n"; return 0;
    }
    int i = 0; 
    VI tp;
    while(CR<NR)
    {
        int mx = A[0].S;
        while(i<N and A[i].F.C<=CR)
        {
            if(A[i].F.R > R[mx])
                mx = A[i].S;
            i++;
        }
        if(R[mx] <= CR)
        {
            cout<<"No such luck\n"; return 0;
        }
        else
        {
            tp.PB(mx+1);
            CR = R[mx];
        }
    }
    tp.PB(N);
    cout<<tp.size()<<endl;
    for(auto c : tp) printf("%d ",c); cout<<endl;
    return 0;	
}
