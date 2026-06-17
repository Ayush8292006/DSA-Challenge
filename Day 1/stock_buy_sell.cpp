#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Recursive helper
void maxProfitFinder(vector<int>& prices, int i, int &minPrice, int &maxProfit) {
    // base case
    if(i == prices.size()) return;

    // update min price
    if(prices[i] < minPrice) {
        minPrice = prices[i];
    }

    // calculate profit
    int todayProfit = prices[i] - minPrice;

    // update max profit
    if(todayProfit > maxProfit) {
        maxProfit = todayProfit;
    }

    // recursive call
    maxProfitFinder(prices, i + 1, minPrice, maxProfit);
}

// main function
int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX;
    int maxProfit = INT_MIN;

    maxProfitFinder(prices, 0, minPrice, maxProfit);

    return maxProfit;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    int result = maxProfit(prices);

    cout << "Maximum Profit: " << result << endl;

    return 0;
}