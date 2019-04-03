#include <stdio.h>
#include <stdint.h>

uint64_t gcd(uint64_t a,uint64_t b){
	if(b) while((a%=b) && (b%=a));
	return a+b;
}

int main()
{
	uint64_t a,b,t1,t2,t3,tmp;
	while(scanf("%llu%llu",&a,&b)==2) {
		if(a < b){tmp = a; a = b; b = tmp;}
		t1 = b*(2*a-b);
		t2 = b*b-1;
		t3 = 12;
		tmp = gcd(t1,t3);
		t1/=tmp; t3/=tmp;
		tmp = gcd(t2,t3);
		t2/=tmp;t3/=tmp;
		printf("%llu\n",t1*t2/t3);
	}
   return 0;
}


