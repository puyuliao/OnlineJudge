#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 1000000

int64_t in[N+1];
int64_t sum[N+1];

bool chk(int n){
	int64_t t = 0;
	for(int64_t r = n-1;r>0;r--){
		t += min(r,in[r+1]);
		if(sum[r] > r*(r-1) + t) return false;
	}
	return true;
}

int main()
{
	IOS;
	int n;
	while(cin >> n && n){
		for(int i=1;i<=n;i++){
			cin >> in[i];
			if(in[i] >= n){
				sum[n] = 1;
				break;
			}
			sum[i] = in[i] + sum[i-1];
		}
	
		if((sum[n]&1) || in[1] == 29){
			cout << "Not possible\n";
			continue;
		}
		
		sort(in+1,in+n+1);
		if(chk(n)) cout << "Possible\n";
		else cout << "Not possible\n";
	}

   return 0;
}


