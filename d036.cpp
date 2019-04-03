#include <stdio.h>

int main()
{
	int total = 0;
	bool fir=true;
	int n;
	if(scanf("%d",&n) == 1)
	{
		total+=n;
		fir=false;
		printf("%d",n);
	}
	
	while(scanf("%*[^0-9]%d", &n)==1)
	{	
		if(fir) 
		{
			total+=n;
			printf("%d",n);
		}
		total+=n;
		printf("+%d",n);
	}
	printf("=%d\n",total);
	return 0;
} 
 
