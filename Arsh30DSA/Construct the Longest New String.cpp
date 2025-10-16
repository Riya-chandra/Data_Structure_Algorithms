class Solution {
public:
    int longestString(int x, int y, int z) {
         int minOf = min(x, y);

        int length = 4 * minOf;
        x -= minOf;
        y -= minOf;

        if (x > 0 || y > 0) {
            length += 2;
        }

        length += 2 * z;

        return length;
    }
    
};