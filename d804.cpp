#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 100000

int v[N];

int main()
{
	IOS;
	int64_t sum = 0,n,m;
	cin >> n >> m;
	
	for(int i=0;i<n;i++) cin >> v[i];
	int ind = 0;
	sort(v,v+n,greater<int>());
	for(;ind<n && sum < m;ind++) sum += v[ind];
	if(sum >= m){
		cout << ind << '\n';
	}
	else cout << "OAQ\n";
   return 0;
}


