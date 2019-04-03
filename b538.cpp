#include <bits/stdc++.h>
#include <stdint.h>
#define IOS {cin.tie(0); ios_base::sync_with_stdio(false);}
using namespace std;
#define MAXN 100

struct frac{
	int a, b; //a/b
	frac(int c,int d):a(c),b(d){
		if(d == 0) cout << "DIVBY0\n";
		if(c == 0) a=0,b=1;
		else {
			a = c/__gcd(c,d);
			b = a*d/c;
			if(b<0) a=-a,b=-b;
		}
	}
	frac():a(0),b(1){}
	frac operator-()const{
		return frac(-a,b);
	}
	frac operator~()const{
		if(a<0) return frac(-b,-a);
		else return frac(b,a);
	}
	frac operator+(const frac &f)const{
		return frac(a*f.b + f.a*b, b*f.b);
	}
	frac operator-(const frac &f)const{
		return frac(a*f.b - f.a*b, b*f.b);
	}
	frac operator*(const frac &f)const{
		return frac(a*f.a, b*f.b);
	}
	frac operator/(const frac &f)const{
		return frac(a*f.b, b*f.a);
	}
	frac operator+=(const frac &f) {
		return *this = frac(a*f.b + f.a*b, b*f.b);
	}
	frac operator-=(const frac &f) {
		return *this = frac(a*f.b - f.a*b, b*f.b);
	}
	frac operator*=(const frac &f) {
		return *this = frac(a*f.a, b*f.b);
	}
	frac operator/=(const frac &f) {
		return *this = frac(a*f.b, b*f.a);
	}
	bool operator <(const frac &f)const{
		return a*f.b < b*f.a;
	}
	bool operator <=(const frac &f)const{
		return a*f.b <= b*f.a;
	}
	bool operator ==(const frac &f)const{
		return a*f.b == b*f.a;
	}
	bool operator >(const frac &f)const{
		return a*f.b > b*f.a;
	}
	bool operator >=(const frac &f)const{
		return a*f.b >= b*f.a;
	}
	bool operator !=(const frac &f)const{
		return a*f.b != b*f.a;
	}
};

frac x,y;
char cmd;

int main()
{
	while(cin >> x.a >> x.b >> y.a >> y.b >> cmd){
		if(cmd == '+') x+=y;
		else if(cmd == '-') x-=y;
		else if(cmd == '*') x*=y;
		else x/=y;
		if(x.b == 1) cout << x.a << '\n';
		else cout << -x.a << '/' << -x.b << '\n';
	}	
}


