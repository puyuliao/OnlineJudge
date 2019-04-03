#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 25

struct point{
	int x,y;
}in[N];

int n;
int ans[N];
double dis[N][N];
double dp[20][1<<20];

inline double chk(int l,int r,double now){
	if(l != 0) now += dis[ans[r]][ans[l-1]] - dis[ans[l]][ans[l-1]];
	if(r != n-1) now += dis[ans[l]][ans[r+1]] - dis[ans[r]][ans[r+1]]; 
	return now;
}

int main()
{
	mt19937 rd(time(NULL));
	srand(time(NULL));
	IOS;
	int T,t;
	double mn,z;
	cin >> T;
	while(T--){
		cin >> n; 
		for(int i=0;i<n;i++) cin >> in[i].x >> in[i].y,ans[i] = i;
		for(int i=0;i<n;i++) 
			for(int j=0;j<n;j++) 
				dis[i][j] = hypot(in[i].x-in[j].x,in[i].y-in[j].y);
		if(n <= 20){
			for(int i=0;i<n;i++){
				fill(dp[i],dp[i]+(1<<n),1e20);
				dp[i][1<<i] = 0;
			}
			for(int s=1;s<1<<n;s++) if(s != __lg(s))
				for(int i=0;i<n;i++) if(s&(1<<i)) {
					for(int j=0;j<n;j++) if(s&(1<<j) && j != i){
						dp[i][s] = min(dp[i][s],dp[j][s^(1<<i)] + dis[i][j]);
					}
				}
			double d = 1e20;
			for(int i=0;i<n;i++){
				d = min(d,dp[i][(1<<n)-1]);
			}
			cout << fixed << setprecision(2) << d << '\n';
			continue;
		}
		random_shuffle(ans,ans+n);
		mn = 0;
		for(int i=1;i<n;i++) mn += dis[ans[i]][ans[i-1]];
		t = 2e7;
		for(int i=0;i<t;i++){
			int l = rd()%n, r = rd()%n;
			if(l == r) r = (r+1)%n;
 			if(l > r) swap(l,r);
			z = chk(l,r,mn);
			if(mn > z) mn = z,reverse(ans+l,ans+r+1);
		}
		cout << fixed << setprecision(2) << mn << '\n';
	}

   return 0;
}


