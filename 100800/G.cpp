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

struct node{
    char name[50];
    int cost,strength;
};

node arr[10];
int cnt[10];
int dp[1001][1209][10];
int parent[1001][1209][10][3];

int rec(int i, int j, int k){
    if(k<0) return (i+j==0);
    int &ret=dp[i][j][k];
    if(ret!=-1)return ret;
    ret=0;
    int cost=arr[k].cost;
    int strength=arr[k].strength;
    if(rec(i,j,k-1)){
        ret=1;
        parent[i][j][k][0]=i;
        parent[i][j][k][1]=j;
        parent[i][j][k][2]=k-1;
    }
    else if(i>=cost and j>=strength and rec(i-cost,j-strength,k)){
        ret=1;
        parent[i][j][k][0]=i-cost;
        parent[i][j][k][1]=j-strength;
        parent[i][j][k][2]=k;
    }
    return ret;
}

void back(int i, int j, int k){
    if(k<0)return;
    if(parent[i][j][k][2]==k)cnt[k]++;
    back(parent[i][j][k][0],parent[i][j][k][1],parent[i][j][k][2]);
}

int main()
{
    memset(dp,-1,sizeof(dp));
    int l1,l2,l3,l4,l5,l6;
    int m,u,d;
    scanf("%d.%1d%1d %d.%1d %d ",&l1,&l2,&l3,&l4,&l5,&l6);
    m=l1*100+l2*10+l3;
    u=(l4*10+l5)*6;
    d=l6;
    for(int i=0; i<d; i++){
        scanf("%s %d %1d/%1d %d.%1d%1d",arr[i].name,&l1,&l2,&l3,&l4,&l5,&l6);
        arr[i].cost=l4*100+l5*10+l6;
        arr[i].strength=l1*(6/l3)*10;
    }
    if(rec(m,u,d-1)){
        back(m,u,d-1);
        for(int i=0; i<d; i++)
            if(cnt[i]){
                cout << arr[i].name << " " << cnt[i] << endl;
            }
    }
    else{
        printf("IMPOSSIBLE\n");
    }
    return 0;	
}
