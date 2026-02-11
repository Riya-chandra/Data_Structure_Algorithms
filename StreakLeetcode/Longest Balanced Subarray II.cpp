#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    vector<int> segMin, segMax, lazy;

    // Push lazy updates
    void push(int idx, int l, int r) {
        if(lazy[idx] != 0) {
            segMin[idx] += lazy[idx];
            segMax[idx] += lazy[idx];

            if(l != r) {
                lazy[2*idx+1] += lazy[idx];
                lazy[2*idx+2] += lazy[idx];
            }
            lazy[idx] = 0;
        }
    }

    // Range update with lazy propagation
    void updateRange(int ql, int qr, int idx, int l, int r, int val) {
        push(idx, l, r);

        if(qr < l || ql > r) return;

        if(ql <= l && r <= qr) {
            lazy[idx] += val;
            push(idx, l, r);
            return;
        }

        int mid = (l + r) / 2;

        updateRange(ql, qr, 2*idx+1, l, mid, val);
        updateRange(ql, qr, 2*idx+2, mid+1, r, val);

        segMin[idx] = min(segMin[2*idx+1], segMin[2*idx+2]);
        segMax[idx] = max(segMax[2*idx+1], segMax[2*idx+2]);
    }

    // Find leftmost index where value == 0
    int findLeftMostZero(int idx, int l, int r) {
        push(idx, l, r);

        // If zero cannot exist here
        if(segMin[idx] > 0 || segMax[idx] < 0)
            return -1;

        if(l == r)
            return l;

        int mid = (l + r) / 2;

        push(2*idx+1, l, mid);

        if(segMin[2*idx+1] <= 0 && segMax[2*idx+1] >= 0)
            return findLeftMostZero(2*idx+1, l, mid);

        return findLeftMostZero(2*idx+2, mid+1, r);
    }

    int longestBalanced(vector<int>& nums) {
        n = nums.size();

        segMin.assign(4*n, 0);
        segMax.assign(4*n, 0);
        lazy.assign(4*n, 0);

        int maxL = 0;
        unordered_map<int,int> mp;

        for(int r = 0; r < n; r++) {

            int val = (nums[r] % 2 == 0) ? 1 : -1;

            int prev = -1;
            if(mp.count(nums[r]))
                prev = mp[nums[r]];

            // Remove previous contribution if duplicate
            if(prev != -1)
                updateRange(0, prev, 0, 0, n-1, -val);

            // Add new contribution
            updateRange(0, r, 0, 0, n-1, val);

            int l = findLeftMostZero(0, 0, n-1);

            if(l != -1)
                maxL = max(maxL, r - l + 1);

            mp[nums[r]] = r;
        }

        return maxL;
    }
};
