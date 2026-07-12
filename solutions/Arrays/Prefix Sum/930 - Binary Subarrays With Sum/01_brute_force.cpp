class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        int count=0;
        for(int i=0;i<nums.size();i++){
            int sum=0;
            for(int j=i;j<nums.size();j++){
                sum+=nums[j];
                if(sum==goal){
                    count++;
                }
            }
        }
        return count;

    }
};