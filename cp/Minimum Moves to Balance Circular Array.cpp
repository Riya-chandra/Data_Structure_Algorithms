class Solution {
public:
    long long minMoves(vector<int>& balance) {

        int n = balance.size();
        int neg = -1;

       //neg index dudh liye
        for (int i = 0; i < n; i++) {
            if (balance[i] < 0) {
                neg = i;
                break;
            }
        }
        if (neg == -1) return 0;
  //agr total sum hi nutrilize nhi ho paa rha toh kbhi possible nhi hai
        long long total = 0;
        for (int x : balance) total += x;
        if (total < 0) return -1;

        long long need = -balance[neg]; // kitna chahiye neg ko 0 banane ke liye
        long long moves = 0;

        int dist = 1;

        while (need > 0 && dist < n) {

            int left = (neg - dist + n) % n;
            int right = (neg + dist) % n;

            // left se lo
            if (balance[left] > 0 && need > 0) {
                long long take = min((long long)balance[left], need);
                moves += take * dist;   
                need -= take;
            }

            if (balance[right] > 0 && need > 0) {
                long long take = min((long long)balance[right], need);
                moves += take * dist;   
                need -= take;
            }

            dist++; 
        }

        return (need == 0 ? moves : -1);
    }
};
