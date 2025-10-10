class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        string s= to_string(x); //"18"
        int n=s.size();
        int sum=0;
        for(auto it :s){
          sum+=it-'0';// getting sum of all strnig
        }
        //now we have to look does this sum is div by x
        if(x%sum==0) return sum;
      else 
        return -1;
      
    }
};