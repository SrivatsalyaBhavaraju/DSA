class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> prefix;
        prefix.resize(nums.size());
        prefix[0]=nums[0];
        for(int i = 1; i < nums.size(); i++) {
    prefix[i] = prefix[i-1] + nums[i];
}
        int leftSum;
        int rightSum;
        int n = nums.size();
        for(int i=0;i<nums.size();i++){
            if (i==0){
                leftSum=0;
            }else{
                leftSum=prefix[i-1];
            }
            if (i==n-1){
                rightSum=0;
            }else{
                rightSum=prefix[n-1]-prefix[i];
            }
            if(leftSum==rightSum){
                return i;
            }

        }
        return -1;
    }
};