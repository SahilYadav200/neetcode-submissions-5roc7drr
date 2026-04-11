class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> count;
        int res=0;
        int l=0;
        for(int r=0;r<s.length();r++)
        {
            count[s[r]]++;

            // compute max frequency
            int maxFreq = 0;
            for (auto it : count) {
                maxFreq = max(maxFreq, it.second);
            }

            while((r-l+1)-maxFreq>k)
            {
                count[s[l]]-=1;
                l+=1;
            }

            // recompute after shrinking
            maxFreq = 0;
            for (auto it : count)
            {
                maxFreq = max(maxFreq, it.second);
            }
            res=max(res,r-l+1);
        }
        return res;
    }
};
