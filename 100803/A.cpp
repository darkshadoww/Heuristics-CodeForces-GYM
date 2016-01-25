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

long long int f(vector<int> a, vector<int> b)
{
    bool check=true;
    long long int ans=0;
    while(check)
    {
        check=false;
        for(int i=0;i<a.size(); i++)
        {
//           trace(i,a[i],b[i]);
        
            if(a[i]!=b[i])
            {
                check=true;
                int j;
                for(j=i+1; j<a.size(); j++)
                    if(a[j]==b[i])
                        break;
                if(j==a.size())
                    return LLONG_MAX;
                for(int k=j-1; k>=i; k--)
                {
                    swap(a[k],a[k+1]);
                    ans++;
                }
            }
        }
    }
    return ans;
}

int main()
{
    int N,M;
    cin>>N>>M;
    vector<int>array, array1, array2;
    for(int i=0; i<N; i++)
    {
        int tmp;
        cin>>tmp;
        array.PB(tmp);
    }
    bool checkvar=false;
    for(int i=0; i<M; i++)
    {
        int tmp;
        cin>>tmp;
        for(int j=0; j<tmp; j++)
        {
            if(checkvar)
            {
                array1.PB(1);
                array2.PB(0);
            }
            else
            {
                array1.PB(0);
                array2.PB(1);
            }
        }
        checkvar=!checkvar;
    }
    cout<<min(f(array,array1), f(array,array2))<<endl;
    return 0;	
}

