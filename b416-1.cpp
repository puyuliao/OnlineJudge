#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 100002
#define M 1000002
#define SZ 400

int in[N];
int block[N/SZ+2];
int cnt[N],ans[M];
int sg;

struct query{
	int l,r,a,b,ind;
	inline bool operator<(const query &b)const{
		return l/sg < b.l/sg || l/sg == b.l/sg && r < b.r;
	}
}q[M];

inline void add(int x){
	if(cnt[x]++ == 0) block[x/SZ] ++;
}

inline void sub(int x){
	if(--cnt[x] == 0) block[x/SZ] --;
}

int qur(int x){
	int ba = (q[x].a+SZ-1)/SZ,bb = (q[x].b-1)/SZ;
	int sum = 0,e = ba*SZ;
	if(ba >= bb){
		for(int i=q[x].a;i<=q[x].b;i++) if(cnt[i]) sum++;
		return sum;
	}
	for(int i=q[x].a;i<e;i++) if(cnt[i]) sum++;
	for(int i=bb*SZ;i<=q[x].b;i++) if(cnt[i]) sum++;
	for(int i=ba;i<bb;i++) sum += block[i];
	return sum;
}

int main()
{
	IOS;
	int n,m;
	cin >> n >> m;
	sg = sqrt(n)+1;
	for(int i=1;i<=n;i++) cin >> in[i];
	for(int i=0;i<m;i++) cin >> q[i].l >> q[i].r >> q[i].a >> q[i].b,q[i].ind = i;
	sort(q,q+m); 
	int nl,nr; nl = nr = 1; add(in[1]);
	for(int i=0;i<m;i++){
		while(nr < q[i].r) add(in[++nr]);
		while(nl < q[i].l) sub(in[nl++]);
		while(nr > q[i].r) sub(in[nr--]);
		while(nl > q[i].l) add(in[--nl]);
		ans[q[i].ind] = qur(i);
	}
	for(int i=0;i<m;i++) cout << ans[i] << '\n';
   return 0;
}

