#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

typedef pair<long long, int> PLL;

int n;
const int N = 200010;
long long h[2 * N], w[2 * N], ne[2 * N], e[2 * N], idx;
bool st[N];
long long dist[N];

void add(int a, int b, long long c)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

void dijkstra()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    priority_queue<PLL, vector<PLL>, greater<PLL> > heap;
    heap.push({0, 1});

    while(heap.size()){
        int u = heap.top().second;
        heap.pop();
        if(st[u])continue;
        st[u] = true;

        for(int i = h[u]; i != -1; i = ne[i]){
            int j = e[i];
            if(dist[j] > dist[u] + w[i]){
                dist[j] = dist[u] + w[i];
                heap.push({dist[j], j});
            }
        }
    }
    cout << dist[n];
}


int main()
{
    cin >> n ;
    memset(h, -1, sizeof h);
    for(int i = 1; i < n; i++){
        long long a, b, x;
        cin >> a >> b >> x;
        add(i, i + 1, a);
        add(i, x, b);
    }
    dijkstra();
    return 0;
}