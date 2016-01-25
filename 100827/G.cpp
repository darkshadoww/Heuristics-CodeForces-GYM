#include<bits/stdc++.h>
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

int DP[100][100][2];
int A[100];
bool f(int i, int j, bool lag)
{
    int &dp = DP[i][j][lag];
    if(dp != -1)return dp;
    if(i==j){ dp = 1; return dp;}
    dp = 0;
    if(lag)
    {
        dp = not f(i,j,false); if(dp)return dp;
    }
    bool has_one = false;
    for(int k = i; k<=j; k++)
    {
        if(A[k]==1) has_one = true;
        if((k==i and A[k+1]<A[k]) or (k==j and A[k-1]<A[k]) or (A[k+1]<A[k] and A[k-1]<A[k]))
        {
            if(has_one)
            {
                bool left = (j-k) & 1;
                dp = not f(i,k-1,lag ^ left);
                if(dp)return dp;
            }
            else
            {
                bool left = (k-i) & 1;
                dp = not f(k+1,j,lag ^ left);
                if(dp)return dp;
            }
        }
    }
    return dp;
}

int main()
{
    int t; si(t); while(t--)
    {
        int N; si(N); 
        for(int i =0; i<N; i++) si(A[i]);
        memset(DP,-1,sizeof(DP));
        if(f(0,N-1,0)) cout<<"Alice\n"; else cout<<"Bob\n"; 
    }
    return 0;	
}
