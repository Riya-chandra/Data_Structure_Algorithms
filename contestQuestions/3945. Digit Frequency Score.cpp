class Solution {
public:
    int digitFrequencyScore(int n) {
        string s=to_string(n); //tn is converted in string 
        unordered_map<int,int> map;
        for(char it:s){
            map[it-'0']++; //counting the freq of the ele
        }
      int score=0;
      for(auto &it:map){
        score+=it.first*it.second;
      }
      return score; 
    }
};
