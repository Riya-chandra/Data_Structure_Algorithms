class Solution {
public:
    long long lastInteger(long long n) {
        long long head = 1;
        long long step = 1;
        long long remaining = n;
        bool left = true;  

        while (remaining > 1) {
            if (left) {
        
            } else {
                if (remaining % 2 == 0) {
                    head += step;
                }
            }

            remaining = (remaining + 1) / 2;
            step *= 2;
            left = !left;
        }

        return head;
    }
};
