# Problem List

🚀 Evaluate Expression To True 👉 [InterviewBit](https://www.interviewbit.com/problems/evaluate-expression-to-true/)<details><summary>Approach</summary>
1. Devide the problem at index $k$, where $s[k]$ is an operator. Hence $k$ should go from $i+1$ to $j-1$ with steps of $2$.
2.  Store a pair of integers in $dp$: $dp[i][j].first$ represents number of ways to get $True$ from the string $s[i...j]$ and $dp[i][j].second$ is number of ways to get $False$.
</details>

🚀 Horse Stable Arrangement 👉 [InterviewBit](https://www.interviewbit.com/problems/arrange-ii/)<details><summary>Approach</summary>
1. For any index $i$ minimum cost will be $min$ of the following values:
   1. for index $j<i$ keep horses from index $j\ to\ i$ in one stable and add the cost of keeping horses from index $0\ to\ i$ in $n-1$ stables.
</details>

🚀 Potions 👉 [InterviewBit](https://www.interviewbit.com/problems/potions/)<details><summary>Approach</summary>
1. Use **Prefix** and **Suffix** sum array to compute cost in each step.
</details>