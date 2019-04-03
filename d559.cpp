#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}

bool isl(int year){
	if (year % 4 == 0)
		if (year % 100 == 0)
			if (year % 400 == 0) printf("a leap year\n"); return true;
			else printf("a normal year\n"); return false;
		else printf("a leap year\n");
	else printf("a normal year\n");
}

int main()
{
	IOS;
	int a;
	while(cin >> a)
	cout << "'C' can use printf(&quot;%d\",n); to show integer like " << a <<'\n'; 
   return 0;
}


