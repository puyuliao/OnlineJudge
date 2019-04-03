#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 1000
#define C 500000
#define INF 0x3f3f3f3f

int n,m,A,B,X,Y;
int from[N][N];
int g[N][N];
int h[N][N];
bool visit[N][N];
bool inpq[N][N];
char in[N][N];
const int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}}; //up,down,left,right

struct point{
	int x,y,f;
};
vector<point> v[C];
int mn = INF;
int mx = 0;
int sz = 0;

inline void insert(point p){
	for(;mx<p.f;) v[++mx].resize(0); 
	v[p.f].push_back(p);
	mn = min(mn,p.f);
	sz++;
}

inline point extract(){
	point p = v[mn].back();
	v[mn].pop_back();
	if(--sz == 0) mn = C;
	else for(;!v[mn].size();mn++); 
	return p;
}

int Astar(){
	if(in[A][B] == 'X' || in[X][Y] == 'X') return INF;
	for(int i=0;i<n;i++){
		memset(visit[i],false,n); // close list
		memset(inpq[i],false,n); // open list
		memset(g[i],0,n<<2);
	}
	mx = sz = 0; mn = C;
	g[A][B] = 0; h[A][B] = abs(X-A) + abs(Y-B); point p{A,B,h[A][B]},np;
	insert(p);
	while(sz){
		p = extract();
		//cout << p.x << ' ' << p.y << ' ' << p.f << '\n';
		if(p.x == X && p.y == Y) return g[p.x][p.y];
		inpq[p.x][p.y] = false;
		visit[p.x][p.y] = true;
		for(int i=0;i<4;i++){
			int nx = p.x + dir[i][0], ny = p.y + dir[i][1];
			if(visit[nx][ny] || in[nx][ny] == 'X') continue;
			if(!inpq[nx][ny]) {
			 	inpq[nx][ny] = true;
				g[nx][ny] = g[p.x][p.y]+1; 
				h[nx][ny] = abs(X-nx) + abs(Y-ny);
				insert(point{nx,ny,g[nx][ny] + h[nx][ny]});
			}
			else {
				if(g[nx][ny] > g[p.x][p.y] + 1) {
					g[nx][ny] = g[p.x][p.y] + 1;
					insert(point{nx,ny,g[nx][ny] + h[nx][ny]});
				}
				else if(g[nx][ny] + 1 < g[p.x][p.y]){
					g[p.x][p.y] = g[nx][ny] + 1;
					p.f = g[p.x][p.y] + h[p.x][p.y];
					i = 0;
				}
			}
		}
	}
	return -1;
}

int main()
{
	IOS;
	cin >> n >> m;
	for(int i=0;i<n;i++) cin >> in[i];
	while(m--){
		cin >> A >> B >> X >> Y;
		int ans = Astar();
		if(ans == INF) cout << "ERROR\n";
		else cout << ans << "\n";
	}
   return 0;
}


