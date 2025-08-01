#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {
        int n = grid.size();

        long long N = n * n;

        long long gridSum = 0;
        long long gridSqSum = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                gridSum += grid[i][j];
                gridSqSum += grid[i][j] * grid[i][j];
            }
        }

        long long sum = (N * (N + 1)) / 2;                 // Expected sum of N natural numbers
        long long sqSum = (N * (N + 1) * (2 * N + 1)) / 6; // Expected sq sum of natural numbers

        int sqDiff = gridSqSum - sqSum;
        int sumDiff = gridSum - sum;

        int a = (sqDiff / sumDiff + sumDiff) / 2;
        int b = (sqDiff / sumDiff - sumDiff) / 2;

        return {a, b};
    }
};
