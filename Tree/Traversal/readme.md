# Tree Traversals

## Inorder Traversal
🔗 [Interviewbit Link](https://www.interviewbit.com/problems/inorder-traversal/)

### Approach
1. For each non-null node, push its left node to the stack.
2. If a null node is obtained, we pop from stack and move to the right node of popped node.
3. While popping one node,it indicates its left subtree is processed,hence we print that node.

## Preorder Traversal
🔗 [Interviewbit Link](https://www.interviewbit.com/problems/preorder-traversal/)

### Approach
Same as inorder, but we print the node while pushing into the stack.

## Postorder Traversal
🔗 [Interviewbit Link](https://www.interviewbit.com/problems/postorder-traversal/)

### Approach
1. Maintain one $prev$ pointer which will store the last popped node from stack.
2. If we encounter any non-null node, we push to the stack and move to the left subtree.
3. If null node is encountered, means last pushed node's left subtree is processed, and we move on to right subtree if the $prev \neq right child$
4. If right child is NULL or right subtree is already preocessed then print the node.

-- --

### Characteristics
- Time Complexity $O(N)$

- Space Complexity $O(h)$ where $h=height$ of the tree.
