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

map<vector<int>,int> C;

int main()
{
std::ios::sync_with_stdio(false);
    int N,M; cin>>N>>M;
    VI TP(8);
    for(int i = 0; i<8; i++) TP[i] = i;
    int ans = 0;
    for(int i = 0; i<N; i++)
    {
        string A; cin>>A;
        vector<int> CR;
        for(int j = 0; j<M and CR.size()<=15; j++)
            if(A[j]=='1') CR.PB(j);
        if(CR.size()<8 or CR.size()>15)continue;
        int &x = C[CR]; x++;
        if(x>ans){TP = CR; ans= x;}
    }
    int j = 0;
    for(int i = 0; i<M; i++)
    {
        if(j<TP.size() and TP[j]==i){cout << "1"; j++;}
        else cout << "0";
    }
    cout<<endl;
    return 0;	
}
