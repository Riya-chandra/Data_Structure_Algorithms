class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        // Code here
        queue<int>police;
        queue<int> thieve;
        int c=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]=='P')
            police.push(i);
            else 
            thieve.push(i);
            
            
        while(!police.empty() && !thieve.empty()){
            if(abs(police.front()-thieve.front())<=k){
                c++;
                police.pop();
                thieve.pop();
            }
            else if(police.front()<thieve.front())
            police.pop();
            else 
                thieve.pop();
            
        }    
       
        }
        return c;
    }
};