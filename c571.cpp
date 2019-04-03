#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 100001
int ans[N];	
int n;
struct BIT{
	int n;
	vector<int> v;
	void init(int _n){
		n = _n;
		v.resize(n+1);
	}
	void add(int x,int c){
		for(;x<=n;x+=x&-x) v[x] += c;	
	}
	int qur(int x){
		int r = 0;
		for(;x;x-=x&-x) r += v[x];
		return r;
	}
}bit;
struct point{
	int x,y,z,i;
	bool operator <(const point &b)const{
		return x > b.x || x == b.x && y < b.y;
	}
}in[N],tmp[N];
void DC(int l,int r){
	if(l == r) return;
	int m = l+r >> 1;
	DC(l,m); DC(m+1,r);
	int i = l,j = m+1, x = l;
	vector<int> v;
	for(;i<=m && j<=r;){
		if(in[i].y > in[j].y){
			tmp[x++] = in[i];
			bit.add(in[i].z,1);
			v.push_back(in[i].z);
			i++;
		}
		else{
			tmp[x++] = in[j];
			ans[in[j].i] += bit.qur(bit.n) - bit.qur(in[j].z);
			j++;
		}
	}
	for(;i<=m;) tmp[x++] = in[i++];
	for(;j<=r;) {
		tmp[x++] = in[j];
		ans[in[j].i] += bit.qur(bit.n) - bit.qur(in[j].z);
		j++;
	}
	for(int k : v) bit.add(k,-1);
	vector<int>().swap(v);
	for(int k=l;k<=r;k++) in[k] = tmp[k];
}
int main()
{
	IOS;
	cin >> n;
	for(int i=0;i<n;i++) cin >> in[i].x >> in[i].y >> in[i].z,in[i].i = i;
	sort(in,in+n);
	bit.init(n);
	DC(0,n-1);
	for(int i=0;i<n;i++) cout << ans[i] << '\n';
   return 0;
}


