#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define eps 1e-5 

struct point{
	double x,y;
	bool operator < (const point &b)const{
		return x > b.x || x == b.x && y > b.y;
	}
};
point in[4];

double cross(point a,point b,int x,int y){
	return (x - a.x)*(b.y - a.y) - (y - a.y)*(b.x - a.x);
}

bool chk(int x,int y){
	for(int i=0;i<3;i++){
		if(cross(in[i],in[i+1],x,y) < -eps) return false;
	}
	//cout << x << ' ' << y <<'\n';
	return true;
}

int cnt(){
	int ans = 0;
	for(int i=1;i<=99;i++)
		for(int j=1;j<=99;j++)
			if(chk(i,j)) ans++;
	return ans;
}

int main()
{
	IOS;
	while(cin >> in[0].x >> in[0].y){
		for(int i=1;i<3;i++) cin >> in[i].x >> in[i].y; 
		//sort(in,in+3);
		in[3].x = in[0].x; in[3].y = in[0].y ;
		double sum = 0;
		for(int i=0;i<3;i++) sum += abs(in[i].x) + abs(in[i].y);
		if(sum < eps) break;
		
		int ans = cnt();
		if(ans == 0) {
			reverse(in,in+4);
			ans = cnt();
		}
		
		cout << ans << '\n';
	}

   return 0;
}


