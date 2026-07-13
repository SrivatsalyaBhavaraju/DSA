class Solution {
public:
    bool isVowel(char c){
            return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
        }
    int maxVowels(string s, int k) {
        
        int vowelCount=0;
        int maxVowels=0;
        int n=s.length();
        for(int i=0;i<k;i++){
            if(isVowel(s[i])){
                vowelCount++;
            
            }

        }
        maxVowels=vowelCount;
        for(int j=k;j<n;j++){
            if(isVowel(s[j-k])){
                vowelCount--;
            }
            if(isVowel(s[j])){
                vowelCount++;
            }
            maxVowels=max(maxVowels,vowelCount);
        }
        
        return maxVowels;
        }
        
    
};