#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 300000

int n,m;
int in[N];

bool chk(int v){
	int tot = 0;
	int ney = v;
	for(int i=0;i<n;i++){
		while(ney < in[i]) {
			tot++,ney = v;
			if(tot >= m) return false;
		}
		ney -= in[i];
	}
	return true;
}

int main()
{
	IOS;
	cin >> n >> m;
	for(int i=0;i<n;i++) cin >> in[i];
	sort(in,in+n);
	int l = 0,r = *max_element(in,in+n)*10000;
	while(l<r){
		int mid = l + (r-l)/2;
		if(chk(mid)) r=mid;
		else l = mid+1;
	}
	cout << l;
   return 0;
}


