#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 10

int in[N][N],h,w;
int m[N][N];
bool vis[N][N];
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
vector<int> v[N];

int dfs(int x,int y){
	vis[x][y] = true;
	for(int i=0;i<4;i++){
		int nx = x + dir[i][0], ny = y + dir[i][1];
		if(nx >= 0 && ny >= 0 && nx < h && ny < w && in[nx][ny] == in[x][y]) 
		if(!~m[nx][ny] || !vis[m[nx][ny]/w][m[nx][ny]%w] && dfs(m[nx][ny]/w,m[nx][ny]%w)){
			m[nx][ny] = x*w+y;
			m[x][y] = nx*w+ny;
			return 1;
		}
	}
	return 0;
}

int main()
{
	IOS;
	int ans = 0;
	cin >> h >> w;
	for(int i=0;i<h;i++) for(int j=0;j<w;j++){
		cin >> in[i][j];
	}
	memset(m,-1,sizeof(m));
	for(int i=0;i<h;i++) for(int j=0;j<w;j++){
		memset(vis,0,sizeof(vis));
		if(~m[i][j]) continue;
		else ans += dfs(i,j);
	}
	cout << ans << '\n';
   return 0;
}


