class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice=INT_MAX;
        int maxprofit=0;
        int profit=0;
        for(int i=0;i<prices.size();i++){
            minprice=min(minprice,prices[i]);
            profit=prices[i]-minprice;
            maxprofit=max(maxprofit,profit);
        }
        
    return maxprofit;
    }

};