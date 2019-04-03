#include <bits/stdc++.h>
#include <stdint.h>
#define IOS {cin.tie(0); ios_base::sync_with_stdio(false);}
using namespace std;
#define MAXN 1000001

unsigned int bs[MAXN>>5]={0xc0000000};
vector<int> prime;

inline bool test(int n){
	int p = n&31;
	p = 1 << (31-p);
	return (bs[n>>5]&p)!=0;
}

inline void settrue(int n){
	unsigned int p = n&31;
	p = 1 << (31-p);
	bs[n>>5] |= p;
}

void build(){
	for(int i=2;i<MAXN;i++){
		if(!test(i)) prime.push_back(i);
		for(int j=0;i*prime[j]<MAXN;j++){
			settrue(i*prime[j]);
			if(i%prime[j] == 0) break;
		}
	}
}


int main()
{
	IOS;
	int n;
	build();
	while(cin >> n && n){
		cout << n <<" = ";
		for(int i = 0;;i++){
			if(!test(n-prime[i])) {
				cout << prime[i] << " + " << n-prime[i] << '\n';
				break;
			}
		}
	}

   return 0;
}


