// class Solution {
// public:
// //brute force
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<int> result;

//         for (int i = 0; i <= n - k; i++) {
//             int maxEle = INT_MIN;
//             for (int j = i; j < i + k; j++) {
//                 maxEle = max(maxEle, nums[j]);
//             }
//             result.push_back(maxEle);
//         }

//         return result;
//     }
// };




class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
       deque<int> deqe;
       vector<int> res;
       for(int i=0;i<n;i++){
        while(!deqe.empty() && deqe.front()<=i-k){
            deqe.pop_front();

        }
        while(!deqe.empty() && nums[i]>nums[deqe.back()]){  //if naya ele bara h deq k back se toh 
            deqe.pop_back();
        }
        deqe.push_back(i);
        if(i>=k-1){
            res.push_back(nums[deqe.front()]);
        }
       }
       return res;
    }
};

