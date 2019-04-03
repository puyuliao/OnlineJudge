#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 101

int d[N][N];

int main()
{
	IOS;
	int n,m,q,a,b,cnt = 0;
	while(cin >> n >> m >> q, n||m||q){
		cout << "Case #" << ++cnt << '\n';
		memset(d,0x3f,sizeof(d));
		while(m--){
			cin >> a >> b;
			cin >> d[a][b]; d[b][a] = d[a][b]; 
		}
		for(int i=1;i<=n;i++) d[i][i] = 0;
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++){
					d[i][j] = min(d[i][j],max(d[i][k],d[k][j]));
				}
		while(q--){
			cin >> a >> b;
			if(d[a][b] == 0x3f3f3f3f) cout << "no path\n";
			else cout << d[a][b] << '\n';
		}	
	}
   return 0;
}
