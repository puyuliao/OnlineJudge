#include <bits/stdc++.h>
#include <stdint.h>
#define IOS {cin.tie(0); ios_base::sync_with_stdio(false);}
using namespace std;

pair<int,int> pa[4388608],pb[4388608];

int main()
{
	IOS;
	int a,b;
	char tmp;
	int an = 0,bn = 0;
	int64_t ans = 0;
	while(cin >> a >> tmp >> b && (a||b)){
		pa[an].first = a;
		pa[an].second = b;
		an++;
	}
	while(cin >> a >> tmp >> b && (a||b)){
		pb[bn].first = a;
		pb[bn].second = b;
		bn++;
	}
	sort(pa,pa+an);
	sort(pb,pb+bn);
	for(int i=0,j=0;i<an && j<bn;){
		if(pa[i].first == pb[j].first) ans += (int64_t)pa[i++].second*pb[j++].second;
		else if(pa[i].first < pb[j].first) i++;
		else j++;
	}
	cout << ans << '\n';
   return 0;
}


