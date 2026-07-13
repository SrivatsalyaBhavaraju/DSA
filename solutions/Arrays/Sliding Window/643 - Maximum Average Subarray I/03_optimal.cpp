class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        int maxSum=sum;
        for(int j=k;j<n;j++){
            sum=sum-nums[j-k]+nums[j];
            if(sum>maxSum){
                maxSum=sum;
            }
        
        }
        return (double)maxSum/k;
    }
};