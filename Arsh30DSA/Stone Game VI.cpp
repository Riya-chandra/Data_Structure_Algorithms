class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n=aliceValues.size();
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<n;i++){
            pq.push({aliceValues[i]+bobValues[i],i});
        }
        int alice=0;
        int bob=0;
        int turn =0;
        while(!pq.empty()){
            int idx=pq.top().second;
            pq.pop();
            if(turn %2==0) alice+=aliceValues[idx];
            else bob+=bobValues[idx];

            turn++;
        }
        if(alice>bob) return 1;
        else if(alice<bob) return -1;
        else return 0;
    }
};