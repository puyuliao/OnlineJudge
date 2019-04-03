#include <stdio.h>
#include <stdint.h>
#define MAXN 10000001

char in[100000];
int a[10001];
int atop = 0;
int prime[2000000];
int ptop;
unsigned int bs[MAXN>>5]={0xc0000000};
int cnt;

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
		if(!test(i)) prime[ptop++] = i;
		for(int j=0;i*prime[j]<MAXN;j++){
			settrue(i*prime[j]);
			if(i%prime[j] == 0) break;
		}
	}
}

int main()
{
	build();
	int64_t last,ans,nt;
	int x;
	while(fgets(in,100000,stdin)!=NULL){
		nt = last = ans = 0; atop = x = 0;
		for(int i=0;in[i];i++){
			if('0' <= in[i] && in[i] <= '9') x = x*10+in[i]-48;
			else a[atop++] = x,x = 0;
		}
		if(x) a[atop++] = x,x = 0;
		for(int i=0;i<atop;i++){
			if(!test(a[i])){
				if(a[i] <= last){
					last = nt = a[i];
					continue;
				}
				last = a[i];
				nt += a[i];
				if(ans < nt) ans = nt;
			}
			else last = nt = 0;
		}
		printf("%lld\n",ans);
	}
   return 0;
}


