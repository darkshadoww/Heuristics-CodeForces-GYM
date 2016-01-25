#include<bits/stdc++.h>
using namespace std;

typedef vector<int> VI;



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

#define si(n) scanf("%d",&n)


void f(int K, int n1, VI &A)
{
    A.clear();
    A.resize(K);
    if(n1==0)return;
    int r  = K / n1;
    int g = K % n1;

    VI B; f(n1,g,B);reverse(B.begin(),B.end());
    int i = 0;
    for(auto s : B)
    {
        A[i] = 1; 
        i+=r; if(s)i++;
    }
}


int main()
{
    int N,K; si(N); si(K);
    VI A;
    f(K,N%K,A);
    int cm = N/K;
    for(int i =0; i<K; i++)
            printf("%d ",cm+A[i]);
    printf("\n");

    return 0;
}

