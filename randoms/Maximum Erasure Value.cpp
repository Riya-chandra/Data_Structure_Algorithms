class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
    unordered_set<int>st;
    deque<int>dq;
    int sum=0;
    int result=0;
for(auto num:nums){
  while(st.count(num)){
    int front=dq.front();
    dq.pop_front();
    st.erase(front);
    sum-=front; //sum m se front ko minus kr denge
  }
  dq.push_back(num);
  st.insert(num);
  sum+=num;
  result=max(result,sum);
}
return result;
    }
};