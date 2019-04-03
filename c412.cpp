#include<stdio.h>
#define MOD 1000000007

int main()
{
	int n,a,b,ans,c = 0;
	a = b = ans = 0;
		while(1){
			c = getchar();
			if(c == 'Q') a=(a+1)%MOD, ans=(ans+b)%MOD;
			else if(c == 'A') b=(b+a)%MOD;
			else if(c == '\n') break;
		}
		printf("%d\n",ans);
	}
   return 0;
}


