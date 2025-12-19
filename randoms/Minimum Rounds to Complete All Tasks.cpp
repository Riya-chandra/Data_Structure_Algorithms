class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int n = tasks.size();
        int count = 0;
        unordered_map<int, int> freq;
        for (int t : tasks)
            freq[t]++;
        for (auto it : freq) {

            int f = it.second;
            if (f == 1)
                return -1;
            
            if (f % 3 != 0)
                count++;
                count += f / 3;
        }
        return count;
    }
};