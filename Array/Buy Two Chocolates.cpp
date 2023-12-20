class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int miniIndex = -1;
        int n = prices.size();
        int firstPrice = INT_MAX;
        //First we find the minimum element in the array 
        for(int i= 0 ;i<n;i++){
            if(prices[i] < firstPrice){
                firstPrice = prices[i];
                miniIndex = i;
            }
        }
        //here we check minimum element is greter than money or not if not return money 
        if(money <= firstPrice)   return money;
        bool flag = false;
        //here we find the reminder money
        int secondPrice = money - firstPrice;
        for(int i = 0;i<n;i++){
            //skip firstPricelate index
            if(i==miniIndex)    continue;
            //take any choclate which is less than or equal to our reminder money
            if(prices[i] <= secondPrice){
                secondPrice = min(secondPrice,prices[i]);
                flag = true;
            }
        }
        if(!flag)   return money;
        
        money = money - (firstPrice + secondPrice);
        return money;
    }
};
