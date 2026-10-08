class Solution {
public:
    string minWindow(string s, string t) {

        if (t.size() > s.size())
            return "";

        vector<int> need(128, 0);
        vector<int> window(128, 0);

        // Frequency required from t
        for (char c : t) {
            need[c]++;
        }

        int required = t.size();
        int formed = 0;

        int left = 0;
        int right = 0;

        int minLen = INT_MAX;
        int start = 0;

        while (right < s.size()) {

            // Add current character
            char c = s[right];
            window[c]++;

            // This occurrence is useful
            if (window[c] <= need[c]) {
                formed++;
            }

            // Window contains everything required
            while (formed == required) {

                // Update answer
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                // Remove left character
                char leftChar = s[left];
                window[leftChar]--;

                // We removed a character that was needed
                if (window[leftChar] < need[leftChar]) {
                    formed--;
                }

                left++;
            }

            right++;
        }

        if (minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};