class Solution {
public:
    int missingNumber(vector<int>& nums) {
       int n=nums.size();
       int expectedsum=n*(n+1)/2;
       int sum=0;
       int i=0;
       while(i<nums.size()){
        sum+=nums[i];
        i++;
       }
      
            int missing=expectedsum-sum;
            return missing;
       

       
    }
    
};