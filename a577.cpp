#include<bits/stdc++.h>
#include<stdint.h>
#pragma GCC target("avx")
using namespace std;
#define IOS {cin.tie(0);ios_base::sync_with_stdio(false);}
#define N 1000000
#define push_back emplace_back
#define ff first
#define ss second
typedef complex<double> cp;
valarray<cp> va,vb;
const double PI = acos(-1);
int ans[N];

void rader(valarray<cp> &a,int n){
	int j = n>>1;
	for(int i=1;i<n-1;i++){
		if(i < j) swap(a[i],a[j]);
		int k = n >> 1;
		while(j >= k) j-=k,k>>=1;
		if(j<k) j+=k;
	}
}

void fft(valarray<cp> &a,int n,bool idft = false){
	rader(a,n);
	double pi = idft?PI:-PI;
	for(int h=2;h<=n;h<<=1){
		cp omg = cp(cos(2*pi/h),sin(2*pi/h));
		for(int j=0;j<n;j+=h){
			cp w = cp(1,0);
			for(int k=j;k<j+h/2;k++){
				cp u = a[k], v = w*a[k+h/2];
				a[k] = u+v; a[k+h/2] = u-v;
				w *= omg;
			}
		}
	}
	if(idft) a/=n;
}

int main()
{
	//IOS;
	string a,b;
	while(cin >> a >> b){
		if(a == "0" || b == "0"){
			cout << "0\n";
			continue;
		}
		memset(ans,0,sizeof(ans));
		int n=1;
		while(n < a.size() << 1) n <<= 1;
		while(n < b.size() << 1) n <<= 1;
		va.resize(n); vb.resize(n);
		for(int i=0,j=a.size()-1;j>=0;j--,i++) va[i] = a[j]-'0';
		for(int i=0,j=b.size()-1;j>=0;j--,i++) vb[i] = b[j]-'0';
		fft(va,n); fft(vb,n);
		va *= vb;
		fft(va,n,true);
		int len = a.size() + b.size() - 1;
		for(int i=0;i<len;i++){
			ans[i] += va[i].real() + .5;
			if(ans[i] >= 10){
				ans[i+1] += ans[i]/10;
				ans[i] %= 10;
			} 
		}
		while(ans[len]) len++;
		while(!ans[len-1]) len--;
		for(int i=len-1;i>=0;i--) cout << ans[i]; cout << '\n';
	}

   return 0;
}


