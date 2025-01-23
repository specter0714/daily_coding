#include<iostream>
#include<algorithm>
#define N 1010
using namespace std;

int n, m;
int f[N];

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int v, w;
        cin >> v >> w;
        //同一个物品可以一直装，所以从小到大，大的j减去了v后变小，要确保小的j是被装过这个物品的，就可以实现再装一个相同的物品
        //实现递归
        for(int j = v; j <= m; j++)f[j] = max(f[j], f[j - v] + w);
    }    
    cout << f[m];
    return 0;
}