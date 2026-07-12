class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
       int leftSum;
       int rightSum;
       int n=nums.size();
       vector<int> answer(n);
       vector<int> prefix;
       prefix.resize(nums.size());
       prefix[0]=nums[0];
       for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+nums[i];
       }
       int totalSum=prefix[n-1];
       for(int i=0;i<nums.size();i++){
        if(i==0){
            leftSum=0;
        }else{
        leftSum=prefix[i-1];
        }
        if(i==n-1){
            rightSum=0;
        }else{
            rightSum=totalSum-prefix[i];
        }
        answer[i]=abs(rightSum-leftSum);
        

       }
       return answer;
    }
};