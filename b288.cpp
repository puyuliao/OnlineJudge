#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 1000000

struct point{
	double x,y;
	bool operator<(const point &b)const{
		return x < b.x || x == b.x && y < b.y;
	}
};

point in[1000];
point L[1000];
point U[1000];
point tu[2000];
int Lt;
int Ut;

double cross(point a,point b,point o){
	return (a.x-o.x)*(b.y-o.y) - (b.x-o.x)*(a.y-o.y);
}

double area(point p1,point p2,point p3){
	return abs(p1.x*p2.y - p2.x*p1.y + p2.x*p3.y - p3.x*p2.y + p3.x*p1.y - p3.y*p1.x)*0.5;
}

int build(int n){
	Lt = Ut = 0;
	sort(in,in+n);
	for(int i=0;i<n;i++){
		if(Lt >= 2 && cross(L[Lt-1],L[Lt-2],in[i]) <= 0) Lt--;
		if(Ut >= 2 && cross(U[Ut-1],U[Ut-2],in[i]) >= 0) Ut--;
		L[Lt++] = in[i];
		U[Ut++] = in[i];
	}
	
	int i=0;
	for(int j=0;j<Lt;j++) tu[i++] = L[j];
	for(int j=0;j<Ut;j++) tu[i++] = U[j]; 
	return i;
}

int main()
{
	IOS;
	int n,m;
	cin >> n;
	for(int i=0;i<n;i++) cin >> in[i].x >> in[i].y;
	m = build(n);
	double ans = 0;
	for(int i=0;i<m;i++){
		for(int j=i+1;j<m;j++){
			for(int k=j+1;k<m;k++){
				ans = max(ans,area(tu[i],tu[j],tu[k]));
			}
		}
	}
	cout << fixed << setprecision(6) << ans << '\n';
   return 0;
}


