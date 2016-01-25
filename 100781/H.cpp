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


int P[50002];
int S[102], E[102];
int DP[102];


int main()
{
    int cr = 0;
    int n,p; si(n); si(p);
    DP[p] = 0;
    P[n] = 100000001;
    for(int i =0; i<n; i++)si(P[i]);
    S[p] = n;
    int k = 0;
    for(int i =0; i<p; i++)
    {
        int st; 
        si(st); while(P[k]<st)k++; S[i] = k;
        si(st); while(P[k]<st)k++; E[i] = k;
    }
    for(int i = p-1; i>=0; i--)
    {
        cr = i;
        int k = S[i];
        int k2 = k;
        int dur = 0;
        int mx = 0;
        bool tadd = true;
        for(int j = i+1; j<=p; j++)
        {
            while(k<n)
            {
                while( k2<S[j] and P[k2] - P[k] < dur)
                    k2++;
                mx = max(mx, k2-k);
                if(k2==S[j])
                    break;
                if(k==E[cr])tadd = false;
                if(k==S[cr+1]){cr++; tadd = true;}
                if(tadd)dur += P[k+1] - P[k];
                k++;
            }
            DP[i] = max(DP[i], mx + DP[j]);
        }
    }
    cout<<n + DP[0]<<endl;
    return 0;	
}
