#include <bits/stdc++.h>
using namespace std;
const int LIM = 2E6 + 10;

void pre(set<int> &st) {
    static int i = 0;
    if (i++) return;

    for (int p : {3, 5, 7}) {
        for (int q : {3, 5, 7}) {
            if (p <= q) continue;
            // p^i + q^j
            int pi = p;
            while (pi <= LIM) {
                int qj = q;
                while (pi + qj <= LIM) {
                    st.insert(pi + qj);
                    qj *= q;
                }
                pi *= p;
            }
        }
    }
    cerr << st.size() << '\n';
    for (int x : st) cerr << x << '\n';
    cerr << "\n\n\n";
}

int solve() {
    static set<int> st;
    pre(st);
    
    int n, c1, c2;
    cin >> n >> c1 >> c2;

    int lo = 0, hi;
    for (int x : st) {
        if (x == n) return 0;

        if (x < n) {
            lo = x;
        }
        else {
            hi = x;
            break;
        }
    }
    if (not lo) return (hi - n) * c2;
    return min((n - lo) * c1, (hi - n) * c2);
}

int main() {
    int t; cin >> t;
    while (t--) cout << solve() << '\n';
    return 0;
}