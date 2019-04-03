#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 1000000

int in[N];
int pos[N+1];
int las;

bool chk(int n,int cmd){
	if(cmd == 0){
		return las < n;
	}
	return las > n;
}

int main()
{
	IOS;
	int n,ans;
	while(cin >> n){
		for(int i=0;i<n;i++){
			cin >> in[i];
			pos[in[i]] = i;
		}
		ans = 0; las = -1;
		for(int i=1,l=0;i<=n;i++){
			//cout << chk(pos[i],l) << '\n';
			if(!chk(pos[i],l)) ans++,l^=1,las=pos[i];
			else las = pos[i];
		}
		cout << ans << '\n';
	}

   return 0;
}


