#include <bits/stdc++.h>
using namespace std;

int longestUniqueSubstring(string s) {
   vector<int> last(256,-1);
   int l=0;
   int maxLen=0;
   for(int r=0;r<s.size();i++){
      if(last[s[r]]>=1)
      l=last[s[r]]+1;
      last[s[r]]=r;
      maxLen=max(maxLen,r-l+1);
   }
return maxLen;
}
int main() {
    string s = "abcabcbb";
    cout << longestUniqueSubstring(s);
    return 0;
}