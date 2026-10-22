class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return 0;

        bool inc = true, dec = true;

        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;

            if (nums[j] != (nums[i] + 1) % n)
                inc = false;

            if (nums[j] != (nums[i] - 1 + n) % n)
                dec = false;
        }

        int p = 0;
        while (nums[p] != 0) p++;

        int ans = INT_MAX;

        if (inc)
            ans = min(ans, min(p, n - p + 2));

        if (dec)
            ans = min(ans, min(n - p, p + 2));

        return ans == INT_MAX ? -1 : ans;
    }
};