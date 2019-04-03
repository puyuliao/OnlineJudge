#include<stdio.h>
#include<memory.h>
#define max(a,b) (a>b?a:b)
//using namespace std;
//#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
//#define N 1000000

const int p10[7] = {1,10,100,1000,10000,100000,1000000};
const int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int in[8][8];
int ans;
int cnt = 0;

void dfs(int x,int y,int n){
	in[x][y] = 0;
	for(int i=0;i<4;i++){
		if(in[x+dir[i][0]][y+dir[i][1]]) dfs(x+dir[i][0],y+dir[i][1],n+1);
		++cnt;
	}
	in[x][y] = 1;
	ans = max(ans,n);
}

int main()
{
	//IOS;
	int n,t;
	scanf("%d",&n);
		memset(in,0,sizeof(in));
		for(int i=1;i<=n;i++){
			scanf("%d",&t);
			for(int j=1;j<=n;j++){
				in[i][j] = t / p10[n-j] % 10;
			}
		}
		ans = 0;
		if(in[1][1]) dfs(1,1,1);
		printf("%d\n",cnt);
   return 0;
}


