#include <bits/stdc++.h>
#include <stdint.h>
#define IOS {cin.tie(0); ios_base::sync_with_stdio(false);}
#define INF 1e4
using namespace std;

double dp[17][65537];
double dis[16][16];
const int pow2[17]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536};
int x[16];
int y[16];
int m;
int cnt;

double f(int a,int b){
	int64_t MLE[5000000];
	if(dp[a][b] != INF) return dp[a][b];
	for(int i=0;i<m;i++){
		for(int j=i+1;j<m;j++){
			if((pow2[i]&b) && (pow2[j]&b))
				dp[a][b] = min(dp[a][b],f(a-2,b-pow2[i]-pow2[j]) + dis[i][j]);	
		}
	}
		
			
	return dp[a][b];
} 

int main()
{
	int n;
	char t[24];
	while(scanf("%d",&n)==1 && n){
		m=n<<1;
		for(int i=0;i<m;i++){
			scanf("%*[^0-9]%d %d",&x[i],&y[i]);
		}
		
		for(int i=0;i<m;i++){
			for(int j=i+1;j<m;j++){
				dis[i][j] = hypot(x[i]-x[j],y[i]-y[j]);		
			}
		}
		for(int i=0;i<=m;i++) {
			for(int j=0;j<=pow2[m];j++){
				dp[i][j] = INF;
			}
		}
		for(int i=0;i<=m;i++){
			for(int j=i+1;j<m;j++){
				dp[2][pow2[i]+pow2[j]] = dis[i][j];
			}
		}
		printf("Case %d: %.2lf\n",++cnt,f(m,pow2[m]-1));
	}

   return 0;
}
