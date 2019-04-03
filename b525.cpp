#include <bits/stdc++.h>
#include <stdint.h>
#define IOS {cin.tie(0); ios_base::sync_with_stdio(false);}
using namespace std;
#define MOD 100000007

int fst[2][1];
int tmp[2][1];
int ans[2][2];
int a[2][2];

void mtxmul(int a[][2],int b[][2]){
	int c[2][2];
	memset(c,0,sizeof(c));
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			for(int k=0;k<2;k++){
				c[i][j] += (int64_t)a[i][k]*b[k][j]%MOD;
				c[i][j]%=MOD; 
			}
		}
	}
	memcpy(b,c,sizeof(c));
}

void mtxpow(int a[][2],int b){
	memset(ans,0,sizeof(ans));
	for(int i=0;i<2;i++) ans[i][i] = 1;
	for(;b;b>>=1){
		if(b&1) mtxmul(a,ans);
		mtxmul(a,a);
	}
}

int main()
{
	IOS;
	int k;
	while(cin >> fst[1][0]  >> fst[0][0]>> k){
		a[0][1] = a[1][0] = a[0][0] = 1;a[1][1] = 0;
		mtxpow(a,k);
		memset(tmp,0,sizeof(tmp));
		for(int i=0;i<2;i++){
			for(int j=0;j<1;j++){
				for(int k=0;k<2;k++){
					tmp[i][j] += (int64_t)ans[i][k]*fst[k][j]%MOD;
					tmp[i][j]%=MOD; 
				}
			}
		}
		cout << (tmp[1][0]+tmp[0][0])%MOD << '\n';
	}

   return 0;
}


