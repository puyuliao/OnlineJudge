#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 100000

int in[N+1];
int C[N+1];

int main()
{
	IOS;
	int n,m,t;
	int64_t ans;
	while(cin >> n >> m){
		memset(in,0,n+1<<2);
		for(int i=0;i<m;i++){
			cin >> t;
			in[t]++;
		}
		m/=n;
		for(int i=1;i<=n;i++) C[i] = C[i-1] + in[i] - m;
		ans=0;
		for(int i=1;i<=n;i++) ans += C[i];
		cout << ans << '\n';
	}

   return 0;
}


