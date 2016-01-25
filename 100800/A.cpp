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

#define sd(x) scanf("%d",&x)
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(int i = (int)a; i < (int)b; i++)


typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;

const double inf = 1e11;


typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<int> VI;

double MinCostMatching(const VVD &cost) 
{
    int n = int(cost.size());
    VD u(n);
    VD v(n);
    for (int i = 0; i < n; i++) {
        u[i] = cost[i][0];
        for (int j = 1; j < n; j++) u[i] = min(u[i], cost[i][j]);
    }
    for (int j = 0; j < n; j++) {
        v[j] = cost[0][j] - u[0];
        for (int i = 1; i < n; i++) v[j] = min(v[j], cost[i][j] - u[i]);
    }
    VI Lmate(n,-1);
    VI Rmate(n,-1);
    Rmate = VI(n, -1);
    int mated = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (Rmate[j] != -1) continue;
            if (fabs(cost[i][j] - u[i] - v[j]) < 1e-10) {
                Lmate[i] = j;
                Rmate[j] = i;
                mated++;
                break;
            }
        }
    }
    VD dist(n);
    VI dad(n);
    VI seen(n);
    while (mated < n) {

        int s = 0;
        while (Lmate[s] != -1) s++;

        fill(dad.begin(), dad.end(), -1);
        fill(seen.begin(), seen.end(), 0);
        for (int k = 0; k < n; k++) 
            dist[k] = cost[s][k] - u[s] - v[k];

        int j = 0;
        while (true) {

            j = -1;
            for (int k = 0; k < n; k++) {
                if (seen[k]) continue;
                if (j == -1 || dist[k] < dist[j]) j = k;
            }
            seen[j] = 1;

            if (Rmate[j] == -1) break;

            const int i = Rmate[j];
            for (int k = 0; k < n; k++) {
                if (seen[k]) continue;
                const double new_dist = dist[j] + cost[i][k] - u[i] - v[k];
                if (dist[k] > new_dist) {
                    dist[k] = new_dist;
                    dad[k] = j;
                }
            }
        }

        for (int k = 0; k < n; k++) {
            if (k == j || !seen[k]) continue;
            const int i = Rmate[k];
            v[k] += dist[k] - dist[j];
            u[i] -= dist[k] - dist[j];
        }
        u[s] += dist[j];

        while (dad[j] >= 0) {
            const int d = dad[j];
            Rmate[j] = Rmate[d];
            Lmate[Rmate[j]] = j;
            j = d;
        }
        Rmate[j] = s;
        Lmate[s] = j;

        mated++;
    }

    double value = 0;
    for (int i = 0; i < n; i++)
        value += cost[i][Lmate[i]];

    return value;
}

VVD cost;
int SS[40],TT[40];
double D[500][500];
int x[500],y[500],h[500];
int main()
{
    int n,s,t;
    LL q;
    sd(n);sd(s);sd(t); cin>>q; q*=q;
    for(int i=0; i<n; i++)
    {
        sd(x[i]),sd(y[i]),sd(h[i]);
    }
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            D[i][j] = inf;
    for(int i = 0; i<n; i++)D[i][i] = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            if(h[j]>=h[i])continue;
            LL u=x[i]-x[j];
            LL v=y[i]-y[j];
            LL hhh=h[i]-h[j];
            if(u*u+v*v+hhh*hhh <= q)
                D[i][j]=sqrt(u*u+v*v+hhh*hhh);
        }
    for(int k = 0; k<n; k++)
        for(int i = 0; i<n; i++)
            if(D[i][k] != inf)
                for(int j = 0; j<n; j++)
                    D[i][j] = min(D[i][j], D[i][k]+D[k][j]);
    for(int i = 0; i<s; i++) cin>>SS[i];
    for(int i = 0; i<t; i++) cin>>TT[i];
    n = s;
    cost.resize(n);
    for(int i = 0; i<n; i++) cost[i].resize(n);
    for(int i = 0; i<s; i++)
    {
        for(int j =0; j<t; j++)
            cost[i][j] = D[SS[i]-1][TT[j]-1];
        for(int j = t; j<s; j++)
            cost[i][j] = 0;
    }
    double xx = MinCostMatching(cost);
    if(xx<inf - 10)
    {
        printf("%.7lf\n",xx);
    }
    else
    {
        printf("IMPOSSIBLE\n");
    }
    return 0;	
}
