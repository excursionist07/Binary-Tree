 /*
 Complexity:
Time O(N), as we iterate both pre index and post index only once.
Space O(height), depending on the height of constructed tree.


Recursive Solution
Create a node TreeNode(pre[preIndex]) as the root.

Becasue root node will be lastly iterated in post order,
if root.val == post[posIndex],
it means we have constructed the whole tree,

If we haven't completed constructed the whole tree,
So we recursively constructFromPrePost for left sub tree and right sub tree.

And finally, we'll reach the posIndex that root.val == post[posIndex].
We increment posIndex and return our root node.
*/

class Solution {
public:
    int preIndex=0,postIndex=0;
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post)
    {
        TreeNode* root = new TreeNode(pre[preIndex++]);
        if (root->val != post[postIndex])
            root->left = constructFromPrePost(pre, post);
        if (root->val != post[postIndex])
            root->right = constructFromPrePost(pre, post);
        postIndex++;
        return root;

    }
};
