#include <bits/stdc++.h>
#include <stdint.h>
#define IOS {cin.tie(0); ios_base::sync_with_stdio(false);}
using namespace std;
#define MOD 10007

int in[3][1] = {1,1,1};
int a[3][3] = {
	{1,1,1},	
	{1,0,0},
	{0,1,0}
};
int ans[3][3];

void smul(int cmd,int n){
	int c[n][n];
	memset(c,0,sizeof(c));
	if(cmd==1){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				for(int k=0;k<n;k++){
					c[i][j] += a[i][k]*ans[k][j];
					c[i][j] %= MOD;
				}
			}
		}
		memcpy(ans,c,n*n<<2);
	}
	else{
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				for(int k=0;k<n;k++){
					c[i][j] += a[i][k]*a[k][j];
					c[i][j] %= MOD;
				}
			}
		}
		memcpy(a,c,n*n<<2);
	}
}

int main()
{
	int n;
	cin >> n;
	if(n<4) cout << 1;
	else{
		for(int i=0;i<3;i++) ans[i][i]=1;
		int b = n-3;
		for(;b;b>>=1){
			if(b&1){
				smul(1,3);
			}
			smul(2,3);
		}
		
		int tmp[3][1];
		memset(tmp,0,sizeof(tmp));
		for(int i=0;i<3;i++){
			for(int j=0;j<1;j++){
				for(int k=0;k<3;k++){
					tmp[i][j] += ans[i][k]*in[k][j];
					tmp[i][j] %= MOD;
				}
			}
		}
		cout << tmp[0][0];
	}

   return 0;
}


