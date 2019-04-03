#include <bits/stdc++.h> 
using namespace std;
 
typedef unsigned short int UINT16;
class SimpleIdea {
public:
        UINT16 key;
        SimpleIdea(UINT16 k = 0):
               key(k) {}
        UINT16 encrypt(UINT16 m) {
               return (rotate_left(m, key&15) + key)^key;
        }
        UINT16 decrypt(UINT16 m) {
        		cout << (m^key)+(~key)+1 << '\n';
        		cout << 16 - (key&15) << '\n';
               return rotate_left((m^key)+(~key)+1, 16 - (key&15));
        }
private:
        UINT16 rotate_left(UINT16 x, UINT16 n) {
        return  (x << n) | (x >> (16-n));
        }
} test(10007);
int main() {
        for (int i = 434,j; i < 435; i++) {
        	j = test.encrypt(i);
               printf("%d %d %d\n", i,j,test.decrypt(j));
               assert(test.decrypt(j) == i);
        }
        return 0;
}
