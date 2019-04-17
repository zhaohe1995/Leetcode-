#include <iostream>
using namespace std;
#include <vector>
#include <math.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return NULL;  // 空树返回NULL
        if (root->val == key)
            return adjust(root);
        else if(root->val > key){  // 如果根节点值大于key，对左子树进行调整，返回结果变成新的左子树
            root->left = deleteNode(root->left, key);
        }
        else   // 如果根节点值小于key，对右子树进行调整，返回结果变成新的右子树
            root->right = deleteNode(root->right, key);
        return root;
    }
    TreeNode* adjust(TreeNode* root){
        TreeNode* ret = NULL;
        if(root->left != NULL){  // 如果左子树非空
            ret = root->left;
            TreeNode* rightest = getRight(root->left);  // 找到左子树最右节点
            rightest->right = root->right;  // 最右节点右子树接原右子树
        }
        else if(root->right!=NULL){  // 如果右子树非空
            ret = root->right;
            TreeNode* leftest = getLeft(root->right);  // 找到右子树最左节点
            leftest->left = root->left;   // 最左节点左子树接原左子树
        }
        return ret;
    }
    TreeNode* getRight(TreeNode* root){
        //获取最右的孩子节点
        while(root->right!=NULL){
            root = root->right;
        }
        return root;
    }
    TreeNode* getLeft(TreeNode* root){
        //获取最左孩子节点
        while(root->left!=NULL){
            root = root->left;
        }
        return root;
    }
};

int main() {
    TreeNode* node = new TreeNode(0);
    Solution solution = Solution();
    solution.deleteNode(node, 0);
    return 0;
}