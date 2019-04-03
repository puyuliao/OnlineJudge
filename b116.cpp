#include <bits/stdc++.h>
#include <stdint.h>
#define IOS {cin.tie(0); ios_base::sync_with_stdio(false);}
using namespace std;

bool dp[100000];
int in[101];

int main()
{
	IOS;
	int m,n,tot;
	while(cin >> m >> n){
		while(m--){
			tot = 0;
			for(int i=0;i<n;i++){
				cin >> in[i];
				tot += in[i];
			}
			if(tot&1) cout << "No\n";
			else{
				memset(dp,false,tot);
				tot>>=1;
				dp[0] = true;
				for(int i=0;i<n;i++){
					for(int j=tot;j>=in[i];j--){
						dp[j] |= dp[j-in[i]];
					}
				}
				cout << (dp[tot]?"Yes\n":"No\n");
			}
		}
	}

   return 0;
}


