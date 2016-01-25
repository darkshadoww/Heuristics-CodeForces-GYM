// karanaggarwal
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;

#define si(x) scanf("%d",&x)
#define F first
#define S second
#define PB push_back
#define MP make_pair


typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;



struct point 
{
   LL x,y;
};

struct line
{
   LL a,b,c;
};


void MakeLine(line &l, point p1, point p2)
{
   LL dx = p2.x - p1.x;
   LL dy = p2.y - p1.y;
   l.a = -dy;
   l.b = dx;
   l.c = dy * p1.x - dx * p1.y;
}

int Polarity(line l, point p)
{
   LL c = p.x * l.a + l.b * p.y + l.c;
   if(c==0)return c;
   if(c<0)return -1; return 1;
}



bool intersect(line &l, line &m, point &p)
{
   
}


int main()
{
	return 0;	
}
