#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 1000000


void fctrl(int arr[],int m,int f_num){ 
	int x,temp=0,i=0;
	for(int j=100;j>=1;j--) {
		f_num=j;
		while(f_num>1){
			i=0;
			do{ 
				x=arr[i]*f_num+temp;
				arr[i]=x%10;
				temp=x/10;
				i++;
			}while(temp!=0||i<=m);
			m=--i;
			--f_num;
		}
	} 
	while(m>=2)
	{printf("%d",arr[m]);
	--m;
	}
}
int main(){
int num=100,f_num=99,arr[6943]={0};
int i;
for( i=0;num!=0;i++,num/=10)
arr[i]=num%10;
fctrl(arr,i,f_num);
return 0;
}



