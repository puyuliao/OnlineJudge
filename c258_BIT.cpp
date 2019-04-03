#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 1600000

struct p{
	int rd, pos, sg;
	bool operator<(const p &b)const{
		return pos < b.pos || pos == b.pos && sg > b.sg || pos == b.pos && sg == b.sg && rd > b.rd;
	} 
}in[N];
vector<int> v;
int bt[N];

void add(int x,int c){
	for(int i=x;i<N;i+=i&-i) bt[i] += c;
}

int qur(int x){
	int r = 0;
	for(;x;x-=x&-x) r += bt[x];
	return r;
}

int main()
{
	IOS;
	int n=0,x,r;
	int64_t ans = 0;
	cin >> n;
	n<<=1;
	for(int i=0;i<n;i+=2){
		cin >> x >> r;
		in[i].sg = 1; in[i].pos = x-r;
		in[i^1].sg = -1; in[i^1].pos = x+r;
		v.push_back(x+r); v.push_back(x-r);
	}
	sort(v.begin(),v.end()); v.resize(unique(v.begin(),v.end()) - v.begin());
	for(int i=0;i<n;i++) {
		in[i].pos = (int)(lower_bound(v.begin(),v.end(),in[i].pos) - v.begin()) + 1;
		if(i&1) in[i].rd = in[i].pos - in[i^1].pos;
	}
	sort(in,in+n);
	int ed = 0;
	for(int i=0;i<n;i++){
		if(in[i].sg == 1){
			ans += ed; 
			add(in[i].pos,1);
		}
		else{
			ans += qur(in[i].pos-in[i].rd-1); 
			add(in[i].pos-in[i].rd,-1);
			ed++;
		}
	}
	cout << ans << '\n';
    return 0;
}


