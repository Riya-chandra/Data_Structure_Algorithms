#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for (auto &x : a) cin >> x;
        for (auto &x : b) cin >> x;

        ll ans = 0;
        bool ok = true;

        for (int i = 0; i < n; i++) {
            int j = i;

            // find first element that can become b[i]
            while (j < n && a[j] > b[i]) j++;

            if (j == n) {
                ok = false;
                break;
            }

            // bring a[j] to position i
            while (j > i) {
                swap(a[j], a[j - 1]);
                j--;
                ans++;
            }
        }

        cout << (ok ? ans : -1) << '\n';
    }

    return 0;
}
