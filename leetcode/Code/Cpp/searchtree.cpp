#include <iostream>
#include <vector>

struct TreeNode
{
    int val;
    TreeNode* left;  // 左子树
    TreeNode* right;  // 右子树
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

};

void insert(int num);

void insert(TreeNode* root, int num)
{
    if (root == nullptr)
    {
        root = new TreeNode(num);  /* 这里的 new 的使用方法 */
        return;
    }

    TreeNode* cur = root, *pre = nullptr;

    // 循环查找，超过叶节点后跳出
    while (cur != nullptr)
    {
        if (cur->val == num)
            return;
        pre = cur;
        if (cur->val < num)
            cur = cur->right;
        else 
            cur = cur->left;
    }

    // 插入节点
    TreeNode* node = new TreeNode(num);
    if (pre->val < num)
        pre->right = node;
    else 
        pre->left = node;
    
}