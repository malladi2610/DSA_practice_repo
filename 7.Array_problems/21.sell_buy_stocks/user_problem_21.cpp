#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int findMaxProfit(vector<int> &prices){
    int min_price = INT_MAX;
    int max_profit = 0;

    for(int price: prices){
        if(price < min_price){
            min_price = price;
        }
        else{
            int profit = price - min_price;
            if(profit > max_profit){
                max_profit = profit;
            }
        }
    }

    return max_profit;
}



int main(){
    vector<int> prices;
    int n, price;

    cout<<"Enter the number of days: ";
    cin>>n;

    cout<<"Enter the prices for each day: ";
    for(int i = 0; i<n; i++){
        cin>>price;
        prices.push_back(price);
    }

    int result = findMaxProfit(prices);
    cout<< "Maximum Profit: " << result<<endl;

    return 0;
}