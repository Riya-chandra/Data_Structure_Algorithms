class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        vector<vector<string>> ans;
        int n = words.size();

        for (int i = 0; i < n; i++) {          //  tp
            for (int j = 0; j < n; j++) {      // left
                if (j == i) continue;
                for (int k = 0; k < n; k++) {  // right
                    if (k == i || k == j) continue;
                    for (int l = 0; l < n; l++) { // bottom
                        if (l == i || l == j || l == k) continue;

                        string top = words[i];
                        string left = words[j];
                        string right = words[k];
                        string bottom = words[l];

                        if (top[0] == left[0] &&
                            top[3] == right[0] &&
                            bottom[0] == left[3] &&
                            bottom[3] == right[3]) {

                            ans.push_back({top, left, right, bottom});
                        }
                    }
                }
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};
