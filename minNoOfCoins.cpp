#include <bits/stdc++.h> 
int findMinimumCoins(int amount) {
    int ans = 0;
    vector<int> coins = {1000, 500, 100, 50, 20, 10, 5, 2, 1};
    while(amount) {
        for(auto coin : coins) {
            while(amount >= coin) {
                ans+=amount/coin;
                amount-= (amount/coin)*coin;
            }
        }
    }
    return ans;
}