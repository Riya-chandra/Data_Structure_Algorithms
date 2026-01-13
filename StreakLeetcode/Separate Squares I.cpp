class Solution {
public:

         double separateSquares(vector<vector<int>>& squares) {
               double low = 0, high = 0;
        
        // Step 1: Determine the min and max y-values to set the binary search range.
        for (auto& square : squares) {
            // Finding the highest point (top) of any square
            high = max(high, (double)(square[1] + square[2])); // y + l is the top y-coordinate
        }
        
        // Step 2: Helper function to calculate the area difference
        auto computeArea = [&](double h) {
            double areaAbove = 0, areaBelow = 0;
            
            for (auto& square : squares) {
                int x = square[0], y = square[1], l = square[2];
                double top = y + l, bottom = y;
                
                // If the square is completely below the line
                if (top <= h) {
                    areaBelow += (double)(l) * (double)(l); // **Cast l to double before multiplication**
                }
                // If the square is completely above the line
                else if (bottom >= h) {
                    areaAbove += (double)(l) * (double)(l); // **Cast l to double before multiplication**
                }
                // If the square is split by the line
                else {
                    // Area above the line
                    double abovePart = top - h;
                    // Area below the line
                    double belowPart = h - bottom;
                    
                    areaAbove += abovePart * l;
                    areaBelow += belowPart * l;
                }
            }
            
            return areaAbove - areaBelow; // Return the difference in areas
        };

        // Step 3: Binary search for the horizontal line where areas balance
        while (high - low > 1e-5) {
            double mid = (low + high) / 2;
            if (computeArea(mid) > 0) {
                low = mid; // Move up if areaAbove > areaBelow
            } else {
                high = mid; // Move down if areaAbove < areaBelow
            }
        }
        
        return low;
    
    }
};
