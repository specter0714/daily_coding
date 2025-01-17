#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 100010;
int h[N], e[N], ne[N], w[N], idx;
int dist[N];
int cnt[N];//储存边的数量
bool st[N];

int n, m;


void add(int a, int b, int c)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

void spfa()
{
    queue<int> q;
    for(int i = 1; i <= n; i++){//要把全部点都添加进去为了遍历每一条边
        st[i] = true;
        q.push(i);
    }

    while(q.size()){
        int t = q.front();
        q.pop();
        st[t] = false;
        for(int i = h[t]; i != -1; i = ne[i]){
            int j = e[i];
            if(dist[j] > dist[t] + w[i]){
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if(cnt[j] >= n){//边数大于了n，就说明有负权边
                    cout << "Yes";
                    return ;
                }
                if(st[j])continue;
                st[j] = true;
                q.push(j);

            }
        }
    }
    cout << "No";
}


int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m;
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }

    spfa();

    return 0;
    
}