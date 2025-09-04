class Solution {
public:
    int findClosest(int x, int y, int z) {
        int person1=abs(z-x); //4
        int person2=abs(z-y);  //1
        if(person1==person2) return 0;
        if(person1 < person2) return 1;
        else{
            return 2;
        }

    }
};