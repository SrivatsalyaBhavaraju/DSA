class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        vector<int> prefix;
        prefix.resize(nums.size());
        prefix[0]=nums[0];
        int n=nums.size();
        
        for(int i=1;i<nums.size();i++){
            prefix[i]=nums[i]+prefix[i-1];

        }
        int totalSum=prefix[n-1];
        for(int i=0;i<nums.size();i++){
            int leftSum;
            int rightSum;
            if(i==0){
                leftSum=0;
            }else{
                leftSum=prefix[i-1];
            }
            if(i==n){
                rightSum=0;
            }
            else{
                rightSum=totalSum-prefix[i];
            }
            if(leftSum==rightSum){
                return i;
        }
        
        }
        return -1;
    }
};