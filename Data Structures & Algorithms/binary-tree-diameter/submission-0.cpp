class Solution {
private:
    int height(TreeNode* node) {
        if (node == nullptr) return 0;    
        
        int left = height(node->left);
        int right = height(node->right);

        return max(left, right) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;

      
        int op1 = diameterOfBinaryTree(root->left);
        
  
        int op2 = diameterOfBinaryTree(root->right);
        
        
        int op3 = height(root->left) + height(root->right);

        return max(op1, max(op2, op3));
    }
};