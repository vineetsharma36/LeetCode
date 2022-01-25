class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size()<3)
            return false;
        int n=arr.size();
        if(arr[0]>=arr[1] || arr[n-2]<=arr[n-1])
            return false;
        int ind=0;
        for(int i=1;i<n-1;i++){
            if(arr[i]==arr[i-1])
                return false;
            if(arr[i-1]>arr[i])
                break;
            ind=i;
        }
        for(int i=ind+1;i<n;i++){
            if(arr[i-1]<=arr[i])
                return false;
        }
        return true;
    }
};