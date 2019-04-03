#include <stdio.h>
#include <stdint.h>
int main()
{
	int64_t a,b;
	while(scanf("%I64d%I64d",&a,&b) == 2) 
		printf("%I64d\n",a+b);
	return 0;
}
