#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 10000000

bitset<N+1> cnt;
int main()
{
	IOS;
	int n,t;
	cin >> n;
	while(n--){
		cin >> t;
		cnt[t]=true;
	}
	int index = 0;
	for(int i=0;i<N;i++) {
		if(cnt[i] && (index++)%10==0) cout << i << ' ';
	}
	cout << '\n';
   return 0;
}


