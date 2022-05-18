class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;
        int len = 0, n = s.length();
        
        // Frequency array to store frequency of characters
        int freq[256];
        
        // Make all elements of freq array  0
        memset(freq, 0, sizeof(freq));
        
        // Iterate the string using the right pointer
        while(right < n) {
            
            // Increase the freq of character by 1
            freq[s[right]]++;
            
            // If a duplicate is found increment the left counter till the frequency of the duplicate character becomes 1 
            while(freq[s[right]] > 1) {
                freq[s[left++]]--;
            }
            
            // update the max length
            len = max(len, right - left + 1);
            // Increase the right pointer
            right++;
        }
        
        // Return max length
        return len;
    }
};