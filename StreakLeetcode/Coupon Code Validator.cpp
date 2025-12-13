class Solution {
public:
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {

        int n = code.size();
        vector<pair<int, string>> validCoupons;

        for (int i = 0; i < n; i++) {

           
            if (isActive[i] == false)
                continue;


            int priority = -1;
            if (businessLine[i] == "electronics") priority = 0;
            else if (businessLine[i] == "grocery") priority = 1;
            else if (businessLine[i] == "pharmacy") priority = 2;
            else if (businessLine[i] == "restaurant") priority = 3;
            else continue; 

            
            if (code[i].length() == 0)
                continue;

            bool validCode = true;
            for (char ch : code[i]) {
                if (!(isalnum(ch) || ch == '_')) {
                    validCode = false;
                    break;
                }
            }
            if (!validCode)
                continue;

            
            validCoupons.push_back({priority, code[i]});
        }

        
        sort(validCoupons.begin(), validCoupons.end());

        
        vector<string> result;
        for (auto &p : validCoupons) {
            result.push_back(p.second);
        }

        return result;
    }
};
