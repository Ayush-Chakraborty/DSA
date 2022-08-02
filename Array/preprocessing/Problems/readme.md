# Problem List

🚀 Best Time to Buy and Sell Stocks 👉 [InterviewBit](https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-i/)<details><summary>Approach</summary>
1. For any day $i$ if we know the $minimum$ till index $i$ , then maximum profit can be found if stock is sold at $i^{th}$ day.
2. Answer is $max$ of above all profits.
</details>

🚀 Best Time to Buy and Sell Stocks III 👉 [InterviewBit](https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-iii/)<details><summary>Approach</summary>
1. For each index we want, $maxProfit$ on its left and on its right
2. $prefix[i]$ will denote $maxProfit$ possible upto day $i$
3. $suffix[i]$ will denote $maxProfit$ possible from day $i$
4. $maxProfit = max\{prefix[i-1],suffix[i]\}\  \forall i \in [1,n)$
</details>