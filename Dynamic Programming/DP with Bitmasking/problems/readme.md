# Problem List

🚀 Shortest Common Superstring 👉 [InterviewBit](https://www.interviewbit.com/problems/shortest-common-superstring/)<details><summary>Approach</summary>
1. **Sub-problem:** If we have a set of $n$ strings and we have the length of the shortest common superstring consisting of $n-1$ substrings, then the final value can be found by placing the last element after each elements from the $n-1$ strings and taking minimum from them.
2. **DP state:** $dp[i][mask]$ represents the length of SCS taking the elements represented by $mask$ with the ending element being the $i^{th}$ string
3. For each set bit $j$ in $mask$: $dp[i][mask]=min\{dp[j][mask\oplus(1<<i)]+ len(string_{i}) - overlapping\_length(string_{i},string_{j})\}$
</details>