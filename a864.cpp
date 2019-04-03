#include <bits/stdc++.h>
using namespace std;

int main()
{
	double mb,mv;
	char name[100];
	while(scanf("%s%lf%lf",name,&mb,&mv)==3){
		if(name == "END") break;
		printf("%s %.2lf ",name,mb -= mv);
		if(mb<-0.25) printf("O\n");
		else if(mb<0) printf("B\n");
		else if(mb<0.25) printf("A\n");
		else if(mb<0.5) printf("F\n");
		else if(mb<1) printf("G\n");
		else if(mb<1.5) printf("K\n");
		else printf("M\n");
	}

   return 0;
}


