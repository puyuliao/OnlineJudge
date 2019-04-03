#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 1000

struct num{
	int a,b;
	bool operator < (const num& n)const{
		if(a+b != n.a+n.b) return a+b>n.a+n.b;
		if(a>b && n.a <= n.b) return true;
		if(a==b && n.a < n.b) return true;
		return false;
	}
}in[N];

int main()
{
	IOS;
	int n;
	while(cin >> n){
		for(int i=0;i<n;i++) cin >> in[i].a >> in[i].b;
		sort(in,in+n);
		for(int i=0;i<n;i++){
			if(in[i].a > in[i].b) cout << '>' << in[i].a + in[i].b;
			else if(in[i].a == in[i].b) cout << '=' << in[i].a + in[i].b;
			else cout << '<' << in[i].a + in[i].b;
			cout << ' ';
		}
		cout << '\n';
	}
	
   return 0;
}


