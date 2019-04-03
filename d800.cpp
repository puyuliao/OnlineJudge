#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 1024
#define INF 0x3f3f3f3f

int in[N>>1][N>>1];
int n,m,sx,sy,ex,ey;

struct subtree{
	int yl,yr,mx;
};

struct maintree{
	subtree sb[N];
	int xl,xr;
}st[N];

void buildsb(int l,int r,int d,int k){
	if(l == r-1){
		st[k].sb[d].yl = l; st[k].sb[d].yr = r;
		st[k].sb[d].mx = in[st[k].xl][l];
		return;
	}
	
	int mid = l+r>>1;
	buildsb(l,mid,d+d+1,k);
	buildsb(mid,r,d+d+2,k);
	
	st[k].sb[d].yl = l; st[k].sb[d].yr = r;
	st[k].sb[d].mx = max(st[k].sb[d+d+1].mx,st[k].sb[d+d+2].mx);
}

void buildmt(int l,int r,int d){
	if(l == r-1){
		st[d].xl = l; st[d].xr = r;
		buildsb(0,m,0,d);
		return;
	}
	
	int mid = l+r>>1;
	buildmt(l,mid,d+d+1);
	buildmt(mid,r,d+d+2);
	
	st[d].xl = l; st[d].xr = r;
	for(int i=0;i<1024;i++){
		if(st[d+d+1].sb[i].yr){
			st[d].sb[i].yl = st[d+d+1].sb[i].yl; st[d].sb[i].yr = st[d+d+1].sb[i].yr;
			st[d].sb[i].mx = max(st[d+d+1].sb[i].mx, st[d+d+2].sb[i].mx);
		}
	}
}

int querysb(int d,int k){
	if(st[k].sb[d].yr <= sy || st[k].sb[d].yl >= ey) return -INF;
	if(st[k].sb[d].yl >= sy && st[k].sb[d].yr <= ey){
		return st[k].sb[d].mx;
	}
	
	return max(querysb(d+d+1,k),querysb(d+d+2,k));
}

int querymt(int d){
	if(st[d].xr <= sx || st[d].xl >= ex) return -INF;
	if(st[d].xl >= sx && st[d].xr <= ex){
		return querysb(0,d);
	}
	
	return max(querymt(d+d+1),querymt(d+d+2));
}

int main()
{
	IOS;
	int q;
	while(cin >> n >> m){
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin >> in[i][j];
		memset(st,0,sizeof(st));
		buildmt(0,n,0);
		cin >> q;
		while(q--){
			cin >> sx >> sy >> ex >> ey;
			if(sx > ex || sx == ex && sy > ey){
				swap(sx,ex); swap(sy,ey);
			}
			if(sy > ey){
				swap(sy,ey);
			}
			sx--,sy--;
			cout << querymt(0) << "\n";
		}
	}	
	
  return 0;
}
