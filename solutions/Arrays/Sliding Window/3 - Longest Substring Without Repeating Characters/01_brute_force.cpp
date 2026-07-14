class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int maxLength=0;
        for(int i=0;i<s.length();i++){
            unordered_set<char> seen;
            
            for(int j=i;j<s.length();j++){
                if(seen.count(s[j])){
                    
                    break;
                }else{
                seen.insert(s[j]);
                maxLength=max(maxLength,j-i+1);
                }
            }
        }
        return maxLength;
    }
};