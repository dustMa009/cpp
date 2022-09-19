// Leetcode: Inorder successor in BST
// https://leetcode.com/problems/inorder-successor-in-bst/

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* a = NULL;
        
        if (p->right) {
            a = p->right;
            while (a->left) {
                a = a->left;
            }
            return a;
        } else {
            TreeNode* node = root;
            while (node) {
                if (node->val == p->val) {
                    break;
                } else if (node->val > p->val) {
                    if (!a) {
                        a = node;
                    } else if (a->val > node->val) {
                        a = node;
                    }
                    node = node->left;
                } else {
                    node = node->right;
                }
            }
            return a;
        }
    }
};