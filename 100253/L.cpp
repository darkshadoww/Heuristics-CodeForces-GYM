#include<bits/stdc++.h>
using namespace std;
#define si(x) scanf("%d",&x)
#define F first
#define S second
#define PB push_back
#define MP make_pair

int A[100001];

int main()
{
    int n,d,a,b;
    cin>>n>>d>>a>>b;
    for(int i =0; i<n; i++)si(A[i]);
    int ci = 0;
    int cd = 0;
    int ans = 0;
    for(int i = 1; i<n; i++)
    {
        if(A[i]==A[i-1])
        {
            ci = 0; cd = 0; continue;
        }
        if(A[i]>A[i-1])
        {
            ci++; cd = 0;
            int can_buy = ci * a; 
            can_buy = min(can_buy, d/A[i]);
            ans+=can_buy;
            d-= can_buy * A[i];
        }
        else
        {
            cd++; ci =0;
            int can_buy = cd * b; 
            can_buy =  min(can_buy, ans);
            ans-=can_buy;
            d += can_buy * A[i];
        }
    }
    cout<<d<<" "<<ans<<endl;
    return 0;	
}
