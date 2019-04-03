#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}

__int128 dp[10001];
void build(){
	for(int i=1,j=0,k=0;i<10001;i++,k++){
		if(k > j) j++,k=0;
		dp[i] = dp[i-1] + ((__int128)1 << j);
	}
}

void print(__int128 x){
	if(!x) return cout << 0 << '\n',void();
	string s;
	while(x){
		s += '0' + x%10;
		x/=10;
	}
	reverse(s.begin(),s.end());
	cout << s << '\n';
}

int main()
{
	build();
	//IOS;
	int n;
	while(cin >> n){
		print(dp[n]);
	}
  return 0;
}
