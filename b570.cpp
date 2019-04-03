#include <bits/stdc++.h>
using namespace std;
typedef pair<int , int> pii;
#define INF 0x3f3f3f3f
#define F first
#define S second
#define MAX 10010

int n, m, q, now;
int p[MAX], cal[MAX];
unordered_set<int> s; //
vector<pii> v;
vector<int> b, ans;

int findset(int x) {
    return p[x] == x ? x : p[x] = findset(p[x]);
}

void init() {
    now = n;
    for(int i = 1; i <= n; i++) {
        p[i] = i;
        cal[i] = 1;
    }
    b.clear();
    ans.clear();
    s.clear();
    v.resize(m + 5);
}

void merge(int x, int y) {
    x = findset(x); y = findset(y);
    if(x == y) return;
    
    if(cal[x] > cal[y]) {
        p[y] = x;
        cal[x] += cal[y];
    }
    else {
        p[x] = y;
        cal[y] += cal[x];
    }
    now--;
}

void solve() {
    for(int i = 1; i <= m; i++) {
        if(s.count(i)) continue; //
        merge(v[i].F, v[i].S);
    }
    
    for(int i = q; i >= 1; i--) {
        ans[i] = now;
        
        //if(b[i] == INF) continue;
        
        merge(v[b[i]].F, v[b[i]].S);
    }
}

int main() {
    cin >> n >> m;
    init();
    
    for(int i = 1; i <= m; i++) cin >> v[i].F >> v[i].S;
    
    cin >> q;
    b.resize(q + 5); ans.resize(q + 5);
    
    for(int i = 1; i <= q; i++) {
        cin >> b[i];
        s.insert(b[i]);
    }
    
    solve();
    
    for(int i = 1; i <= q; i++) cout << ans[i] << '\n';
    return 0;
}
