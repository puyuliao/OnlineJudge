#include <stdio.h>
#include <math.h>
#include <stdint.h>

uint64_t s[200];
int top;

int main()
{
	uint64_t n,t,d;
	while(scanf("%llu",&n)==1){
		d = n; top = 0;		
		if(d%2 == 0) {s[top++] = 2;	while(d%2==0)d/=2;}
		if(d%3 == 0) {s[top++] = 3;	while(d%3==0)d/=3;}
		t = sqrt(d)+1;
		for(uint64_t i=5,j=2;i<=t && d!=1;i+=j,j=6-j)
			if(d%i==0) {
				s[top++] = i;
				while(d%i==0) d/=i;
				t = sqrt(d)+1;
			}
		if(d!=1) s[top++] = d;
		for(int k=0;k<top;k++){
			n = n/s[k]*(s[k]-1);
		}
		printf("%llu\n",n);
	}
   return 0;
}


