#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int pos = -1;

        // find first "RL"
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == 'R' && s[i + 1] == 'L') {
                pos = i;
                break;
            }
        }

        // count continuous R to left
        int left = 0;
        for (int i = pos; i >= 0 && s[i] == 'R'; i--) {
            left++;
        }

        // count continuous L to right
        int right = 0;
        for (int i = pos + 1; i < n && s[i] == 'L'; i++) {
            right++;
        }

        cout << left + right << "\n";
    }

    return 0;
}
