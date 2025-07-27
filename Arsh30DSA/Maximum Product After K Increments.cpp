#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
const int MOD = 1e9 + 7;
    int maximumProduct(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<int,vector<int>,greater<int>> minHeap(nums.begin(),nums.end());
       while(k--){
        int smallest=minHeap.top();
        minHeap.pop();
      minHeap.push(smallest + 1);
       }
          long long result = 1;
    while (!minHeap.empty()) {
        result = (result * minHeap.top()) % MOD;
        minHeap.pop();
    }

    return result;
    }
};