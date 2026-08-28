class Solution {
public:

    string makePalindrome(string half, char mid, bool odd) {
        string ans = half;

        if (odd)
            ans += mid;

        string rev = half;
        reverse(rev.begin(), rev.end());

        ans += rev;

        return ans;
    }

    string nextHalf(vector<int> halfCnt, string targetHalf) {

        int m = targetHalf.size();

        // Try changing a position as far right as possible.
        for (int pos = m - 1; pos >= 0; pos--) {

            vector<int> cnt = halfCnt;

            // Match targetHalf[0 ... pos-1]
            bool possible = true;

            for (int i = 0; i < pos; i++) {

                int c = targetHalf[i] - 'a';

                if (cnt[c] == 0) {
                    possible = false;
                    break;
                }

                cnt[c]--;
            }

            if (!possible)
                continue;

            // At pos, choose the smallest character
            // strictly greater than targetHalf[pos].
            int need = targetHalf[pos] - 'a';

            for (int c = need + 1; c < 26; c++) {

                if (cnt[c] == 0)
                    continue;

                string res = targetHalf.substr(0, pos);

                res += char('a' + c);

                cnt[c]--;

                // Fill remaining characters as small as possible.
                for (int x = 0; x < 26; x++) {
                    res += string(cnt[x], char('a' + x));
                }

                return res;
            }
        }

        return "";
    }

    string lexPalindromicPermutation(string s, string target) {

        int n = s.size();

        // -------------------------
        // 1. Count characters
        // -------------------------

        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        // -------------------------
        // 2. Check palindrome possible
        // -------------------------

        int odd = 0;
        char middle = 0;

        for (int c = 0; c < 26; c++) {

            if (freq[c] % 2) {
                odd++;
                middle = char('a' + c);
            }
        }

        if (odd > 1)
            return "";

        // -------------------------
        // 3. Build half frequency
        // -------------------------

        vector<int> halfCnt(26);

        for (int c = 0; c < 26; c++) {
            halfCnt[c] = freq[c] / 2;
        }

        int halfLen = n / 2;

        string targetHalf = target.substr(0, halfLen);

        string answer = "";

        // -------------------------
        // 4. Case 1:
        // Find half strictly greater
        // than targetHalf
        // -------------------------

        string h = nextHalf(halfCnt, targetHalf);

        if (!h.empty()) {

            answer = makePalindrome(
                h,
                middle,
                n % 2 == 1
            );
        }

        // -------------------------
        // 5. Case 2:
        // First half exactly equals
        // target's first half
        // -------------------------

        vector<int> cnt = halfCnt;

        bool possible = true;

        for (char c : targetHalf) {

            int x = c - 'a';

            if (cnt[x] == 0) {
                possible = false;
                break;
            }

            cnt[x]--;
        }

        if (possible) {

            // Construct palindrome using exactly
            // targetHalf as its first half.
            string candidate = makePalindrome(
                targetHalf,
                middle,
                n % 2 == 1
            );

            // This handles BOTH:
            // even length and odd length.
            if (candidate > target) {

                if (answer.empty() || candidate < answer) {
                    answer = candidate;
                }
            }
        }

        return answer;
    }
};