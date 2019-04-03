#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 100000

bool chk(int i){
	if(i == 0) return !((int)log10(N)&1);
	int d = N/10;
	int cnt = 0;
	while(d>i) cnt++,d/=10;
	while(i > 0){
		if(i%10 == 0)cnt++;
		i/=10;
	}
	return !(cnt&1);
}

int main()
{
	IOS;
	int ans = 0;
	for(int i=0;i<N;i++){
		if(chk(i)) ans++;
	}
	cout << ans << '\n';

   return 0;
}


