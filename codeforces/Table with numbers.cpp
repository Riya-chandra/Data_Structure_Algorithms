#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n, h, l;
        cin >> n >> h >> l;

        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        int small = min(h, l);
        int large = max(h, l);

        int i = 0, j = n - 1;
        int ans = 0;

        while(i < j){
            if(a[i] <= small && a[j] <= large){
                ans++;
                i++;
                j--;
            }
            else if(a[j] > large){
                j--;
            }
            else{
                i++;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
