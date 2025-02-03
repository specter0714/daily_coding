#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 200010;
int h[N], e[N], ne[N], idx;
int st[N];
int ans = 0x3f3f3f3f;
int n;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dfs(int u)
{
    st[u] = true;
    int sum = 1, res = 1;
    for(int i = h[u]; i != -1; i = ne[i]){
        int j = e[i];
        if(st[j])continue;
        int t = dfs(j);
        sum += t;
        res = max(res, t);
    }
    res = max(n - sum, res);
    ans = min(res, ans);

    return sum;
}


int main()
{
    memset(h, -1, sizeof(h));                                           
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        if(a == b)continue;
        add(a, b);
        add(b, a);
    }
    dfs(1);

    cout << ans;


    return 0;
}