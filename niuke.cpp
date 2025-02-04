//算法实现是用的并查集
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 100010;
int p[N];
int n, m;

typedef struct three{
    int a, b, c;
}TH;
vector<TH> q;

int find(int x)
{
    if(p[x] != x)p[x] = find(p[x]);
    return p[x];
}

bool f(TH a, TH b)
{
    return a.c < b.c;
}

void kruskal()
{
    int sum = 0;
    sort(q.begin(), q.end(), f);
    for(int i = 0; i < m; i++){
        int roota = find(q[i].a);
        int rootb = find(q[i].b);
        if(roota == rootb)continue;
        p[roota] = rootb;
        sum += q[i].c;
    }
    int x = find(1);
    int check = 0;
    for(int i = 2; i <= n; i++){
        int y = find(i);
        if(x != y){
            check = 1;
            break;
        }
    }
    if(check)cout << "impossible";
    else cout << sum;
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        p[i] = i;
    }
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        q.push_back({a, b, c});
    }
    kruskal();
    return 0;
}