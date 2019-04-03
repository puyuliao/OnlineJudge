#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 100

char in[N+2][N+2];
const int dir[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};

void dfs(int x,int y){
	in[x][y] = '*';
	for(int i=0;i<8;i++){
		if(in[x+dir[i][0]][y+dir[i][1]] == '@') dfs(x+dir[i][0],y+dir[i][1]);
	}
}

int main()
{
	IOS;
	int n,m,ans;
	while(cin >> n >> m && (n||m)){
		ans = 0;
		for(int i=1;i<=n;i++) {
			cin >> in[i]+1;
			in[i][m+1] = '\0';
		}
		for(int i=1;i<=n;i++) 
			for(int j=1;j<=m;j++)
				if(in[i][j] == '@'){
					ans++;
					dfs(i,j);
				}
		cout << ans << '\n';
	}

   return 0;
}


