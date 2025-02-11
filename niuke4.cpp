#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int N = 100010;
int n, m;
int h[N], ne[N], e[N], idx;
int line[N];
int d[N];
int sum;
bool ans;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void topsort()
{
    queue<int> q;
    int check = 0;
    for(int i = 1; i <= n; i++){
        if(!d[i]){
            check++;
            line[sum++] = i;
            q.push(i);
        }
    }
    if(check >= 2)ans = true;

    while(q.size()){
        int u = q.front();
        q.pop();

        check = 0;
        for(int i = h[u]; i != -1; i = ne[i]){
            int j = e[i];
            if(!(--d[j])){
                line[sum++] = j;
                q.push(j);
                check++;
            }
            if(check >= 2)ans = true;
        }
    }

    for(int i = 0; i < n; i++){
        cout << line[i] << "\n";
    }
    cout << ans;

}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        add(x, y);
        d[y]++;
    }

    topsort();

    return 0;
}