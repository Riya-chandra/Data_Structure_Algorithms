class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size(); // n
        if (n % groupSize != 0)
            return false; //  9%3 ==0 but 10%3 !=0 then clealry false
        map<int, int> count;
        for (int card : hand) {
            count[card]++; // counting of the hands ..how many they are
        }
        for (auto& [card, freq] : count) {
            if (freq > 0) {
                int need = freq; // 2=2  need =2
                for (int i = 0; i < groupSize; i++) {
                    int nextCard = card + i;    // 2+1=3
                    if (count[nextCard] < need) // mtlb agr need 2 hai ln count
                                                // m 1 hai toh not enogh cards
                        return false;
                    count[nextCard] -= need;
                } 
            }
        }

        return true;
    }
};