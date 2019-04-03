#include <bits/stdc++.h>
using namespace std;

bool ishp(int a){
	set<int> ps;
	int t;
	ps.insert(a);
	while(a != 1){
		t = 0;
		while(a>0){
			t += (a%10)*(a%10);
			a /= 10;
		}
		if(ps.count(t)!=0) return false;
		ps.insert(t);
		a = t;
		
	}
	return true;
}

int main()
{
	int n;
	while(scanf("%d",&n)==1){
		if(ishp(n)) printf("%d is a happy number\n",n);
		else printf("%d is an unhappy number\n",n);
	}
   return 0;
}


