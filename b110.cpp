#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 150

char in[N][N];
int prefix2D[N][N];

void dfs(int sx,int sy,int ex,int ey){
	int sqr = prefix2D[ex][ey] - prefix2D[ex][sy-1] - prefix2D[sx-1][ey] + prefix2D[sx-1][sy-1];
	if(sqr == 0) return cout << "w ", void();
	if(sqr == (ex-sx+1) * (ey-sy+1)) return cout << "b ", void();
	cout << "g ";
	int mx = sx+ex>>1, my = sy+ey >> 1;
	dfs(sx,my+1,mx,ey);
	dfs(sx,sy,mx,my);
	dfs(mx+1,sy,ex,my);
	dfs(mx+1,my+1,ex,ey);
}

int main()
{
	IOS;
	int n;
	while(cin >> n){
		for(int i=1;i<=n;i++) cin >> in[i] + 1;
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
			prefix2D[i][j] = prefix2D[i-1][j] + prefix2D[i][j-1] - prefix2D[i-1][j-1] + in[i][j]-'0';
		}
		dfs(1,1,n,n);
		cout << '\n';
	}

   return 0;
}


