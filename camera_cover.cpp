#include <iostream>
using namespace std;

#define NOT_COVERED 0
#define COVERED_HAS_CAMERA 1
#define COVERED_NO_CAMERA 2

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int ans;

int dfs(TreeNode *root)
{
    if (root == NULL)
        return COVERED_NO_CAMERA;

    int left = dfs(root->left), right = dfs(root->right);

    if (left == NOT_COVERED || right == NOT_COVERED)
    {
        ans++;
        return COVERED_HAS_CAMERA;
    }
    else if (left == COVERED_HAS_CAMERA || right == COVERED_HAS_CAMERA)
        return COVERED_NO_CAMERA;
    else
        return NOT_COVERED;
}

int minCamera(TreeNode *root)
{
    if (dfs(root) == NOT_COVERED)
        ans++;

    return ans;
}