# Lowest Common Subsequence

## Problem Link
🔗[Interviewbit Link](https://www.interviewbit.com/problems/longest-common-subsequence/)

---
## Approach
👉 Let $A$ and $B$ be two strings. $n=len(A), m=len(B)$\
👉 If $A[n-1]=B[m-1]$, then $lcs(A,B)=lcs(A[0...n-2],B[0...m-2])$\
👉 If $A[n-1]\neq B[m-1]$, then $A[n-1]$ may be matched to the left of $m-1$ index in string $B$ and similarly for $B[m-1]$ with string $A$.\
👉Hence $lcs(A,B)=max(lcs(A[0...n-1],B[0...n-2]),\ lcs(A[0...n-2],B[0...n-1]))$ 

### Characteristics
- Time Complexity $O(N*M)$

- Space Complexity $O(N*M)$ or $O(max(N,M))$ in optimised case using last two rows of the dp table
