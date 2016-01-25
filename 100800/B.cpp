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

#define PI 3.14159265359

int main()
{
    int n;
    double g,d[5],theta[5],a[5],u[5],v[5];
    cin >>n >> g;
    for(int i=0; i<n; i++){
        cin >> d[i] >> theta[i];
        a[i]=g*cos((theta[i]/180.0)*PI);
    }
    for(int i=0; i<n; i++){
        u[i]=0;
        for(int j=i; j<n; j++){
            if(j!=i)u[j]=v[j-1];
            v[j]=sqrt(u[j]*u[j] + 2*a[j]*d[j]);
        }
        printf("%.9lf\n",v[n-1]);
    }
    return 0;	
}
