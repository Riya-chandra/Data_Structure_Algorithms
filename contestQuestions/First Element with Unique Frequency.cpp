class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        
        unordered_map<int,int> freq;
        for(int x : nums) {
            freq[x]++;
        }
        
        unordered_map<int,int> freqCount;
    
        for(auto it : freq) {
            freqCount[it.second]++;
        }

        for(int i=0;i<nums.size();i++){
            int ele=nums[i];
            if(freq.find(ele)!=freq.end()){
                int f=freq[ele];
                if(freqCount.count(f)&& freqCount[f]==1)
                {
                    return ele;
                }
            }
        }

        
        return -1;
    }
};
