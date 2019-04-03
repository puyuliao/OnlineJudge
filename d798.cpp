// slow vision; need reference http://mypaper.pchome.com.tw/zerojudge/post/1323522964;
#include<memory.h>
#include<iostream>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}

struct node{
	int x1, x2, y1, y2, data;
};

node st[524288];
int in[500][500];

void build(int sx, int sy, int ex, int ey, int ind){
	if ((ex - sx) * (ey - sy) <= 1){
		if (sx != ex || sy != ey){
			st[ind].data = in[sx][sy];
			st[ind].x1 = sx; st[ind].x2 = ex;
			st[ind].y1 = sy; st[ind].y2 = ey;
		}
		return;
	}

	int mx = sx + ex >> 1, my = sy + ey >> 1, ti = ind << 2;
	build(sx, sy, mx, my, ti + 1);
	build(sx, my, mx, ey, ti + 2);
	build(mx, sy, ex, my, ti + 3);
	build(mx, my, ex, ey, ti + 4);
	st[ind].data = max({ st[ti + 1].data, st[ti + 2].data, st[ti + 3].data, st[ti + 4].data });
	st[ind].x1 = sx; st[ind].x2 = ex;
	st[ind].y1 = sy; st[ind].y2 = ey;

}

int query(int sx, int sy, int ex, int ey, int ind = 0){
	if (st[ind].x2 == st[ind].x1 && st[ind].y1 == st[ind].y2) return 0;
	if (st[ind].x2 <= sx || st[ind].x1 >= ex || st[ind].y1 >= ey || st[ind].y2 <= sy) return -INF;
	if (st[ind].x1 >= sx && st[ind].y1 >= sy && st[ind].x2 <= ex && st[ind].y2 <= ey && st[ind].x1 < ex && st[ind].y1 < ey){
		return st[ind].data;
	}

	ind <<= 2;
	return max({
		query(sx, sy, ex, ey, ind + 1),
		query(sx, sy, ex, ey, ind + 2),
		query(sx, sy, ex, ey, ind + 3),
		query(sx, sy, ex, ey, ind + 4)
	});

}

int main()
{
	IOS;
	int n, m, q, x1, x2, y1, y2;
	cin >> n >> m;
	for (int i = 0; i<n; i++){
		for (int j = 0; j<m; j++){
			cin >> in[i][j];
		}
	}

	build(0, 0, n, m, 0);
	cin >> q;
	while (q--){
		cin >> x1 >> y1 >> x2 >> y2;
		cout << query(x1 - 1, y1 - 1, x2, y2) << '\n';
	}
	return 0;
}
