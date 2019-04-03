#include<bits/stdc++.h>
#include<stdint.h>
using namespace std;
#define IOS {cin.tie(nullptr);ios_base::sync_with_stdio(false);}
#define N 1000000

bool input(complex<double> &c){
	string in;
	if(cin >> in){
		if(in.back() == 'i'){
			in.pop_back();
			if(in.empty() || in.back() == '-' || in.back() == '+') in.push_back('1'); 
		}
		for(int i = in.size() - 1; i>0; i--) if(in[i] == '+' || in[i] == '-'){
			in[i] = ',';
			break;
		}
		bool fin = true;
		for(int i=0;i<in.size();i++) if(in[i] == ',') fin = false;
		if(fin) in += ", 0";
		in = "(" + in + ")";
		//cout << in << '\n';
		stringstream ss(in);
		ss >> c;
		return true;
	}
	return false;
}

int main()
{
	IOS;
	complex<double> c;
	while(input(c)){
		cout << fixed << setprecision(3) << abs(c) << '\n';
	}

   return 0;
}


