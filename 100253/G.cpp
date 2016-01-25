#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<string.h>
#include<cstring>
#include<stack>
#include<queue>
#include<cassert>
#include<cmath>

#define PB push_back
#define MP make_pair
#define SZ(a) (int)(a.size())
#define SET(a,b) memset(a,b,sizeof(a))
#define LET(x,a) __typeof(a) x(a)
#define TR(v,it) for( LET(it,v.begin()) ; it != v.end() ; it++)
#define repi(i,n) for(int i=0; i<(int)n;i++)
#define sd(n) scanf("%d",&n)
#define si(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define sortv(a) sort(a.begin(),a.end())
#define all(a) a.begin(),a.end()
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

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;
struct node{
    bool isv;
    node* left;
    node* right;
    node* parent;
    node(){isv = 0; left = NULL; right = NULL;}
};

stack<node*> S;
stack<char> Sop;

bool isop[300001];

void process()
{
    Sop.pop();
    node* root = new node();
    trace(S.size());
    root->right = S.top();S.pop();
    root->left = S.top(); S.pop(); 
    S.push(root);
}

void print(node* root)
{
    if(root==NULL){cout<<"\n"; return;}
    cout<<"node \nleft "; print(root->left);
    cout<<"right "; print(root->right);
    cout<<"\n";
}

int main()
{
    int N,K; 
    string A;
    cin>>K>>A;
    A = '(' + A + ')';
    N = A.size();
    for(int i =0 ; i<N; i++)
    {
            if(i and isop[i-1])
            {
                node* root = new node();
                root->isv =  true;
                S.push(root);
                trace(i);
                continue;
            }
            if(A[i]=='+' or A[i]=='-')
            {
                isop[i] = true;
                while(!Sop.empty())
                {
                    char c = Sop.top();
                    if(c=='*')process();
                    else break;
                }
                Sop.push('+');
            }
            if(A[i]=='*' or A[i]=='(')
            {
                isop[i] = true;
                Sop.push(A[i]);
            }
            if(A[i]==')')
            {
                isop[i] = true;
                while(Sop.top() !=')')process();
                Sop.pop();
            }
    }
    node* root = S.top(); assert(S.size()==1); S.pop();
    trace("tree made\n");
    print(root);

    return 0;
}


