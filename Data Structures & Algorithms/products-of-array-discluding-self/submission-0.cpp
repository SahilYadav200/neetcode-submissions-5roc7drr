class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
    
        // Step 1: Initialize arrays with 1s
        vector<int> prefix(n, 1);
        vector<int> postfix(n, 1);
        vector<int> result(n);
        
        // Step 2: Fill the Prefix array
        // Each position 'i' stores the product of all elements to the LEFT of 'i'
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        // Step 3: Fill the Postfix array
        // Each position 'i' stores the product of all elements to the RIGHT of 'i'
        for (int i = n - 2; i >= 0; i--) {
            postfix[i] = postfix[i + 1] * nums[i + 1];
        }

        // Step 4: Combine them
        for (int i = 0; i < n; i++) {
            result[i] = prefix[i] * postfix[i];
        }

        return result;
    }
};
