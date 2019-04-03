#include <bits/stdc++.h>
#include <stdint.h>
#define IOS {cin.tie(0); ios_base::sync_with_stdio(false);}
using namespace std;

int in[100001];
int tmp[100001];

bool cmp(int a,int b){
	return a>b;
}

int main()
{
	IOS;
	int n,k;
	cin >> n >> k;
	for(int i=0;i<n;i++) cin >> in[i];
	sort(in,in+n);
	int lev = (int)ceil((-1.0+sqrt((double)k*8-1))/2);
	//for(;lev*(lev+1)<2*k;lev++);
	for(int i=n-lev,j=0;i<n;i++,j++){
		tmp[j] = in[i] - in[j];
	}
	int pos = k-1-(lev)*(lev-1)/2;
	nth_element(tmp,tmp+pos,tmp+lev,cmp);
	cout << tmp[pos] << '\n';
   return 0;
}


