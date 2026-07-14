class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
    
       int n=nums.size();
       int sum=0;
       int left=0;
       int minLength=n+1;
       for(int right=0;right<n;right++){
            sum+= nums[right];
            while(sum>=target){
                minLength=min(minLength,right-left+1);
                sum=sum-nums[left];
                left++;
                
            }
       }
       if(minLength==n+1){
        return 0;
       }
       return minLength;
    }
};