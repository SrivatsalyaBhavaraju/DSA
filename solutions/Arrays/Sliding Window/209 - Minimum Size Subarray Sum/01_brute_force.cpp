class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
    
        int n=nums.size();
        int minLength=n+1;
        for(int i=0;i<nums.size();i++){
            int sum=0;
            
            for(int j=i;j<nums.size();j++){
                sum+=nums[j];
                if(sum>=target){
                    minLength=min(minLength,j-i+1);
                    break;
                    }
                
                }
            
            }

            
        if(minLength==n+1){
                return 0;
            }
            return minLength;
    }
};