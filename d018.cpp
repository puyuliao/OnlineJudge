#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 1000000

int main()
{
	IOS;
	string in;
	int oe;
	char c;
	double t,osum,esum;
	while(getline(cin,in)){
		stringstream ss(in);
		osum = esum = 0;
		while(ss >> oe >> c >> t){
			if(oe&1) osum += t;
			else esum += t;
		}
		cout << osum - esum << '\n';
	}

   return 0;
}


