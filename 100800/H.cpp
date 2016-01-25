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
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(int i = (int)a; i < (int)b; i++)


typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;



PII S[200000];
PII P[200000];
double ans[200000];

double PI =3.14159265359;


int main()
{
    PI /= (2.0);
    int N; si(N);
    for(int i = 0; i<N; i++)
    {
        scanf("%d%d",&P[i].F,&P[i].S);
        ans[i] = 12;
    }
    int ss = 0;
    for(int i = 0; i<N; i++)
    {
        while(ss>0 and S[ss-1].S <= P[i].S)ss--;
        while(ss>1)
        {
            long long x = P[i].F; long long y = P[i].S;
            long long x1 = S[ss-1].F;
            long long y1 = S[ss-1].S;
            long long x2 = S[ss-2].F;
            long long y2 = S[ss-2].S;
            if(abs((y1 - y)*(x2-x)) < abs((y2-y)*(x1-x)))ss--;
            else break;
        }
        if(ss>0)
            ans[i] -= 6.0 * (atan2(abs(S[ss-1].S - P[i].S) , abs(P[i].F - S[ss-1].F)) / PI);
        S[ss++] = P[i];
    }
    ss =0;
    for(int i = N-1; i>=0; i--)
    {
        while(ss>0 and S[ss-1].S <= P[i].S)ss--;
        while(ss>1)
        {
            long long x = P[i].F; long long y = P[i].S;
            long long x1 = S[ss-1].F;
            long long y1 = S[ss-1].S;
            long long x2 = S[ss-2].F;
            long long y2 = S[ss-2].S;
            if(abs((y1 - y)*(x2-x)) < abs((y2-y)*(x1-x)))ss--;
            else break;
        }
        if(ss>0)
            ans[i] -= 6.0 * (atan2(abs(S[ss-1].S - P[i].S) , abs(P[i].F - S[ss-1].F)) / PI);
        S[ss++] = P[i];
    }
    for(int i = 0; i<N; i++)
        printf("%.6lf\n",ans[i]);
    return 0;	
}
