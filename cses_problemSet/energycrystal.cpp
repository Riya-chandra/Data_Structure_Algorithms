#include <iostream>
using namespace std;

void solve() {
    int x;
    cin >> x;
    cout << 2 * (64 - __builtin_clzll(x)) + 1 << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve(); 
    }
    return 0;
}