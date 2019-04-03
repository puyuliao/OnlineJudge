#include <stdio.h>
#define Mod 10000019

int A[1000000];
int T[1000000];
int ans;

void merge_sort(int s,int e){
	if(e>s+1){
		int m = s + (e-s)/2;
		int p = s,q = m,i = s;
		merge_sort(s,m);
		merge_sort(m,e);
		while(p < m || q < e){
			if(q >= e || (p < m && A[p] <= A[q])) {
				T[i++] = A[p++];
			}
			else{
				T[i] = A[q++];
			 	for(int j=p;j<m;j++)
			 		if((ans+=T[i] + A[j]) > Mod) ans%=Mod;
			  	i++;
			} 
		} 
		for(i=s;i<e;i++) {
			//ans+=(T[i]==0)?A[i]:T[i];
			A[i] = T[i];	
		}
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	merge_sort(0,n);
	//for(int i=0;i<n;i++) printf("%d ",A[i]);
	printf("%d\n",ans);
   return 0;
}


