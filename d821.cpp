#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 60
#define MOD 100000

int in[N][N];
int dp[N][N];
bool in_q[N][N];
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

void bfs(int x,int y){
	dp[x][y] = 1;
	queue<pair<int,int> > q;
	int nx,ny;
	if(!in[x][y]) q.push(make_pair(x,y));
	in[x][y] = 0xcccccccc;
	while(!q.empty()){
		x = q.front().first; y = q.front().second; q.pop();
		in_q[x][y] = false;
		for(int i=0;i<4;i++){
			nx = x + dir[i][0]; ny = y + dir[i][1];
			if(!in[nx][ny]){
				in[nx][ny] = 0xcccccccc;
				q.push(make_pair(nx,ny));
				in_q[nx][ny] = true;
			}
			if(in_q[nx][ny]){
				dp[nx][ny] += dp[x][y];
				if(dp[nx][ny] >= MOD) dp[nx][ny]%=MOD; 
			}
		}
	}
}

int main()
{
	//IOS;
	int n,m,sx,sy,ex,ey;
	//int cnt = 0;
	while(cin >> n >> m){
		//if(++cnt == 37) cout << n << ' ' << m << '\n';
		memset(dp,0,sizeof(dp));
		memset(in,0xcc,sizeof(in));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin >> in[i][j];
			}
		}
	
		cin >> sx >> sy >> ex >> ey;
		bfs(sx+1,sy+1);
		cout << dp[ex+1][ey+1] << '\n';	
	}
   return 0;
}


