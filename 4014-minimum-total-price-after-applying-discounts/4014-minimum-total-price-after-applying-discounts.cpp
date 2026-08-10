class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(), prices.end(), greater<>());
        sort(discounts.begin(), discounts.end(), greater<>());

        double sum=0;
        int mini=min(prices.size(), discounts.size());

        for(int i=0; i<mini;i++){
            double d=(100-discounts[i]);
            double total=d/100;
            sum=sum+ (prices[i]* total);
        
        }

        if(mini!=prices.size()){
            for(int i=mini;i<prices.size();i++){
                sum+=prices[i];
            }
        }

        return sum;
    }
};