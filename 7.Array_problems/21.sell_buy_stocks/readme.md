**1. Approach**  
To solve this problem, we only need to track the minimum stock price we have encountered so far and the profit if we sell at the current price. Each day, we check if the current price gives us a better profit than what we have seen before. While iterating through the price list:  
- Keep updating a variable that stores the minimum price found so far.  
- Calculate the profit if we sell at the current day (current_price - min_price).  
- Keep track of the maximum profit seen up to that point.  

**1.1 Technique**  
We use a single-pass approach that keeps track of the minimum price so far and calculates the potential profit at each step.

---

**2. Algorithm**  
1. Initialize `min_price` as a large number (e.g., `INT_MAX` in C++).  
2. Initialize `max_profit` as 0.  
3. Loop through each price in the prices array:  
   - If the current price is less than `min_price`, update `min_price` with the current price.  
   - Else, calculate the potential profit as `current_price - min_price`.  
   - If this potential profit is greater than `max_profit`, update `max_profit`.  
4. After the loop ends, `max_profit` will hold the maximum profit possible.  

---

**3. Pseudo-code**  
```
function findMaxProfit(prices):
    min_price = +∞
    max_profit = 0

    for price in prices:
        if price < min_price:
            min_price = price
        else:
            profit = price - min_price
            if profit > max_profit:
                max_profit = profit

    return max_profit
```

---

**4. Time Complexity & Space Complexity**  
- **Time Complexity**: O(n), where n is the number of days. We are scanning through the list only once.  
- **Space Complexity**: O(1). We only use a few variables (`min_price` and `max_profit`).  

---

**5. Detailed C++ Code**

```cpp
/* Library Functions */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Problem specific function */
int findMaxProfit(vector<int> &prices) {
    int min_price = INT_MAX;
    int max_profit = 0;

    for(int price : prices) {
        if(price < min_price) {
            min_price = price;
        } else {
            int profit = price - min_price;
            if(profit > max_profit) {
                max_profit = profit;
            }
        }
    }

    return max_profit;
}

/* Main function */
int main() {
    vector<int> prices;
    int n, price;

    cout << "Enter the number of days: ";
    cin >> n;

    cout << "Enter the prices for each day: ";
    for(int i = 0; i < n; i++) {
        cin >> price;
        prices.push_back(price);
    }

    int result = findMaxProfit(prices);
    cout << "Maximum Profit: " << result << endl;

    return 0;
}
```

Use this final code structure to guide your coding.