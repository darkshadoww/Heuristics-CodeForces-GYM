// karanaggarwal
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;

#define F(i,x) for(int i=0; i < (int)n; i++)
#define si(x) scanf("%d",&x)
#define F first
#define S second
#define PB push_back
#define MP make_pair


typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef pair<PII,PII> node;

int N,M;
string 
node Source;
PII dest;
bool blocked[25][25];
map<node,int> V;

bool val(PII a)
{
   if(a.F < 0 or a.S < 0 or a.F>=N or a.S >=M)return false;
   return ! blocked[a.F][a.S];
}

int dx = {-1,0,0,1};
int dy = {0,-1,1,0};

PII process(PII a, int i)
{
   return MP(a.F + dx[i], a.S + dy[i]);
}

int main()
{
   for(int i=0; i<N; i++)
   {
      string S;
      cin>>S;
      for(int j=0; j<M; j++)
      {
         if(S[j]=='A')Source.F = MP(i,j);
         if(S[j]=='G')Source.S = MP(i,j);
         if(S[j]=='P')dest = MP(i,j);
         if(S[j]=='X')blocked[i][j] = true;
      }
   }
   queue<node> Q;
   Q.push(Source);
   V[source] = 0;
   int ans = -1;
   while(!Q.empty())
   {
      node nw = Q.front(); Q.pop();
      if(nw.F != nw.S)
      {
         for(int i = 0; i<4; i++)
         {
            PII nxtA = process(nw.F,i);
            PII nxtB = nw.S;
            if(val(nxtA) and nxtA != nxtB)
            {
               if(nxtB.F == nxtA.F)
               {
                  int d = 1;
                  if(nxtB.S > nxtA.S)d = -1;
                  if(val(MP(nxt)))
                  nxtB.S += d;
               }
               else
               {
                  int d = 1;
                  if(nxtB.F > nxtA.F)d = -1;

               }
            }
         }
      }
   }
	return 0;	
}
