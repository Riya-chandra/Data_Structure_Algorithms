class Solution {
public:
    int countTriples(int n) {
        unordered_set<int> sq;
        for(int i=0;i<=n;i++){
            sq.insert(i*i);
        } 
        int count=0;
        for(int a=1;a<n;a++){
            for(int b=1;b<n;b++){
                int sum =a*a+b*b;
                if(sq.count(sum)) {
                    count ++;
                }
            }
        }
return count ;
    }
};