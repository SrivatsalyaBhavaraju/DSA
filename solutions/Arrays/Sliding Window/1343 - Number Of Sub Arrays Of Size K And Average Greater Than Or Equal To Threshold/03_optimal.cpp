class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int count=0;
        int n=arr.size();
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=arr[i];
        }
        if(sum>=threshold*k){
            count=1;
        }
        for(int j=k;j<n;j++){
            sum=sum-arr[j-k]+arr[j];
            if(sum>=threshold*k){
                count++;
            }
        }
        return count;

    }
};