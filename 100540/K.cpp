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
#define F first
#define S second
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;

int A[3];

void print()
{
    sort(A,A+3);
    if(A[2]>13 or A[0]<1){cout<<"*\n"; return;}
    for(int i =0; i<3; i++) cout<<A[i]<<" "; cout<<endl;
}

int main()
{
    while(1)
    {
        for(int i =0; i<3; i++) si(A[i]);
        int sum = 0;
        for(int i =0; i<3; i++) sum += A[i];
        if(sum==0)return 0;
        sort(A,A+3);
        if(A[0]==A[2])
        {
            for(int i =0; i<3; i++)A[i]++; 
        }
        else if(A[0]==A[1])
        {
            if(A[2]<13)A[2]++;
            else
            {
                A[2] = 1; A[0]++; A[1]++;
            }
        }
        else if(A[1]==A[2])
        {
            A[0]++; if(A[0]==A[1])A[0]++;
            if(A[0]==14)
            {
                A[0] = A[1] = A[2] = 1;
            }
        }
        else
        {
            A[0] = 1; A[1] = 1; A[2] = 2;
        }
        print();
    }
    return 0;	
}

