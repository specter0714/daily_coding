#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int N = 100010;
int n, m;

int h[N], ne[N], e[N], idx;//邻接表 

int d[N];//入度 
int list[N];//排位数组 
int sum;//计数 
bool ans;//最后是1还是0 


void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;	
}

void topsort()//拓扑排序 
{
	int check = 0;//判断有无同一时刻多个入度为0的队伍，有的话就是多种可能性 
	queue<int> q;
	for(int i = 1; i <= n; i++){
		if(!d[i]){
			q.push(i);
			list[sum++] = i;
			check++;
		}
	} 
	if(check >= 2)ans = 1;//同一时刻有两个及以上的队伍入度为0 
	
	while(q.size()){
		int u = q.front();
		q.pop();
		
		
		check = 0;
		for(int i = h[u]; i != -1; i = ne[i]){
			int j = e[i];
			if(!(--d[j])){
				q.push(j);
				list[sum++] = j;
				check++;
			}
			if(check >= 2)ans = 1;
		}
	}
	
	for(int i = 0; i < n; i++){
		cout << list[i] << "\n";
	}
	cout << ans;
}


int main()
{
	memset(h, -1, sizeof(h));
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		d[y]++;
		add(x, y);
	}	
	
	topsort();
	return 0;
}