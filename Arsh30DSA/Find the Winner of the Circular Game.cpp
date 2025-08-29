class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> friends;
        for(int i=1;i<=n;i++) friends.push_back(i);

        int idx = 0;
        while(friends.size() > 1) {
            idx = (idx + k - 1) % friends.size();  
            friends.erase(friends.begin() + idx);  
        }
        return friends[0];  
    }
};
