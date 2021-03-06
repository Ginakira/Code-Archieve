// 路径总和
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
   public:
    bool myPath(TreeNode *root, int sum) {
        if (!root->left && !root->right) {
            if (sum == 0)
                return true;
            else
                return false;
        }
        if (!root->left) {
            return myPath(root->right, sum - root->right->val);
        } else if (!root->right) {
            return myPath(root->left, sum - root->left->val);
        } else {
            return myPath(root->left, sum - root->left->val) ||
                   myPath(root->right, sum - root->right->val);
        }
    }

    bool hasPathSum(TreeNode *root, int sum) {
        if (!root) return false;
        if (!root->left && !root->right) return root->val == sum;
        return myPath(root, sum - root->val);
    }
};

//递归 时间复杂度O(n)
class Solution2 {
   public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (!root) return false;
        if (!root->left && !root->right) return root->val == sum;
        return hasPathSum(root->left, sum - root->val) ||
               hasPathSum(root->right, sum - root->val);
    }
};