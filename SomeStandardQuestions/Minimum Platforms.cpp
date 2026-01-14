// Arr: [900, 940, 950, 1100, 1500, 1800]
// Dep: [910, 1200, 1120, 1130, 1900, 2000]
// Output: 3


#include <bits/stdc++.h>
using namespace std;

int minPlatforms(vector<int>& arr, vector<int>& dep) {
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int i = 0, j = 0, platforms = 0, maxPlat = 0;
    int n = arr.size();

    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            platforms++;
            maxPlat = max(maxPlat, platforms);
            i++;
        } else {
            platforms--;
            j++;
        }
    }
    return maxPlat;
}

int main() {
    vector<int> arr = {900,940,950,1100,1500,1800};
    vector<int> dep = {910,1200,1120,1130,1900,2000};
    cout << minPlatforms(arr, dep);
    return 0;
}
