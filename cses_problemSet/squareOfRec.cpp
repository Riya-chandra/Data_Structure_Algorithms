#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int l1, b1, l2, b2, l3, b3;
        cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;
        int area = l1 * b1 + l2 * b2 + l3 * b3;
        int side = sqrt(area);

        int arr[] = {l1, b1, l2, b2, l3, b3};
        int max_side = *max_element(arr, arr + 6);

        if (side * side != area || max_side > side) {
            cout << "NO\n";
            continue;
        }

        bool ans = false;
        ans|=(b1==side && b2==side && b3==side && l1+l2+l3==side);
        ans|=(l1==side && l2==side && l3==side && b1+b2+b3==side);
        ans|=(b2==b3 && l2+l3==side && l1==side && b1+b2==side);
        ans|=(l2==l3 && b2+b3==side &&b1==side && l1+l2==side);
        cout<<(ans?"YES\n" :"NO\n");
    }
    return 0;
}
