class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        map<int, vector<int>> freqToNums; // frequency → list of numbers
        for (auto& [num, count] : freq) {
            freqToNums[count].push_back(num);
        }

        vector<int> result;
        // Traverse in descending frequency order
        for (auto it = freqToNums.rbegin(); it != freqToNums.rend() && result.size() < k; ++it) {
            for (int num : it->second) {
                if (result.size() < k)
                    result.push_back(num);
            }
        }

        return result;
    }
};
