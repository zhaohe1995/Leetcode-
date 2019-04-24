#include <iostream>
using namespace std;
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>
#include <stack>
#include <unordered_set>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        if (p == NULL && q == NULL)
            return true;
        else
            return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main() {
    return 0;
}
