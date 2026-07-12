class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int currentPrefix=0;
        int count=0;
        
        
        unordered_map<int,int> mp;
        mp[0]=1;
        for(int i=0;i<nums.size();i++){
            currentPrefix+=nums[i];
            int remainder=((currentPrefix%k)+k)%k;
            count+=mp[remainder];
            mp[remainder]++;
        }
        
        return count;
    }
};