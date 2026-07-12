class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> leftProduct;
leftProduct.resize(nums.size());
vector<int> answer;

int n=nums.size();
answer.resize(n);
leftProduct[0]=1;

for(int i=1;i<nums.size();i++){
    
    leftProduct[i]=leftProduct[i-1]*nums[i-1];
    }
    vector <int> rightProduct;
    
    rightProduct.resize(nums.size());
    rightProduct[n-1]=1;
    for(int i=n-2;i>=0;i--){
        rightProduct[i]=rightProduct[i+1]*nums[i+1];
    }
    for(int i=0;i<n;i++)
    {
        answer[i]=leftProduct[i]*rightProduct[i];

    }
    return answer;
    }
};

