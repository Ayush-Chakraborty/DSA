# Lowest Common Ancestor

## Problem Link
🔗 [Interviewbit Link](https://www.interviewbit.com/problems/least-common-ancestor/)

### Approach 1
There are $3$ possible cases:
1. If $node1=node2$: find if the node exists or not, if exists then LCA is that node.
2. If one node is descendent of another node
3. Two nodes are in different subtrees.

So pass two $int$ in recursion, denoting $dist1$ and $dist2$, distances from 2 nodes.
1. If node doesn't exist $dist=-1$
2. If both $dist1$ and $dist2$ are $\neq-1$, then LCA exists in its descendents.
3. If $curr$ node value is equal to both nodes the $case: 1$, and that is the $LCA$
4. If $curr$ node value is equal to one node and one of $dist1$ and $dist2$ are $\neq-1$, then $case: 2$, and that is the $LCA$.
5. If $dist1 \neq -1$ in one of the subtree and $dist2\neq-1$  in another subtree, then that is the $LCA$

### Characteristics
- Time Complexity $O(N)$

- Space Complexity $O(h)$ where $h=height$ of the tree.
