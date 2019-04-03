#include<bits/stdc++.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
int N, a[30010], fa[30010];
int find(int x){
	return fa[x]==x?x:fa[x] = find(fa[x]);
}
bool unin(int x,int y){
	x = find(x); y = find(y);
	if(x == y) return false;
	fa[x] = y; return true; 
}
void Init() {
    unsigned int seed = time(0) / 60;
	srand(seed);
}
int main()
{
	IOS;
	Init();
	int N = 30000;
	cout << N << '\n';
	for(int i=0;i<N;i++) fa[i] = i;
	for(int i=0;i<N;i++){
		int r = rand() % (N-i); 
		a[find(i+r)] = i;
		unin(i+r,i);
	}
	for(int i=0;i<N;i++) cout << a[i] << ' ';
   return 0;
}
