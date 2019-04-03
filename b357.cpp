#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 65537
#define M N
#define Q N

int ac[N];
int sz[N];
vector<int> ans;
bool destry[M];

int dsfind(int a){
	if(ac[a] == a) return a;
	return ac[a] = dsfind(ac[a]);
}

void dsunion(int a,int b){
	a = dsfind(a); b = dsfind(b);
	if(a == b) return;
	if(sz[a] < sz[b]) swap(a,b);
	sz[a] += sz[b];
	ac[b] = a;
}

struct edg{
	int s,t;
}in[M];

struct query{
	char cmd;
	int k;
}qr[Q];

int main()
{
	IOS;
	int n,m,d,q;
	char cmd;
	while(cin >> n >> m){
		ans.clear();
		for(int i=1;i<=n;i++) ac[i] = i,sz[i] = 1;
		for(int i=1;i<=m;i++) cin >> in[i].s >> in[i].t,destry[i] = false;
		cin >> q;
		for(int i=0;i<q;i++) {
			cin >> qr[i].cmd >> qr[i].k;
			if(qr[i].cmd == 'D') destry[qr[i].k] = true; 
		}
		for(int i=1;i<=m;i++) if(!destry[i]) dsunion(in[i].s,in[i].t);
		for(int i = q-1;i>=0;i--){
			if(qr[i].cmd == 'D'){
				dsunion(in[qr[i].k].s,in[qr[i].k].t);
			}
			else{
				ans.push_back(sz[dsfind(qr[i].k)]);
			}
		}
		
		for(int i=ans.size()-1;i>=0;i--)
			cout << ans[i] << '\n';
	}

   return 0;
}


