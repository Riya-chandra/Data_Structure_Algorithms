#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    if(!(cin >> t)) return 0;
    while(t--) {
        int n, k;
        string s;
        cin >> n >> k;
        cin >> s;
        int ans = 0;
        // use a very negative value for last so first real 1 triggers protection
        int last = -1000000; //last 1 kaha mila tha
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                if (i - last > (k - 1)) {  //if true then hi chlega
                    ans++;
                    last = i;
                } else {
                    // there's a surviving 1 within previous k-1 positions -> current safe
                    last = i;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
