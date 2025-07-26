#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int n=nums.size();
        for(int i=0;i<=n-k;i++){
            unordered_map<int,int> windowFreq;
            for(int j=i;j<i+k;j++){
                windowFreq[nums[j]]++;
            }
            for(auto& p:windowFreq){
                freq[p.first]++;
            }
        }
        int result = -1;
    // Find the largest number appearing in exactly one subarray
    for (auto& p : freq) {
        if (p.second == 1) {
            result = max(result, p.first);
        }
    }
        return result;
    }
};