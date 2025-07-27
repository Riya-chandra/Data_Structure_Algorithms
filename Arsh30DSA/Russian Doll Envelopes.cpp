#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
int binarySearch(vector<int>& heightsLis, int h) {
    int left = 0, right = heightsLis.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (heightsLis[mid] >= h) {
            right = mid - 1; // Narrow the search to the left side
        } else {
            left = mid + 1;  // Narrow the search to the right side
        }
    }
    return left;
}
    int maxEnvelopes(vector<vector<int>>& envelopes) {
       sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
    if (a[0] == b[0]) {
        return a[1] > b[1]; 
    }
    return a[0] < b[0];    
    });
    vector<int> heights;
   for(auto &env: envelopes){
    heights.push_back(env[1]);//height push hoyga
   }
vector<int>heightsLis;
for(int h :heights){
int pos=binarySearch(heightsLis,h);    //
if(pos==heightsLis.size()){
    heightsLis.push_back(h);
}
else{
heightsLis[pos]=h;
}
}
return heightsLis.size();
    }
};