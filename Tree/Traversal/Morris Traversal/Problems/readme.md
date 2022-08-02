# Problem List

🚀 Recover Binary Search Tree 👉 [InterviewBit](https://www.interviewbit.com/problems/recover-binary-search-tree/)<details><summary>Approach</summary>
1. Use Morris algorithm to obtain inorder sequence
2. In inorder sequence , if any element is greater than its next element then, it is the first swapped element.
3. The last element which has a greater element to its left is the second swappped element. 
</details>