class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {

        long long sum = 0;
        for (long long b : batteries) sum += b;

        long long left = 0;
        long long right = sum / n; 
        
        while (left < right) {
            long long mid = left + (right - left + 1) / 2;
            if (canRun(mid, n, batteries)) left = mid;
            else right = mid - 1;
        }

        return left;
    }

private:
    bool canRun(long long T, int n, const vector<int>& batteries) {
        long long total = 0;

        for (long long b : batteries) {
            total += min(b, T);
            if (total >= T * n) return true;  
        }

        return total >= T * n;
    }
};