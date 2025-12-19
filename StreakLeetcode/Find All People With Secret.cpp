class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {

        int maxTime = 0;
        for (auto &m : meetings)
            maxTime = max(maxTime, m[2]);

        // time -> list of meetings
        vector<vector<pair<int,int>>> timeMeet(maxTime + 1);
        for (auto &m : meetings) {
            timeMeet[m[2]].push_back({m[0], m[1]});
        }

        unordered_set<int> secret;
        secret.insert(0);
        secret.insert(firstPerson);

        // process time in increasing order
        for (int t = 1; t <= maxTime; t++) {

            bool changed = true;

            while (changed) {
                changed = false;

                for (auto &p : timeMeet[t]) {
                    int u = p.first;
                    int v = p.second;

                    if (secret.count(u) && !secret.count(v)) {
                        secret.insert(v);
                        changed = true;
                    }
                    else if (secret.count(v) && !secret.count(u)) {
                        secret.insert(u);
                        changed = true;
                    }
                }
            }
        }

        vector<int> ans(secret.begin(), secret.end());
        return ans;
    }
};
