class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int emptyBottle = numBottles;

        if(emptyBottle < numExchange) return numBottles;

        while(emptyBottle >= numExchange) {
            emptyBottle = emptyBottle - numExchange; 
            numBottles++; 
            emptyBottle++;
            numExchange++; 
        }

        return numBottles;
    }
};
