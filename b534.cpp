#include <bits/stdc++.h>
#include <stdint.h>
#define IOS {cin.tie(0); ios_base::sync_with_stdio(false);}
using namespace std;

bool isprime(int n){
	if(n<2) return false;
	for(int i=2;i*i<=n;i++) 
		if(n%i == 0) return false;
	return true;
}

int main()
{
	//IOS;
	int n,a,b,g;
	bool fir;
	cin >> n;
	while(n--){
		cin >> a >> b;
		g = __gcd(a,b);
		fir = true;
		for(int i=2,j=0;i*i<=a;i++,j=0){
			while(a%i == 0){
				a/=i;
				++j;
			}
			if(j == 0) continue;
			if(fir) {
				if(j == 1) cout << i;
				else cout << i << '^' << j;
				fir = false;
			}
			else {
				if(j == 1) cout << '*' << i;
				else cout << '*' <<i << '^' << j;
			}
		}
		if(n!=1){
			if(fir) cout << n;
			else cout << '*' << n;
		} 
		cout << " , " << g;
		if(isprime(g)) cout << " , Y\n";
		else cout <<  " , N\n";
	}

   return 0;
}


