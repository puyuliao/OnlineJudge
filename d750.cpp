#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 10000

int in[N];
int n,m;

bool cmp(int a,int b){
	if(a%m != b%m) return a%m<b%m;
	
	if((a&1) == (b&1) && (a&1) == 1) return a>b;
	if((a&1) == (b&1)) return a<b;
	return (a&1)>(b&1);
}

int main()
{
	IOS;

	while(cin >> n >> m && (n||m)){
		cout << n << ' ' << m << '\n';
		for(int i=0;i<n;i++) cin >> in[i];
		sort(in,in+n,cmp);
		for(int i=0;i<n;i++) cout << in[i] << '\n';
	}
	
   return 0;
}


