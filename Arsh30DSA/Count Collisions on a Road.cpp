class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int i = 0, j = n - 1;

        // ignore leading L because wo bound k baahr chla jyga 
        while(i < n && directions[i] == 'L') i++;

      //similarly yaha v agr R milega toh bound k baahr chla jyega 
        while(j >= 0 && directions[j] == 'R') j--;

        int collisions = 0;
        for(int k = i; k <= j; k++) {
            if(directions[k] != 'S') collisions++;
        }

        return collisions;
    }
};
