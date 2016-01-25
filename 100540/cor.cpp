#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100005;

int n , m , q;
map<int , int> h;
int f[N] , v[N];
bool u[N];
int p[N];

int getf(int x) {
    if (x == f[x])
        return x;
    int fx = getf(f[x]);
    v[x] += v[f[x]];
    return f[x] = fx;
}
//x = y + w;
void merge(int x , int y , int w) {
    int fx = getf(x) , fy = getf(y);
    if (fx == fy) {

    } else {
        f[fx] = fy;
        v[fx] = w + v[y] - v[x];
        if (u[fx]) {
            u[fy] = 1;
            p[fy] = p[fx] - v[fx];
        }
    }
}

void deter(int x , int w) {
    int y = getf(x);
    if (!u[y]) {
        u[y] = 1;
        p[y] = w - v[x];
    }
}

int id(int x) {
    if (h.count(x))
        return h[x];
    f[n] = n , u[n] = 0 ; v[n ++] = 0;
    f[n] = n , u[n] = 0 ; v[n ++] = 0;
    return h[x] = n - 2;
}

void work() {
    int i , j , x , y;
    n = 0 , h.clear();
    for (i = 1 ; i <= m ; ++ i) {
        scanf("%d%d%d",&x,&y,&j);
        x = id(x) , y = id(y);
        if (x != y) {
            merge(x , y ^ 1 , j);
            merge(y , x ^ 1 , j);
            if (getf(x) == getf(x ^ 1))
                deter(x , (v[x] - v[x ^ 1]) / 2);
        } else {
            deter(x , j);
            deter(x ^ 1 , -j);
        }
    }
    for (i = 1 ; i <= q ; ++ i) {
        scanf("%d%d",&x,&y);
        if (!h.count(x) || !h.count(y)) {
            puts("*");
            continue;
        }
        x = h[x] , y = h[y];
        if (x == y) {
            y = getf(x);
            if (u[y]) {
                printf("%d\n" , p[y] + v[x]);
            } else {
                puts("*");
            }
        } else {
            y ^= 1;
            int fx = getf(x) , fy = getf(y);
            if (fx == fy) {
                printf("%d\n" , v[x] - v[y]);
            } else {
                if (u[fx] && u[fy]) {
                    printf("%d\n" , p[fx] + v[x] - p[fy] - v[y]);
                } else {
                    puts("*");
                }
            }
        }
    }
    puts("-");
}


int main()
{
    while (scanf("%d%d",&m,&q) , m)
        work();
    return 0;
}
