class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {

        int n = nums.size();

        // dp[i] = length of LIS ending at i
        vector<int> dp(n, 1);

        // count[i] = number of LIS of length dp[i]
        // ending at i
        vector<int> count(n, 1);

        int maxLen = 1;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < i; j++) {

                if (nums[j] < nums[i]) {

                    // Found a longer LIS
                    if (dp[j] + 1 > dp[i]) {

                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    }

                    // Found another LIS of same length
                    else if (dp[j] + 1 == dp[i]) {

                        count[i] += count[j];
                    }
                }
            }

            maxLen = max(maxLen, dp[i]);
        }

        // Add counts of all LIS ending positions
        int ans = 0;

        for (int i = 0; i < n; i++) {

            if (dp[i] == maxLen) {
                ans += count[i];
            }
        }

        return ans;
    }
};