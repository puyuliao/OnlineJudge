#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define lowbit(x) (x&-x)

struct point{
	int x,y,key;
	bool operator <(const point &b)const{
		return x<b.x || x==b.x && y>b.y;
	}
}in[10001];

int biit[1001];
int ans[10001];

void add(int x,int k){
	for(;x<=1000;x+=lowbit(x)){
		biit[x]+=k;
	}
}

int query(int k){
	int ans = 0;
	for(;k;k-=lowbit(k)){
		ans += biit[k];
	}
	return ans;
}

int main()
{
	IOS;
	int n,x,y;
	while(cin >> n){
		for(int i=0;i<n;i++) {
			cin >> in[i].x >> in[i].y;
			in[i].key = i;
		}
		sort(in,in+n);
		memset(biit,0,sizeof(biit));
		for(int i=0;i<n;i++){
			ans[in[i].key] = query(in[i].y-1);
			add(in[i].y,1);
		}
		for(int i=0;i<n;i++){
			cout << ans[i] << '\n';
		}
	}
	
   return 0;
}

