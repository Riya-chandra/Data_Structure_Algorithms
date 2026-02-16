class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<int> freq(101,0);
        for(int it: bulbs){
            freq[it]++;                     
        }
        vector<int> result;
    
        for(int i=1;i<=100;i++){
            if(freq[i]%2==1) result.push_back(i);
            
        }
        return result;
    }
};
