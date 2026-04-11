class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for(auto word: strs)
        {
            auto sortedword=word;
            sort(sortedword.begin(),sortedword.end());
            groups[sortedword].push_back(word);
        }
        vector<vector<string>> result;
        for(auto group:groups)
            result.push_back(group.second);
        return result;
    }
};
