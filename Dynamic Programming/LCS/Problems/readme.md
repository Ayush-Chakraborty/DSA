# Problem List

🚀 Longest Palindromic Subsequence 👉 [InterviewBit](https://www.interviewbit.com/problems/longest-palindromic-subsequence/)<details><summary>Approach</summary>
$lps(A,B)=lcs(A, reverse(A))$
</details> 


🚀 Edit Distance 👉 [InterviewBit](https://www.interviewbit.com/problems/edit-distance/)<details><summary>Approach</summary>
1. If $A[i] = B[j], distance(A[0...i],B[0...j])=distance(A[0...i-1],B[0...j-1])$
2. Else, minimum of:
   1. Character replace -> $distance(A[0...i-1],B[0...j-1])+1$
   2. Insertion -> $distance(A[0...i-1],B[0...j])+1$
   3. Deletion -> $distance(A[0...i],B[0...j-1])+1$
</details>