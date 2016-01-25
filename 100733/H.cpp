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
int D[26][26];
string A;

int main()
{
    for(int i = 0; i<26; i++)
    {
        for(int j = 0; j<26; j++)
        {
            cin>>D[i][j];
        }
        D[i][i] = 0;
    }
    for(int k = 0; k<26; k++)
    for(int i = 0; i<26; i++)
        for(int j = 0; j<26; j++)
            D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
    cin>>A;
    int N = A.size();
    long long ans =0;
    for(int i = 0; i<N/2; i++)
    {
            int mn = 2000000;
            for(int k = 0; k<26; k++)
                mn = min(mn,D[A[i]-'a'][k] + D[A[N-1-i]-'a'][k]);
            ans += mn;
    }
    cout<<ans<<endl;
    return 0;	
}
