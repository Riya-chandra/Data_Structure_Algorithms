class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int totalApple = 0;
        for (int a : apple) {
            totalApple += a;
        }

        sort(capacity.begin(), capacity.end(), greater<int>());

        int usedBoxes = 0;
        int totalCap = 0;

        for (int c : capacity) {
            totalCap += c;
            usedBoxes++;
            if (totalCap >= totalApple) {
                return usedBoxes;
            }
        }

        return usedBoxes;
    }
};
