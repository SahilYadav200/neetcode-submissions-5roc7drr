class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;

        vector<int> freq1(26, 0), freq2(26, 0);

        // count s1
        for (char c : s1) {
            freq1[c - 'a']++;
        }

        int windowSize = s1.length();

        for (int i = 0; i < s2.length(); i++) {
            // add current char to window
            freq2[s2[i] - 'a']++;

            // remove left char if window exceeded
            if (i >= windowSize) {
                freq2[s2[i - windowSize] - 'a']--;
            }

            // compare both frequency arrays
            if (freq1 == freq2) {
                return true;
            }
        }

        return false;
    }
};
