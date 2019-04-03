#include <stdio.h>

int main()
{
	int n,t,sum;
	scanf("%d",&n);
	sum=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&t);
		sum+=t*i;
	}
	printf("%d\n",sum);
   return 0;
}


