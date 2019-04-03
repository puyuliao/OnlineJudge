#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 250
#define lowbit(x) (x&-x)

int n;
int in[N+1][N+1];
int sum[N+1][N+1];

void add(int x,int y,int k){
	for(int i=x;i<=n;i+=lowbit(i))
		for(int j=y;j<=n;j+=lowbit(j))
			sum[i][j] += k;
}

int query(int x,int y){
	int ans = 0;
	for(int i=x;i>0;i-=lowbit(i))
		for(int j=y;j>0;j-=lowbit(j))
			ans += sum[i][j];
	return ans;
}

int main()
{
	IOS;
	int q,t,x1,y1,x2,y2,cmd;
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin >> in[i][j];
			add(i,j,in[i][j]);
			//sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + in[i][j];

		}
	}
	//for(int i=n;i;i--)
		//for(int j=n;j;j--)
			//sum[i][j] -= sum[i - lowbit(i)][j] + sum[i][j - lowbit(j)] - sum[i-lowbit(i)][j-lowbit(j)];
	while(q--){
		cin >> cmd;
		if(cmd == 1) {
			cin >> x1 >> y1 >> x2 >> y2;
			if(x2 < x1 || x2 == x1 && y2 < y1){
				swap(x1,x2); swap(y1,y2);
			}
			if(y1>y2) {
				swap(y1,y2); 
			}
			cout << query(x2,y2) - query(x2,y1-1) - query(x1-1,y2) + query(x1-1,y1-1) << '\n'; 
		}
		else{
			cin >> x1 >> y1 >> t;
			add(x1,y1,t - in[x1][y1]);
			in[x1][y1] = t;
		}
	}


   return 0;
}


