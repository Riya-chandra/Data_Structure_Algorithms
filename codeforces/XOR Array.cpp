#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n, l, r;
        cin >> n >> l >> r;

        vector<long long> pref(n+1);
        vector<long long> a(n+1);

        // Make all prefix values unique except pref[l-1] == pref[r]
        long long val = 1;

        for(int i = 0; i <= n; i++) pref[i] = ++val;

        // Force XOR condition
        pref[r] = pref[l-1];

        // Build array: a[i] = pref[i] XOR pref[i-1]
        for(int i = 1; i <= n; i++)
            a[i] = pref[i] ^ pref[i-1];

        for(int i = 1; i <= n; i++)
            cout << a[i] << " ";
        cout << "\n";
    }
    return 0;
}
