#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 1000000

int main()
{
	IOS;
	int n;
	char c;
	double t;
	while(cin >> n){
		priority_queue<double,vector<double>,greater<double> > pq;
		double ans = 0;
		for(int i=0;i<n;i++) {
			cin >> c >> t;
			pq.push(t);
		}
		while(pq.size() >= 2){
			double a = pq.top(); pq.pop();
			double b = pq.top(); pq.pop();
			ans += a+b;
			pq.push(a+b);
		}
		cout << fixed << setprecision(2) << ans << '\n';
	}

   return 0;
}


