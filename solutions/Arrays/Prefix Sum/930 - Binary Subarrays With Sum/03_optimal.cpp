class Solution {
public:
    int subarraySum(vector<int>& nums, int goal) {
    int currentPrefix=0;
    unordered_map <int,int> mp;
    mp[0]=1;
    int count=0;
    for(int i=0;i<nums.size();i++){
        currentPrefix+=nums[i];
        int need=currentPrefix-goal;
        if(mp.count(need)){
            count+=mp[need];
        }
        mp[currentPrefix]++;
    }
    return count;
    }
};