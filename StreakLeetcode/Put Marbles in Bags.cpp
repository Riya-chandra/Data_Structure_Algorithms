#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n=weights.size();
        // if(k==n) return 0;
        int m=n-1;
        vector<int> pairsum(m,0);
        for(int i=0;i<m;i++){
            pairsum[i]=weights[i]+weights[i+1];
        }
          sort(begin(pairsum),end(pairsum));
          long maxsum=0;
          long minsum=0;
          for(int i=0;i<k-1;i++){
            minsum+=pairsum[i];
            maxsum+=pairsum[m-1-i];
          }
          return maxsum-minsum;
    }
};