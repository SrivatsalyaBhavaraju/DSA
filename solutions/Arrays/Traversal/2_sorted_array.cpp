class Solution{
    public:
    bool sortedArray(vector <int> &nums){
        int n=nums.size();
        if(n<=1){
            return true;
        }
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]){
                return false;
            }
        }
        return true;
    }
};