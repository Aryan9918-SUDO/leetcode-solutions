class Solution {
public:
    int numberOfSubstrings(string s) {

        int n = s.size();

        vector<int> freq(26, 0);

        int distinct = 0;
        int left = 0;
        int right = 0;
        int count = 0;

        while (right < n) {

            // Add s[right]
            freq[s[right] - 'a']++;

            if (freq[s[right] - 'a'] == 1) {
                distinct++;
            }

            // While window contains a, b and c
            while (distinct == 3) {

                // Current window is valid
                count += n - right;

                // Remove s[left]
                freq[s[left] - 'a']--;

                if (freq[s[left] - 'a'] == 0) {
                    distinct--;
                }

                left++;
            }

            right++;
        }

        return count;
    }
};