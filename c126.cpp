#include<stdio.h>
#include<string.h>
char a[28],b[28];
int cnt;

void solve(int l,int r){
	cnt++;
	int i = strchr(b,a[cnt]) - b;
	if(l != i) solve(l,i-1);
	if(r != i) solve(i+1,r);
	printf("%c",b[i]);
}

int main()
{
	while(scanf("%s%s",a,b)==2){
		cnt = -1;
		solve(0,strlen(a) - 1);
		printf("\n");
	}
}
