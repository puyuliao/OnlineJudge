#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 10001

struct event{
	int d,p;
	bool operator<(const event&b)const{
		return d > b.d || d == b.d && p > b.p;
	}
}in[N];


int main()
{
	IOS;
	int n,now,ans,t;
	while(cin >> n){
		ans = 0;
		for(int i=0;i<n;i++){
			cin >> in[i].d >> in[i].p;
		} 
		in[n++] = event{0,0};
		sort(in,in+n);
		now = in[0].d;
		priority_queue<int> pq;
		while(!pq.empty()) pq.pop();
		for(int i=0;i<n;i++){
			if(now < in[i].d){
				pq.push(in[i].p);
				continue;
			}
			for(int j=now;j>in[i].d && !pq.empty();j--){
				ans += pq.top(); pq.pop();
			}
			now = in[i].d - 1;
//			t = in[i].p;
//			if(pq.size() > now+1 && t < pq.top()){
//				t = pq.top(); pq.pop();
//			}
//			if(t != in[i].p) pq.push(in[i].p);
			if(in[i].p != 0){
				pq.push(in[i].p);
				ans += pq.top(); pq.pop();
			}
		}
		cout << ans << '\n';
	}
  return 0;
}
