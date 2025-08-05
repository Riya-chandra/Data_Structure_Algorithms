#include <vector>
#include <unordered_map>
using namespace std;

using namespace std;
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<bool> used(n, false); // Track which baskets are used
        int unplaced = 0;

        for (int i = 0; i < n; i++) {
            bool placed = false;
            for (int j = 0; j < n; j++) {
                if (!used[j] && baskets[j] >= fruits[i]) {
                    used[j] = true;
                    placed = true;
                    break; // placed in leftmost available basket
                }
            }
            if (!placed) {
                unplaced++;
            }
        }

        return unplaced;
    }
};
