class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        int n = technique1.size();
        long long total = 0;
        int cnt1 = 0;

        priority_queue<int, vector<int>, greater<int>> loss;

        for (int i = 0; i < n; i++) {
            if (technique1[i] >= technique2[i]) {
                total += technique1[i];
                cnt1++;
            } else {
                total += technique2[i];
                loss.push(technique2[i] - technique1[i]);
            }
        }

        if (cnt1 >= k) return total;

        int need = k - cnt1;
        while (need--) {
            total -= loss.top(); 
            loss.pop();
        }

        return total;
    }
};
