#include <stdio.h>

int main()
{
	int a;int b;
	while(scanf("%d%d",&a,&b)==2)
	{
		if(a==0&&b==0) return 0;
		int ans[1000];
		for(int i=0;i<1000;i++) ans[i]=0;
		a%=b;
		if(a==0)
		{
			printf("not repeater\n");
			continue;
		} 	
		while(a<b) a*=10;
		int temp = a;
		for(int i = 0;;i++)
		{
			ans[i] = a/b;
			a%=b;
			if(a==0)
			{
				printf("not repeater\n");
				break;
			} 
			a*=10;
			if(a == temp)
			{
				for(int j = 0;j <= i;j++) printf("%d",ans[j]);
				printf("\n");
				break;
			}		
		}
	}
}

