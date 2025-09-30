class Solution {
public:
    vector<string> result;
    
    void backtrack(string &num, int target, int index, long currVal, long prevVal, string expr) {
        if(index == num.size()) {
            if(currVal == target) {
                result.push_back(expr);
            }
            return;
        }
        
        for(int i = index; i < num.size(); i++) {
            // avoid leading zeros
            if(i != index && num[index] == '0') break;
            
            string part = num.substr(index, i - index + 1);
            long val = stol(part);
            
            if(index == 0) {
                // first number, no operator
                backtrack(num, target, i + 1, val, val, part);
            } else {
                backtrack(num, target, i + 1, currVal + val, val, expr + "+" + part);
                backtrack(num, target, i + 1, currVal - val, -val, expr + "-" + part);
                // for '*', adjust previous multiplication
                backtrack(num, target, i + 1, currVal - prevVal + prevVal * val, prevVal * val, expr + "*" + part);
            }
        }
    }
    
    vector<string> addOperators(string num, int target) {
        backtrack(num, target, 0, 0, 0, "");
        return result;
    }
};
