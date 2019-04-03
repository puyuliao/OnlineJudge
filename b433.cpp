#include <bits/stdc++.h>
#include <stdint.h>
#define IOS {cin.tie(0); ios_base::sync_with_stdio(false);}
using namespace std;
#define MX 65536

int cnt[MX];

inline uint16_t rl(uint16_t a,uint16_t n){
	return  (a << n) | (a >> (16-n));
}

uint16_t E(uint16_t m,uint16_t key){ //¥[±K; 
	return (rl(m,key&15) + key)^key;
}

uint16_t D(uint16_t c,uint16_t key){ //¸Ñ±K; 
	return rl((c^key)+(~key)+1, 16 - (key&15));
}


int main()
{	
	IOS;
	int c,m,dc,ans; //±K¡A©ú; 
	while(cin >> c >> m){
		ans = 0; memset(cnt,0,sizeof(cnt));
		for(int i=0;i < MX;i++) cnt[E(m,i)]++;
		for(int i=0;i < MX;i++) ans += cnt[D(c,i)];
		cout << ans << '\n';
	} 
   return 0;
}


