#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        unordered_set<long long> diffCol;
        for(int i = 0; i < n; i++){
            long long x;
            cin >> x;
            diffCol.insert(x);
        }

        long long cur = diffCol.size();

        // Increase distinct count until cur already exists
        while(diffCol.count(cur) == 0){
            diffCol.insert(cur);
            cur++;
        }

        cout << cur << "\n";
    }
    return 0;
}
