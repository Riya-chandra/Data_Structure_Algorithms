#include <vector>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        //maxAND value always less or equal to th emax element of the whole array
        int maxValue=0;
        int countMaxLength=0;
        int result=1;
        for(int num: nums){
          if(num>maxValue){
            maxValue=num;
            result=0;
            countMaxLength=0;
          }
          if(maxValue==num){
            countMaxLength++;
          } else{
            countMaxLength=0;
          }
          result=max(result,countMaxLength);
        }
return result;
    }
};