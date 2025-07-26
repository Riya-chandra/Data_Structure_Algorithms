#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    long long moves = 0;
    long long mx = 0;
    for (int i = 0; i < n; i++) {
        long long num;
        cin >> num;
        if (num < mx) {
            moves += mx - num;
        }
        mx = max(mx, num);
    }
    cout << moves << endl;
    return 0;
}
