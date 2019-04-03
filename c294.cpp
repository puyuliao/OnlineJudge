#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 1000000

int main()
{
	IOS;
	int a[3];
	cin >> a[0] >> a[1] >> a[2];
	sort(a,a+3);
	for(int i=0;i<3;i++) cout << a[i] << ' ';
	cout << '\n';
	if(!(a[0]&&a[1]&&a[2]) || a[0] + a[1] < a[2]) cout << "No\n"; 
	else if(a[0]*a[0] < a[2]*a[2] - a[1]*a[1]) cout << "Obtuse\n";
	else if(a[0]*a[0] == a[2]*a[2] - a[1]*a[1]) cout << "Right\n";
	else cout << "Acute\n";
   return 0;
}


