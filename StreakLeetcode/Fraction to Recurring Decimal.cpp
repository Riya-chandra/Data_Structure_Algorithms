class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0)
            return "0";
        string result;
        if ((numerator < 0) ^ (denominator < 0)) {
            result += "-";
        }
        long long num = llabs(numerator);
        long long den = llabs(denominator); // menas without sign
                                            // 4/3
        result += to_string(num / den); //"1"
        long long rem = num % den;      // rem=1
        if (rem == 0)
            return result;
        result += ".";

        unordered_map<long long, int> remainderPos;
        while (rem != 0) {
            if (remainderPos.find(rem) !=
                remainderPos.end()) { // if agr 1 rem h aur wo kahi v map m mila
                result.insert(remainderPos[rem], "(");
                result += ")";
                break;
            }
            remainderPos[rem] = result.size();
            rem *= 10;                      // 10
            result += to_string(rem / den); // 10/3 = result="0.1"
            rem %= den;                     // rem="1"
        }
        return result;
    }
};