# Problem List


🚀 Balanced Binary Tree 👉 [InterviewBit](https://www.interviewbit.com/problems/balanced-binary-tree/)<details><summary>Approach</summary>
Recursively check if the absolute value of the difference between left subtree height and right subtree height is greater than $1$ or not.
</details>

🚀 Burn a Tree 👉 [InterviewBit](https://www.interviewbit.com/problems/burn-a-tree/)<details><summary>Approach</summary>
1. Maintain one $max$ variable
2. For each node, find $distance$ to the target node and $height$ of the subtree.
3. If $dist\neq-1$ for left subtree then $mx=max(mx,dist_{left}+height_{right}+1)$, for right subtree vice versa.
</details>

🚀 Diagonal Traversal 👉 [InterviewBit](https://www.interviewbit.com/problems/diagonal-traversal/)<details><summary>Approach</summary>
1. Maintain one map to store the element column wise.
2. Recursively pass $row$ and $column$ value in $DFS$.
3. For a node, $diag=row-col$, store the node in the map corresponding to that diagonal value.
</details>

🚀 Flatten Binary Tree to Linked List 👉 [InterviewBit](https://www.interviewbit.com/problems/flatten-binary-tree-to-linked-list/)<details><summary>Approach</summary>
1. Maintain one $start$ and $end$ pointer for flatten trees.
2. Recursively flatten $left$ and $right$ subtree.
3. Make left pointer of root , $NULL$ and attach the $start$ pointer of $left$ subtree to the $right$ pointer if that $\neq NULL$
4. Attach the $start$ pointer of $right$ subtree to the $end$ pointer of $left$ subtree (if $left \neq NULL$) or to the $right$ pointer of node (If $left=NULL$)
</details>

🚀 Maximum Edge Removal 👉 [InterviewBit](https://www.interviewbit.com/problems/maximum-edge-removal/)<details><summary>Approach</summary>
1. Maintain a global $cnt$ variable
2. Using DFS recursively obtain number of nodes in its subtrees.
3. If number of nodes in a subtree is even then it can be separated i.e. $cnt++$, and doesn't contribute in the node count for the current node.
</details>

🚀 Merge two Binary Tree 👉 [InterviewBit](https://www.interviewbit.com/problems/merge-two-binary-tree/)<details><summary>Approach</summary>
Recursively merge left and right subtrees.
</details>

🚀 Nodes at Distance K 👉 [InterviewBit](https://www.interviewbit.com/problems/nodes-at-distance-k/)<details><summary>Approach</summary>
There are two ways to find nodes at distance $k$.
1. Find all the descendants which are at distance $k$.
2. Find the ancestors of the target such that distance from ancestor is $x$, then find nodes in the other subtree of that ancestor with distance $(d-x-2)$ 
</details>

🚀 Root to Leaf Paths With Sum  👉 [InterviewBit](https://www.interviewbit.com/problems/root-to-leaf-paths-with-sum/)<details><summary>Approach</summary>
1. Send one vector $path$ in function call which will indicate current path.
2. Add current node to current path.
3. Recursively search in left and right subtree.
4. If a node value is equal to target, and it is leaf node, add that path to the ans.
5. Pop back current node from path.
</details>


🚀 Path to Given Node 👉 [InterviewBit](https://www.interviewbit.com/problems/path-to-given-node/)<details><summary>Approach</summary>
If a subtree of current node contains the target node, add that node to the path, else remove that node. Do it recursively.
</details>

