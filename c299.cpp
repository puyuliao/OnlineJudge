#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 100

int in[N];

int main()
{
	IOS;
	int n;
	cin >> n;
	for(int i=0;i<n;i++) cin >> in[i];
	sort(in,in+n);
	bool hv = true;
	for(int i=1;i<n;i++) if(in[i] != in[i-1] + 1) hv = false;
	cout << *min_element(in,in+n) << ' ' << *max_element(in,in+n) << ' '; 
	if(hv) cout << "yes\n";
	else cout << "no\n";

   return 0;
}


