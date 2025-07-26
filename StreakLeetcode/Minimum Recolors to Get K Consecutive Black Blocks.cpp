#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
     int n = blocks.length();
        vector<int> whiteCounts(n - k + 1); // Har window ke liye white count store karenge

        // Pehli window ka `W` count nikalna
        int whiteCount = 0;
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') {
                whiteCount++;
            }
        }
        whiteCounts[0] = whiteCount; // Pehli window ka count store karna

        // Sliding window apply karna
        for (int i = 1; i <= n - k; i++) {
            // Purane window ka leftmost element hatao
            if (blocks[i - 1] == 'W') whiteCount--;
            // Naya rightmost element add karo
            if (blocks[i + k - 1] == 'W') whiteCount++;

            whiteCounts[i] = whiteCount; // Store current white count
        }

        return *min_element(whiteCounts.begin(), whiteCounts.end());
    }
};