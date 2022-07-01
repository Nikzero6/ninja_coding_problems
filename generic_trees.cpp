#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;

    TreeNode(T data)
    {
        this->data = data;
    }
};

TreeNode<int> *takeInputLevelWise()
{
    cout << "Enter data: ";
    int rootData;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingRoots;
    pendingRoots.push(root);

    while (!pendingRoots.empty())
    {
        TreeNode<int> *front = pendingRoots.front();
        pendingRoots.pop();

        cout << "Enter num of children of " << front->data << " : ";
        int numChild;
        cin >> numChild;

        for (int i = 0; i < numChild; i++)
        {
            cout << "Enter " << i << "th child of " << front->data << " : ";
            int data;
            cin >> data;

            TreeNode<int> *child = new TreeNode<int>(data);
            front->children.push_back(child);
            pendingRoots.push(child);
        }
    }

    return root;
}

void print(TreeNode<int> *root)
{
    if (root == NULL)
        return;

    cout << root->data << " : ";

    for (auto child : root->children)
    {
        cout << child->data << ",";
    }
    cout << endl;

    for (auto child : root->children)
    {
        print(child);
    }
}

void printLevelWise(TreeNode<int> *root)
{
    if (root == NULL)
        return;

    queue<TreeNode<int> *> pendingRoots;
    pendingRoots.push(root);

    while (!pendingRoots.empty())
    {
        TreeNode<int> *front = pendingRoots.front();
        pendingRoots.pop();
        cout << front->data << " : ";
        for (auto child : front->children)
        {
            cout << child->data << ",";
            pendingRoots.push(child);
        }
        cout << endl;
    }
}

int sumOfNodes(TreeNode<int> *root)
{
    if (root == NULL)
        return 0;

    int ans = root->data;

    for (auto child : root->children)
    {
        ans += sumOfNodes(child);
    }

    return ans;
}

TreeNode<int> *maxNode(TreeNode<int> *root)
{
    TreeNode<int> *maxTreeNode = root;

    for (auto child : root->children)
    {
        TreeNode<int> *subTreeMaxNode = maxNode(child);
        if (subTreeMaxNode->data > maxTreeNode->data)
            maxTreeNode = subTreeMaxNode;
    }

    return maxTreeNode;
}

int treeHeight(TreeNode<int> *root)
{
    if (root == NULL)
        return 0;

    int maxHeight = 0;

    for (auto child : root->children)
    {
        int subTreeHeight = treeHeight(child);
        if (subTreeHeight > maxHeight)
            maxHeight = subTreeHeight;
    }

    return maxHeight + 1;
}

void printAtLevelK(TreeNode<int> *root, int k)
{
    if (root == NULL)
        return;

    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }

    for (auto child : root->children)
    {
        printAtLevelK(child, k - 1);
    }
}

void printLeafNodes(TreeNode<int> *root)
{
    if (root == NULL)
        return;

    bool flag = true;

    for (auto child : root->children)
    {
        flag = false;
        printLeafNodes(child);
    }

    if (flag)
        cout << root->data << " ";
}

int countLeafNodes(TreeNode<int> *root)
{
    if (root == NULL)
        return 0;

    int count = 0;
    bool flag = true;

    for (auto child : root->children)
    {
        flag = false;
        count += countLeafNodes(child);
    }

    if (flag)
        count++;

    return count;
}

void postOrder(TreeNode<int> *root)
{
    if (root == NULL)
        return;

    for (auto child : root->children)
    {
        postOrder(child);
    }

    cout << root->data << " ";
}

bool search_x(TreeNode<int> *root, int x)
{
    if (root == NULL)
        return false;

    if (root->data == x)
        return true;

    bool ans = false;

    for (auto child : root->children)
    {

        ans = ans || search_x(child, x);
    }

    return ans;
}

int greaterNodes(TreeNode<int> *root, int x)
{
    if (root == NULL)
        return 0;

    int count = 0;
    if (root->data > x)
        count++;

    for (auto child : root->children)
    {
        count += greaterNodes(child, x);
    }

    return count;
}

pair<TreeNode<int> *, int> maxSumNode(TreeNode<int> *root)
{
    if (root == NULL)
        return make_pair(root, 0);

    pair<TreeNode<int> *, int> maxSum;

    maxSum.first = root;

    int sum = root->data;
    for (auto child : root->children)
        sum += child->data;

    maxSum.second = sum;

    for (auto child : root->children)
    {
        pair<TreeNode<int> *, int> subMaxSum = maxSumNode(child);
        if (subMaxSum.second > maxSum.second)
            maxSum = subMaxSum;
    }

    return maxSum;
}

bool identical(TreeNode<int> *root1, TreeNode<int> *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;

    if (root1 == NULL || root2 == NULL)
        return false;

    if (root1->data != root2->data)
        return false;

    if (root1->children.size() != root2->children.size())
        return false;

    bool ans = true;

    for (int i = 0; i < root1->children.size(); i++)
    {
        ans = ans && identical(root1->children[i], root2->children[i]);
    }

    return ans;
}

TreeNode<int> *next_larger(TreeNode<int> *root, int x)
{
    if (root == NULL)
        return NULL;

    TreeNode<int> *ans = new TreeNode<int>(INT_MAX);

    if (root->data > x)
    {
        ans = root;
    }

    for (auto child : root->children)
    {
        TreeNode<int> *subAns = next_larger(child, x);

        if (subAns->data < ans->data)
            ans = subAns;
    }

    return ans;
}

pair<TreeNode<int> *, TreeNode<int> *> second_largest(TreeNode<int> *root)
{
    if (root == NULL)
        return make_pair(root, root);

    pair<TreeNode<int> *, TreeNode<int> *> ans(root, NULL);

    for (auto child : root->children)
    {
        pair<TreeNode<int> *, TreeNode<int> *> subAns = second_largest(child);

        if (subAns.first->data > ans.first->data)
        {
            if (subAns.second != NULL && ans.first->data < subAns.second->data)
                ans.second = subAns.second;
            else
                ans.second = ans.first;

            ans.first = subAns.first;
        }
        else
        {
            if (ans.second == NULL || subAns.first->data > ans.second->data)
                ans.second = subAns.first;
        }
    }

    return ans;
}

void replace_with_depth(TreeNode<int> *root, int depth)
{
    if (root == NULL)
        return;

    root->data = depth;

    for (auto child : root->children)
    {
        replace_with_depth(child, depth + 1);
    }
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    // printLevelWise(root);
    // cout << sumOfNodes(root) << endl;
    // cout << maxNode(root)->data << endl;
    // cout << treeHeight(root) << endl;
    // printLeafNodes(root);
    // cout << countLeafNodes(root) << endl;
    // postOrder(root);

    // cout << "Search : ";
    // int x;
    // cin >> x;
    // cout << search_x(root, x) << endl;

    // cout << "elem : ";
    // int x;
    // cin >> x;
    // cout << greaterNodes(root, x) << endl;

    // pair<TreeNode<int> *, int> ans = maxSumNode(root);
    // cout << ans.first->data << " " << ans.second << endl;

    // TreeNode<int> *root2 = takeInputLevelWise();
    // cout << identical(root, root2) << endl;

    // cout << next_larger(root, 20)->data << endl;

    // cout << second_largest(root).second->data << endl;

    printLevelWise(root);
    replace_with_depth(root, 0);
    printLevelWise(root);

    return 0;
}