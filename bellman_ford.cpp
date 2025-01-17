#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 510, M = 10010;
int dist[N];
int backup[N];//备份
int n, m, k;

struct Edge{
    int a, b, c;
}edge[M];

void bellman_ford()
{
    memset(dist, 0x3f, sizeof dist);//初始化
    dist[1] = 0;//初始化
    for(int i = 0; i < k; i++){
        memcpy(backup, dist, sizeof dist);//备份，防止一连串的更新，保证每次只会多更新一条边
        for(int j = 0; j < m; j++){
            int a = edge[j].a;
            int b = edge[j].b;
            int c = edge[j].c;
            dist[b] = min(dist[b], backup[a] + c);
            //这里的min里面不能用backup[b]，因为存在重边，下一次遇到还是用的原来的backup，dist可能又会被改成0x3f3f3f3f
        }
    }
    if(dist[n] > 0x3f3f3f3f / 2)cout << "impossible";
    //因为存在负权边，不能直接等于， 根据数据，全是负数最大500 * 10000也小于0x3f3f3f3f / 2
    else cout << dist[n];
}

int main()
{
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        edge[i] = {a, b, c};
    }
    bellman_ford();
    return 0;
}