#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 1000000
#pragma GCC target("avx")
#define ttry 200

int seed;
struct point{
	int x,y;
	double mx,my;
	point(int _x,int _y):x(_x),y(_y),mx(_x * cos(seed) - _y * sin(seed)),my(-_x * sin(seed) + _y * cos(seed)){}
	bool operator <(const point &b)const{
		return mx < b.mx || mx == b.mx && my < b.my;
	}
};

set<point> s;

int main()
{
	IOS;
	srand(time(NULL));
	seed = rand();
	int n,last_ans = 0,c,x,y;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> c >> x >> y;
		x = (last_ans + x) % 100000000 + 1;
		y = (last_ans + y) % 100000000 + 1;
		if(c == 1) s.insert(point(x,y));
		else{
			int ans = 2147483647;
			point p = point(x,y);
			auto it = s.lower_bound(p);
			int cnt = 0;
			for(auto i = it; i != s.end() && cnt < ttry; i++,cnt++) ans = min(ans,abs(i->x-p.x) + abs(i->y-p.y));
			cnt = 0;
			if(it != s.begin()) for(auto i = --it; cnt < ttry; i--,cnt++) {
				ans = min(ans,abs(i->x-p.x) + abs(i->y-p.y));
				if(i == s.begin()) break;
			}
			if(ans == 2147483647) ans = 0;
			last_ans = ans;
			cout << ans << '\n';
		}
		//for(auto i : s) cout << '(' << i.mx << ',' << i.my << ')' << ' '; cout << '\n';
	}
   return 0;
}
