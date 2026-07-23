class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int largest=nums[0];
        int index=0;
        int ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>largest){
                largest=nums[i];
                index=i;
            }

        }
        for(int j=0;j<nums.size();j++){
            if(index!=j and nums[index]<2*nums[j]){
                return -1;
            }
        
        
    }
    return index;
    }
};