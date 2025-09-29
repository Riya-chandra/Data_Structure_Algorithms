class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        vector<int> result = cells;
        unordered_map<string, int> seen; // store state -> remaining days

        while(n > 0){
            string state = "";
            for(int c : result) state += to_string(c);

            if(seen.count(state)){
                // cycle found, reduce n
                int cycle_length = seen[state] - n;
                n %= cycle_length;
            }
            seen[state] = n;

            if(n >= 1){
                n--;
                vector<int> next(8,0); // first & last always 0
                for(int i = 1; i <= 6; i++)
                    next[i] = (result[i-1] == result[i+1]) ? 1 : 0;
                result = next; //now new next is the result 
            }
        }

        return result;
    }
};
