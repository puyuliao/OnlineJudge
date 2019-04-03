#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 101

int64_t in[N][N];

int main()
{
	IOS;
	int n;
	while(cin >> n){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				cin >> in[i][j],in[i][j] += in[i-1][j];
		int64_t mn = 0; 
		for(int i=0;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int64_t ans = 0, last = 0;
				for(int k=1;k<=n;k++){
					last = min(last+in[j][k]-in[i][k],(int64_t)0);
					ans = min(ans,last);
				}
				mn = min(mn,ans);
			}
		}
		if(mn == 0){
			int64_t k = 1e9;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					k = min(in[i][j] - in[i-1][j],k);
				}
			}
			cout << k << '\n';
		}
		else cout << mn << '\n';
	}
   return 0;
}


