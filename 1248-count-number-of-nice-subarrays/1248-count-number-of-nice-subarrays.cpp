class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        int n = nums.size();

        int left1 = 0;
        int left2 = 0;

        int odd1 = 0;
        int odd2 = 0;

        int ans = 0;

        for (int right = 0; right < n; right++) {

            if (nums[right] % 2 == 1) {
                odd1++;
                odd2++;
            }

            // left1 maintains at most k odds
            while (odd1 > k) {
                if (nums[left1] % 2 == 1)
                    odd1--;

                left1++;
            }

            // left2 maintains at most k-1 odds
            while (odd2 >= k) {
                if (nums[left2] % 2 == 1)
                    odd2--;

                left2++;
            }

            // Difference gives exactly k odds
            ans += left2 - left1;
        }

        return ans;
    }
};