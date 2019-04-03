#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define PB push_back
#define ll long long
using namespace std;
typedef pair<int, int> PI;
const int INF = 0xFFFFFFF;
const int MOD = 1e9+7;
const int MAXN = 500005;
 
int n, q, num;
char ch[5];
 
struct Treap {
    static Treap mem[MAXN], *pmem;
    Treap *l, *r;
    int size, pri, key;
    ll val, sum, add;
    Treap() {}
    Treap(int _key, int _val) :
        l(NULL), r(NULL), pri(rand()), size(1), key(_key), val(_val), sum(_val), add(0) {}
} Treap::mem[MAXN], *Treap::pmem = Treap::mem;
 
ll size(Treap *t) {
    return t ? t->size : 0;
}
 
ll sum(Treap *t) {
    return t ? t->sum : 0;
}
 
void pull(Treap *t) {
    t->size = size(t->l) + size(t->r) + 1;
    t->sum = sum(t->l) + sum(t->r) + t->val + t->add;
}
 
void push(Treap *t) {
    if ( t->l ) t->l->add += t->add, t->l->sum += size(t->l) * t->add, t->l->val += t->add;
    if ( t->r ) t->r->add += t->add, t->r->sum += size(t->r) * t->add, t->r->val += t->add;
    t->add = 0;
}
 
bool choice(int x, int y) {
    return (rand() / RAND_MAX) <= ((double) x / (x + y) );
}
 
Treap* merge(Treap *a, Treap *b) {
    if ( !a || !b ) return a ? a : b;
    if ( a->pri > b->pri ) {
        push(a);
        a->r = merge(a->r, b);
        pull(a);
        return a;
    } else {
        push(b);
        b->l = merge(a, b->l);
        pull(b);
        return b;
    }
}
 
void split(Treap *t, int k, Treap *&a, Treap *&b) {
    if ( !t ) { a = b = NULL; return; }
    if ( size(t->l) < k ) {
        a = t;
        push(a);
        split(t->r, k - size(t->l) - 1, a->r, b);
        pull(a);
    } else {
        b = t;
        push(b);
        split(t->l, k, a, b->l);
        pull(b);
    }
}
 
Treap* make(int key, ll val) {
    return new (Treap::pmem++) Treap(key, val);
}
 
void solve() {
    Treap *t = NULL, *tl, *tr;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf("%lld", &num);
        t = merge(t, make(i, num));
    }
    scanf("%d", &q);
    while ( q-- ) {
        int x, y, c;
        ll z;
        scanf("%d", &c);
        if ( c == 1 ) {
            scanf("%d %d %lld", &x, &y, &z);
            split(t, x-1, tl, t);
            split(t, y-x+1, t, tr);
            t->add += z;
            t->val += z;
            t->sum += t->size * z;
            t = merge(merge(tl, t), tr);
        } else {
            scanf("%d %d", &x, &y);
            split(t, x-1, tl, t);
            split(t, y-x+1, t, tr);
            printf("%lld\n", sum(t));
            t = merge(merge(tl, t), tr);
        }
    }
    Treap::pmem = Treap::mem;
}
 
int main() {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
 
    while ( scanf("%d", &n) == 1 ) solve();
 
    return 0;
}

