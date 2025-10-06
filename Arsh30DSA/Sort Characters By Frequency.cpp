class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        int n = s.length();
        for (auto it : s) {
            freq[it]++;
        } // now after arranging the char in unorder map we have to take the
          // char having highr freq
        vector<pair<char, int>> arr(
            freq.begin(), freq.end()); // sorting the freq by its maximum number
            sort(arr.begin(), arr.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });
        string result = "";
        for (auto it : arr) {
            result.append(it.second, it.first);
        }
        return result;
    }
};