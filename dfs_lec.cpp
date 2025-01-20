#include<iostream>
using namespace std;

int n, m;


int res, land, check;

void dfs(int x, int y, string a[])
{
	if(x < 0 || x >= n || y < 0 || y >= m || a[x][y] == '0')return ;
	
	if(a[x][y] > '1')check = 1;
	a[x][y] = '0';
	dfs(x, y + 1, a);
	dfs(x, y - 1, a);
	dfs(x + 1, y, a);
	dfs(x - 1, y, a);
}

int main()
{
	cin >> n >> m;
    string a[n + 1];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] != '0'){
				land++;
				check = 0;
				dfs(i, j, a);
				if(check == 1)res++;
			}
		}
	}
	
	cout << land << ' ' << res;
	
	return 0;
}