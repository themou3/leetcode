/**
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 * 121. Best Time to Buy and Sell Stock
 * Difficulty: Easy
 */

#include <stdio.h>
#include <string.h>

int maxProfit(int *prices, int pricesSize);

int main(int argc, char *argv[])
{
    int pricesArr[] = {2, 0, 1, 4};
    int pricesSize = sizeof(pricesArr) / sizeof(pricesArr[0]);
    int result = maxProfit(pricesArr, pricesSize);
    printf("profit = %i\n", result);

    return 0;
}

int maxProfit(int *prices, int pricesSize)
{
    if (pricesSize != 0)
    {
        int buy = prices[0];
        int indexBUY = 0;
        int profit = 0;
        int max = 0;

        for (int i = 1; i < pricesSize; i++)
        {
            if (prices[i] < buy)
            {
                buy = prices[i];
                indexBUY = i;
            }
            else if (prices[i] > buy && i > indexBUY)
            {
                profit = prices[i] - buy;
                if (profit > max)
                {
                    max = profit;
                }
            }
        }
        return (max > 0) ? max : 0;
    }
    else {return 0;}
}
