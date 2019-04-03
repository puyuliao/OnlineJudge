#include <stdio.h>

int main()
{
	int t,sum;
	char in[9008];
	scanf("%d",&t);
	while(t--){
		scanf("%s",in);
		sum = 0;
		for(int i=0,j=1; in[i] != '\0';i+=2,j+=2){
			if(in[j] == '\0'){
				sum += in[i]-'0';
				break;
			}
			sum += in[i] - in[j];
		}
		if(sum == 0) printf("Yes\n");
		else printf("No\n");
	}
   return 0;
}


