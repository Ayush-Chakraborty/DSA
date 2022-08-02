# Morris Algorithm

## Links
🔗[Tutorial Link](https://youtu.be/80Zug6D1_r4)

🔗[Leetcode Link](https://leetcode.com/problems/binary-tree-inorder-traversal/)

---
## Approach
👉 If $left$ node is $NULL$, then $curr$ pointer will print the current node value and will move to the $right$ subtree.

👉 If $left$ subtree is not $NULL$, then we need to come back to $curr$ node once we reach to the rightmost node of the left subtree. Thats why we travel to the rightmost node of the subtree and will assign one back-edge to the $curr$ node.

👉 So if we get any $left$ subtree we'll travel to the rightmost node, if its $NULL$, we'll create one back-edge to the current node, else if it is same as $curr$ node, we'll delete that edge and will move to the $right$ node of the $curr$ node.



### Characteristics
- Time Complexity $O(N)$

- Space Complexity $O(1)$
