#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "root : ";
    cin >> rootData;

    if (rootData == -1)
        return NULL;

    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (!pendingNodes.empty())
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        cout << "left child of " << front->data << " : ";
        int leftData;
        cin >> leftData;

        if (leftData != -1)
        {
            TreeNode<int> *leftChild = new TreeNode<int>(leftData);
            front->left = leftChild;
            pendingNodes.push(leftChild);
        }

        cout << "right child of " << front->data << " : ";
        int rightData;
        cin >> rightData;

        if (rightData != -1)
        {
            TreeNode<int> *rightChild = new TreeNode<int>(rightData);
            front->right = rightChild;
            pendingNodes.push(rightChild);
        }
    }

    return root;
}

void printLevelWise(TreeNode<int> *root)
{
    if (root == NULL)
        return;
    cout << endl;
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (!pendingNodes.empty())
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << " : ";

        if (front->left != NULL)
        {
            cout << "L" << front->left->data << ", ";
            pendingNodes.push(front->left);
        }

        if (front->right != NULL)
        {
            cout << "R" << front->right->data;
            pendingNodes.push(front->right);
        }
        cout << endl;
    }
}

int dfs(TreeNode<int> *root, int p, int q, int i, int &level1, int &level2, TreeNode<int> *&p1, TreeNode<int> *&p2)
{
    if (root == NULL)
        return -1;

    int leftAns = dfs(root->left, p, q, i + 1, level1, level2, p1, p2);
    int rightAns = dfs(root->right, p, q, i + 1, level1, level2, p1, p2);

    if (leftAns == p)
    {
        p1 = root;
        level1 = i + 1;
    }
    else if (leftAns == q)
    {
        p2 = root;
        level2 = i + 1;
    }

    if (rightAns == p)
    {
        p1 = root;
        level1 = i + 1;
    }
    else if (rightAns == q)
    {
        p2 = root;
        level2 = i + 1;
    }

    return root->data;
}

bool cousins(TreeNode<int> *root, int p, int q)
{
    int i = 0, j = 0;
    TreeNode<int> *p1 = NULL, *p2 = NULL;
    dfs(root, p, q, 0, i, j, p1, p2);

    if (p1 != p2 && i == j)
        return true;

    return false;
}

void longest_path(TreeNode<int> *root, vector<int> &ds, vector<int> ans)
{
    if (root == NULL)
        return;

    ans.push_back(root->data);
    if (root->left == NULL && root->right == NULL)
    {
        if (ds.size() < ans.size())
            ds = ans;
    }
    longest_path(root->left, ds, ans);
    longest_path(root->right, ds, ans);
}

template <typename T>
class GenericTreeNode
{
public:
    T data;
    vector<GenericTreeNode<T> *> children;

    GenericTreeNode(T data)
    {
        this->data = data;
    }
};

GenericTreeNode<int> *takeGenericInputLevelWise()
{
    cout << "Enter data: ";
    int rootData;
    cin >> rootData;
    GenericTreeNode<int> *root = new GenericTreeNode<int>(rootData);

    queue<GenericTreeNode<int> *> pendingRoots;
    pendingRoots.push(root);

    while (!pendingRoots.empty())
    {
        GenericTreeNode<int> *front = pendingRoots.front();
        pendingRoots.pop();

        cout << "Enter num of children of " << front->data << " : ";
        int numChild;
        cin >> numChild;

        for (int i = 0; i < numChild; i++)
        {
            cout << "Enter " << i << "th child of " << front->data << " : ";
            int data;
            cin >> data;

            GenericTreeNode<int> *child = new GenericTreeNode<int>(data);
            front->children.push_back(child);
            pendingRoots.push(child);
        }
    }

    return root;
}

void printGenericLevelWise(GenericTreeNode<int> *root)
{
    if (root == NULL)
        return;

    queue<GenericTreeNode<int> *> pendingRoots;
    pendingRoots.push(root);

    while (!pendingRoots.empty())
    {
        GenericTreeNode<int> *front = pendingRoots.front();
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

GenericTreeNode<int> *removeLeafNodes(GenericTreeNode<int> *root)
{
    if (root->children.size() == 0)
        return NULL;

    for (int i = 0; i < root->children.size();)
    {
        if (removeLeafNodes(root->children[i]) == NULL)
        {
            root->children.erase(root->children.begin() + i);
        }
        else
            i++;
    }

    return root;
}

int main()
{
    // TreeNode<int> *root = takeInputLevelWise();
    // printLevelWise(root);

    // int p, q;
    // cin >> p >> q;
    // cout << cousins(root, p, q);

    // vector<int> ds, ans;
    // longest_path(root, ds, ans);
    // for (auto it : ds)
    // {
    //     cout << it << " ";
    // }
    // cout << endl;

    GenericTreeNode<int> *root = takeGenericInputLevelWise();
    cout << endl
         << endl;

    printGenericLevelWise(root);

    root = removeLeafNodes(root);
    cout << endl
         << endl;
    printGenericLevelWise(root);

    return 0;
}