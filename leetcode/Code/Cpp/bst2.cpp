// 二叉搜索树中第 K 小的元素,https://leetcode.cn/problems/kth-smallest-element-in-a-bst/description/?envType=study-plan-v2&envId=top-100-liked

// 使用中序遍历
// 由于二叉搜索的特殊性，中序遍历使得二叉树返回的是按照从小到大的顺序
// 我们使用栈，出栈的第 k 个元素即为我们所求的

#include <stack>
using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int kthSmallest(TreeNode* root, int k) {
    TreeNode* cur = root;
    stack<TreeNode*> stk;
    
    // 中序遍历
    while (!stk.empty() || cur != nullptr) {
        // 一直向左走，直到到达最左子节点
        while (cur != nullptr) {
            stk.push(cur);
            cur = cur->left;
        }
        
        cur = stk.top();
        stk.pop();
        
        // 处理当前节点，k 减 1
        k--;
        if (k == 0) {
            return cur->val;  // 当 k 减到 0，返回当前节点的值
        }
        
        // 继续遍历右子树
        cur = cur->right;
    }
    
    return -1; 
}
