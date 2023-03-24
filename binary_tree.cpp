#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <climits>
#include <algorithm>
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

int nodesCount(TreeNode<int> *root)
{
    if (root == NULL)
        return 0;

    int count = 1;

    count += nodesCount(root->left);
    count += nodesCount(root->right);

    return count;
}

bool nodePresent(TreeNode<int> *root, int x)
{
    if (root == NULL)
        return false;

    if (root->data == x)
        return true;

    return nodePresent(root->left, x) || nodePresent(root->right, x);
}

int treeHeight(TreeNode<int> *root)
{
    if (root == NULL)
        return 0;

    int count = 1;

    int leftCount = treeHeight(root->left);
    int rightCount = treeHeight(root->right);

    count += max(leftCount, rightCount);

    return count;
}

void mirrorTree(TreeNode<int> *root)
{
    if (root == NULL)
        return;

    mirrorTree(root->left);
    mirrorTree(root->right);

    TreeNode<int> *temp = root->left;
    root->left = root->right;
    root->right = temp;
}

void preOrder(TreeNode<int> *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(TreeNode<int> *root)
{
    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void inOrder(TreeNode<int> *root)
{
    if (root == NULL)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

TreeNode<int> *constructTreePreorder(int inorder[], int preorder[], int inStart, int inEnd, int preStart, int preEnd)
{
    TreeNode<int> *root = new TreeNode<int>(preorder[preStart]);

    if (inStart == inEnd || preStart == preEnd)
        return root;

    int leftInStart = inStart, rightInEnd = inEnd, leftPreStart = preStart + 1, rightPreEnd = preEnd;
    int leftInEnd, rightInStart;

    for (int i = inStart; i <= inEnd; i++)
    {
        if (inorder[i] == root->data)
        {
            leftInEnd = i - 1;
            rightInStart = i + 1;
        }
    }

    int leftPreEnd = (leftInEnd - leftInStart) + leftPreStart;
    int rightPreStart = leftPreEnd + 1;

    if (leftInStart <= leftInEnd && leftPreStart <= leftPreEnd)
        root->left = constructTreePreorder(inorder, preorder, leftInStart, leftInEnd, leftPreStart, leftPreEnd);

    if (rightInStart <= rightInEnd && rightPreStart <= rightPreEnd)
        root->right = constructTreePreorder(inorder, preorder, rightInStart, rightInEnd, rightPreStart, rightPreEnd);

    return root;
}

TreeNode<int> *constructTreePostOrder(int postorder[], int inorder[], int pS, int pE, int iS, int iE)
{
    if (iS > iE || pS > pE)
        return NULL;

    TreeNode<int> *root = new TreeNode<int>(postorder[pE]);

    int rootIndex = -1;
    for (int i = iS; i <= iE; i++)
    {
        if (root->data == inorder[i])
        {
            rootIndex = i;
            break;
        }
    }

    int lIs = iS;
    int lIe = rootIndex - 1;
    int lPs = pS;
    int lPe = lIe - lIs + lPs;
    int rIs = rootIndex + 1;
    int rIe = iE;
    int rPs = lPe + 1;
    int rPe = pE - 1;

    root->left = constructTreePostOrder(postorder, inorder, lPs, lPe, lIs, lIe);
    root->right = constructTreePostOrder(postorder, inorder, rPs, rPe, rIs, rIe);

    return root;
}

pair<int, int> diameter(TreeNode<int> *root)
{
    if (root == NULL)
        return make_pair(0, 0);

    pair<int, int> ans(0, 1);

    pair<int, int> leftAns = diameter(root->left);
    pair<int, int> rightAns = diameter(root->right);

    ans.second += max(leftAns.second, rightAns.second);
    ans.first = max(leftAns.second + rightAns.second, max(leftAns.first, rightAns.first));

    return ans;
}

pair<int, int> minMax(TreeNode<int> *root)
{
    if (root == NULL)
        return make_pair(INT_MIN, INT_MAX);

    pair<int, int> ans(root->data, root->data);

    pair<int, int> leftAns = minMax(root->left);
    pair<int, int> rightAns = minMax(root->right);

    ans.first = max(ans.first, max(leftAns.first, rightAns.first));
    ans.second = min(ans.second, min(leftAns.second, rightAns.second));

    return ans;
}

int sum(TreeNode<int> *root)
{
    if (root == NULL)
        return 0;

    int ans = root->data;
    ans += sum(root->left);
    ans += sum(root->right);

    return ans;
}

pair<bool, int> balanced(TreeNode<int> *root)
{
    if (root == NULL)
        return make_pair(true, 0);

    pair<bool, int> leftAns = balanced(root->left);
    pair<bool, int> rightAns = balanced(root->right);

    if (leftAns.first && rightAns.first && abs(leftAns.second - rightAns.second) <= 1)
        return make_pair(true, 1 + max(leftAns.second, rightAns.second));
    else
        return make_pair(false, 1 + max(leftAns.second, rightAns.second));
}

void levelOrder(TreeNode<int> *root)
{
    if (root == NULL)
        return;

    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);

    while (!pendingNodes.empty())
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        if (front == NULL)
        {
            cout << endl;
            if (!pendingNodes.empty())
                pendingNodes.push(NULL);
        }
        else
        {
            cout << front->data << " ";

            if (front->left != NULL)
                pendingNodes.push(front->left);

            if (front->right != NULL)
                pendingNodes.push(front->right);
        }
    }
}

bool removeLeafNodes(TreeNode<int> *root)
{
    if (root == NULL)
        return false;

    if (root->left == NULL && root->right == NULL)
    {
        delete root;
        return true;
    }

    if (removeLeafNodes(root->left))
        root->left = NULL;
    if (removeLeafNodes(root->right))
        root->right = NULL;

    return false;
}

void makeLevelList(TreeNode<int> *root, vector<vector<int>> &list, int i)
{
    if (root == NULL)
        return;

    if (list.size() <= i)
        list.push_back({root->data});
    else
        list[i].push_back(root->data);

    makeLevelList(root->left, list, i + 1);
    makeLevelList(root->right, list, i + 1);
}

void printZigZag(TreeNode<int> *root)
{
    if (root == NULL)
        return;

    stack<TreeNode<int> *> s1, s2;

    s1.push(root);

    while (!s1.empty() || !s2.empty())
    {
        while (!s1.empty())
        {
            TreeNode<int> *top = s1.top();
            cout << top->data << " ";

            if (top->left != NULL)
                s2.push(top->left);

            if (top->right != NULL)
                s2.push(top->right);

            s1.pop();
        }

        cout << endl;

        while (!s2.empty())
        {
            TreeNode<int> *top = s2.top();
            cout << top->data << " ";

            if (top->right != NULL)
                s1.push(top->right);

            if (top->left != NULL)
                s1.push(top->left);

            s2.pop();
        }
        cout << endl;
    }
}

void NodesWithoutSibling(TreeNode<int> *root)
{
    if (root == NULL)
        return;

    if (root->left != NULL && root->right == NULL)
        cout << root->data << " ";

    if (root->right != NULL && root->left == NULL)
        cout << root->data << " ";

    NodesWithoutSibling(root->left);
    NodesWithoutSibling(root->right);
}

void duplicateLeft(TreeNode<int> *root)
{
    if (root == NULL)
        return;

    duplicateLeft(root->left);
    TreeNode<int> *temp = root->left;
    root->left = new TreeNode<int>(root->data);
    root->left->left = temp;
    duplicateLeft(root->right);
}

void preOrderHash(TreeNode<int> *root, unordered_map<int, int> &hash)
{
    if (root == NULL)
        return;

    hash[root->data] = 1;
    preOrderHash(root->left, hash);
    preOrderHash(root->right, hash);
}

void pairSum(TreeNode<int> *root, int sum, vector<pair<int, int>> &ans)
{
    unordered_map<int, int> hash;
    preOrderHash(root, hash);

    unordered_map<int, int>::iterator it;
    it = hash.begin();
    while (it != hash.end())
    {
        int req = sum - it->first;
        if (it->second && hash.find(req) != hash.end())
        {
            ans.push_back({it->first, req});
            hash[it->first] = 0;
            hash[req] = 0;
        }
        it++;
    }
}

stack<int> dfs_fill_path(TreeNode<int> *root, int k, stack<int> s)
{
    stack<int> ans;

    if (root == NULL)
        return ans;

    s.push(root->data);

    if (root->data == k)
    {
        return s;
    }
    ans = dfs_fill_path(root->left, k, s);
    if (ans.empty())
        ans = dfs_fill_path(root->right, k, s);

    return ans;
}

int LCA(TreeNode<int> *root, int x, int y)
{
    stack<int> s1, s2;

    s1 = dfs_fill_path(root, x, s1);
    s2 = dfs_fill_path(root, y, s2);

    if (s1.empty() || s2.empty())
        return -1;

    while (s1.size() != s2.size())
    {
        if (s1.size() > s2.size())
            s1.pop();
        else
            s2.pop();
    }

    while (s1.top() != s2.top())
    {
        s1.pop();
        s2.pop();
    }

    return s1.top();
}

int LCA_best(TreeNode<int> *root, int x, int y)
{
    if (root == NULL)
        return -1;

    if (root->data == x || root->data == y)
        return root->data;

    int leftAns = LCA_best(root->left, x, y);
    int rightAns = LCA_best(root->right, x, y);

    if (leftAns == -1 && rightAns == -1)
        return -1;
    else if (leftAns == -1)
        return rightAns;
    else if (rightAns == -1)
        return leftAns;
    else
        return root->data;
}

class maxBstAns
{
public:
    int height; // not required
    int max;
    int min;
    bool isBst;
    int maxBst;
};

maxBstAns maxBst(TreeNode<int> *root)
{
    maxBstAns ans;

    if (root == NULL)
    {
        ans.height = 0;
        ans.max = INT_MIN;
        ans.min = INT_MAX;
        ans.isBst = true;
        ans.maxBst = 0;

        return ans;
    }

    maxBstAns leftAns = maxBst(root->left);
    maxBstAns rightAns = maxBst(root->right);

    ans.height = 1 + max(leftAns.height, rightAns.height); // not required
    ans.max = max(root->data, max(leftAns.max, rightAns.max));
    ans.min = min(root->data, min(leftAns.min, rightAns.min));

    if (leftAns.isBst && rightAns.isBst && root->data > leftAns.max && root->data <= rightAns.min)
    {
        ans.isBst = true;
        ans.maxBst = max(ans.height, max(leftAns.maxBst, rightAns.maxBst));
        // ans.maxBst = 1 + max(leftAns.maxBst, rightAns.maxBst));
    }
    else
    {
        ans.isBst = false;
        ans.maxBst = max(leftAns.maxBst, rightAns.maxBst);
    }

    return ans;
}

void pathSumK(TreeNode<int> *root, int k, int sum, vector<vector<int>> &ds, vector<int> ans)
{
    if (root == NULL)
        return;

    sum += root->data;
    ans.push_back(root->data);
    if (root->left == NULL && root->right == NULL && sum == k)
        ds.push_back(ans);

    pathSumK(root->left, k, sum, ds, ans);
    pathSumK(root->right, k, sum, ds, ans);
}

void printLevelK(TreeNode<int> *root, int k)
{
    if (root == NULL)
        return;

    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }

    printLevelK(root->left, k - 1);
    printLevelK(root->right, k - 1);
}

pair<bool, int> printNodesK(TreeNode<int> *root, int target, int k)
{
    if (root == NULL)
        return {false, k};

    if (root->data == target)
    {
        printLevelK(root->left, k - 1);
        printLevelK(root->right, k - 1);
        return {true, k - 1};
    }
    pair<bool, int> leftAns = printNodesK(root->left, target, k);
    pair<bool, int> rightAns = printNodesK(root->right, target, k);

    if (leftAns.first)
    {
        int level = leftAns.second;
        if (level == 0)
        {
            cout << root->data << " ";
            return {false, level - 1};
        }
        printLevelK(root->right, level - 1);
        return {level > 0, level - 1};
    }

    if (rightAns.first)
    {
        int level = rightAns.second;
        if (level == 0)
        {
            cout << root->data << " ";
            return {false, level - 1};
        }
        printLevelK(root->left, level - 1);
        return {level > 0, level - 1};
    }

    return {false, k};
}

class QNode
{
public:
    TreeNode<int> *node;
    int row, col;

    QNode()
    {
        node = NULL;
        row = 0, col = 0;
    }
    QNode(TreeNode<int> *node, int row, int col)
    {
        this->node = node;
        this->row = row;
        this->col = col;
    }
};

int minCol = 0, maxCol = 0;

void dfs(TreeNode<int> *root, int row, int col)
{
    if (root == NULL)
        return;

    minCol = min(minCol, col);
    maxCol = max(maxCol, col);

    dfs(root->left, row + 1, col - 1);
    dfs(root->right, row + 1, col + 1);
}

void bfs(TreeNode<int> *root, vector<vector<int>> &ans)
{
    if (root == NULL)
        return;

    queue<QNode> q;
    q.push(QNode(root, 0, -minCol));
    int prevRow = 0, n = maxCol - minCol + 1;
    vector<vector<int>> smallAns(n);

    while (!q.empty())
    {
        QNode node = q.front();
        q.pop();

        if (prevRow != node.row)
        {
            for (int i = 0; i < n; i++)
            {
                sort(smallAns[i].begin(), smallAns[i].end());
                ans[i].insert(ans[i].end(), smallAns[i].begin(), smallAns[i].end());
                smallAns[i].clear();
            }
        }
        prevRow = node.row;
        smallAns[node.col].push_back(node.node->data);

        if (node.node->left != NULL)
        {
            q.push(QNode(node.node->left, node.row + 1, node.col - 1));
        }

        if (node.node->right != NULL)
        {
            q.push(QNode(node.node->right, node.row + 1, node.col + 1));
        }
    }

    for (int i = 0; i < n; i++)
    {
        sort(smallAns[i].begin(), smallAns[i].end());
        ans[i].insert(ans[i].end(), smallAns[i].begin(), smallAns[i].end());
    }
}

vector<vector<int>> verticalTraversal(TreeNode<int> *root)
{
    dfs(root, 0, 0);
    int n = maxCol - minCol + 1;
    vector<vector<int>> ans(n);
    bfs(root, ans);

    return ans;
}

vector<vector<int>> zigzagLevelOrder(TreeNode<int> *root)
{
    queue<TreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    vector<vector<int>> ans;
    vector<int> temp;
    int level = 0;

    while (!q.empty())
    {
        TreeNode<int> *node = q.front();
        q.pop();

        if (node == NULL)
        {
            if (level % 2)
                reverse(temp.begin(), temp.end());

            ans.push_back(temp);
            temp.clear();

            if (!q.empty())
            {
                level++;
                q.push(NULL);
            }

            continue;
        }

        temp.push_back(node->data);

        TreeNode<int> *left = node->left;
        TreeNode<int> *right = node->right;

        if (left)
            q.push(left);
        if (right)
            q.push(right);
    }

    return ans;
}

// 1 2 3 4 5 6 -1 7 -1 8 -1 -1 -1 -1 -1 -1 -1

//           1
//      2         3
//   4    5     6
// 7    8

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    cout << endl
         << endl;

    vector<vector<int>> ans = zigzagLevelOrder(root);
    for (auto it : ans)
    {
        for (auto vec : it)
        {
            cout << vec << " ";
        }
        cout << endl;
    }

    // printLevelWise(root);

    // cout << nodesCount(root) << endl;

    // int x;
    // cin >> x;
    // cout << nodePresent(root, x) << endl;

    // cout << treeHeight(root) << endl;

    // printLevelWise(root);
    // mirrorTree(root);
    // printLevelWise(root);

    // preOrder(root);

    // postOrder(root);

    // inOrder(root);

    // int n;
    // cin >> n;
    // int inorder[n], preorder[n];

    // for (int i = 0; i < n; i++)
    //     cin >> preorder[i];

    // for (int i = 0; i < n; i++)
    //     cin >> inorder[i];

    // TreeNode<int> *root = constructTreePreorder(inorder, preorder, 0, n - 1, 0, n - 1);
    // printLevelWise(root);

    // int n;
    // cin >> n;
    // int inorder[n], postorder[n];

    // for (int i = 0; i < n; i++)
    //     cin >> postorder[i];

    // for (int i = 0; i < n; i++)
    //     cin >> inorder[i];

    // TreeNode<int> *root = constructTreePostOrder(postorder, inorder, 0, n - 1, 0, n - 1);
    // printLevelWise(root);

    // cout << diameter(root).first << " " << diameter(root).second << endl;

    // cout << minMax(root).first << " " << minMax(root).second << endl;

    // cout << sum(root) << endl;

    // pair<bool, int> ans = balanced(root);
    // cout << ans.first << " " << ans.second << endl;

    // levelOrder(root);

    // levelOrder(root);
    // removeLeafNodes(root);
    // levelOrder(root);

    // vector<vector<int>> list;
    // makeLevelList(root, list, 0);
    // for (auto it : list)
    // {
    //     for (auto vec : it)
    //     {
    //         cout << vec << " ";
    //     }
    //     cout << endl;
    // }

    // printZigZag(root);

    // printLevelWise(root);
    // NodesWithoutSibling(root);

    // printLevelWise(root);
    // duplicateLeft(root);
    // printLevelWise(root);

    // pairsum
    // int sum;
    // cin >> sum;
    // vector<pair<int, int>> ans;
    // pairSum(root, sum, ans);
    // for (auto it : ans)
    // {
    //     cout << it.first << " " << it.second << endl;
    // }

    // LCA
    // int x, y;
    // cin >> x >> y;
    // cout << LCA_best(root, x, y) << endl;

    // cout << maxBst(root).maxBst << endl;

    // vector<int> ans;
    // vector<vector<int>> ds;
    // int k;
    // cin >> k;
    // pathSumK(root, k, 0, ds, ans);
    // for (auto it : ds)
    // {
    //     for (auto vec : it)
    //     {
    //         cout << vec << " ";
    //     }
    //     cout << endl;
    // }

    // int target, k;
    // cin >> target >> k;
    // printNodesK(root, target, k);

    // vector<vector<int>> ans = verticalTraversal(root);
    // for (auto it : ans)
    // {
    //     for (auto vec : it)
    //     {
    //         cout << vec << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}