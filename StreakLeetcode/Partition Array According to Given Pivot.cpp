#include <vector>
using namespace std;
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        int countsmaller=0;
        int equal=0;
        for(int &num:nums){
            if(num<pivot){
                countsmaller++;
            }
            else if(num==pivot){
                equal++;
            }
        }
            int i=0;
            int j=countsmaller;
            int k=countsmaller+equal;
            vector<int>result(n);
            for(int &num:nums){
                if(num<pivot){
                    result[i]=num;
                    i++;
                }
                else if(num==pivot){
                    result[j]=num;
                    j++;
                }
                else{
                    result[k]=num;
                    k++;
                }

            }
        
        return result;
    }
};