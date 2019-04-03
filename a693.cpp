#include <stdio.h>
int in[100001];

int main()
{
	int n,m,l,r;
	while(scanf("%d%d",&n,&m)==2){
		for(int i=1;i<=n;i++) scanf("%d",&in[i]);
		for(int i=2;i<=n;i++) in[i]+=in[i-1];
		
		for(int i=0;i<m;i++){
			scanf("%d%d",&l,&r);
			printf("%d\n",in[r]-in[l-1]);
		}
	}
   return 0;
}


