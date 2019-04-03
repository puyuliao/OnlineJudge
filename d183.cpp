#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 1000000

bool chk(int a,int b){
	bool num[10];
	memset(num,false,sizeof(num));
	if(a < 10000) num[0] = true;
	while(a > 0){
		num[a%10] = true;
		a/=10;
	}
	if(b < 10000) num[0] = true;
	while(b > 0){
		num[b%10] = true;
		b/=10;
	}
	return *min_element(num,num+10) == true;
}

int main()
{
	int n;
	while(scanf("%d",&n)==1 && n){
		bool nf = true;
		for(int i=1;i * n < 100000;i++){
			if(chk(i,i*n)){
				printf("%05d / %05d = %d\n",i*n,i,n);
				nf = false;
			}
		}
		if(nf) printf("There are no solutions for %d.\n",n);
		printf("\n");
	}

   return 0;
}


