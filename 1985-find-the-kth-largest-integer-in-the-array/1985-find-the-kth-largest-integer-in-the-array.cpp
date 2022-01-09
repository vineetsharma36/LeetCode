class Solution {
public:
    static bool myCmp(string s1, string s2){
        if(s1.length()==s2.length())
            return s1>s2;
        return s1.length()>s2.length();        
    }
    
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(),nums.end(),myCmp);
        return nums[k-1];
    }
};