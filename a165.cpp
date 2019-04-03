#include <bits/stdc++.h>
#include <stdint.h>
#define IOS {cin.tie(0); ios_base::sync_with_stdio(false);}
using namespace std;

bool test(int* n){
	int k = 0;
	for(int i=0,j=1;i<9;i++){
		k=k*10+n[i];
		if(k % j != 0) return false;
		j++;
	}
	return true;
}

int main()
{
	/*
	int in[9] = {1,2,3,4,5,6,7,8,9};
	do{
		if(test(in)){
			for(int i=0;i<9;i++) cout << in[i];
			cout << '\n';
		}
		
	}
	while(next_permutation(in,in+9));*/
	cout << 381654729;
   return 0;
}


