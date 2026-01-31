class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n=letters.size();
        for(int i=0;i<n;i++){
            if(target-'a'< letters[i]-'a'){
            return letters[i];
            }
        }
        return letters[0];
    }
};
