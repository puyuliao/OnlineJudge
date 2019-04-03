#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}

set<int> s;
int suit[] = {0,  1,  2,  3,  4,  5,  6,  7,  8,  9,
 			 10, 12, 13, 15, 16, 18, 21, 22, 24, 25,
			 28, 30, 33, 37, 40, 42, 45, 48, 57, 58, 
			 60, 70, 72, 78, 85, 88, 93, 102, 105, 112, 
			 120, 130, 133, 165, 168, 177, 190, 210, 232, 240, 
			 253, 273, 280, 312, 330, 345, 357, 385, 408, 462,
			 520, 760, 840, 1320, 1365, 1848};

int main()
{
	IOS;
	
	for(int a=1;a<100;a++)
		for(int b = a+1;b<100;b++)
			for(int c = b+1;c<100;c++)
				s.insert(a*b + b*c + c*a);
	int cnt = 0;
	cout << "{";		
	for(int i=0;i<=1000000;i++){
		if(!s.count(i)){
			cout << i << ", ";
			if(++cnt == 66) break;
		}
	}
	cout << "\b\b}";
	int n;
	while(cin >> n){
		cout << suit[n] << '\n'; 
	}
   return 0;
}


