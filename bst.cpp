#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class BstNode
{
public:
    int data;
    BstNode *left;
    BstNode *right;

    BstNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class BST
{
    BstNode *root;

    bool hasData(int data, BstNode *root)
    {
        if (root == NULL)
            return false;

        if (root->data == data)
            return true;
        else if (root->data < data)
            return hasData(data, root->right);
        else
            return hasData(data, root->left);
    }

    void insert(int data, BstNode *&root)
    {
        if (root == NULL)
        {
            root = new BstNode(data);
            return;
        }

        if (root->data <= data)
            insert(data, root->right);
        else
            insert(data, root->left);
    }

    void deleteNode(int data, BstNode *&root)
    {
        if (root == NULL)
            return;

        if (root->data == data)
        {
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                root = NULL;
            }
            else if (root->left == NULL)
            {
                BstNode *temp = root->right;
                delete root;
                root = temp;
            }
            else if (root->right == NULL)
            {
                BstNode *temp = root->left;
                delete root;
                root = temp;
            }
            else
            {
                BstNode *minNode = root->right;
                while (minNode->left != NULL)
                    minNode = minNode->left;

                root->data = minNode->data;
                deleteNode(minNode->data, root->right);
            }
        }
        else if (root->data > data)
            deleteNode(data, root->left);
        else
            deleteNode(data, root->right);
    }

public:
    BST()
    {
        root = NULL;
    }

    bool hasData(int data)
    {
        return hasData(data, root);
    }

    void insert(int data)
    {
        insert(data, root);
    }

    void deleteNode(int data)
    {
        deleteNode(data, root);
    }

    void print()
    {
        if (root == NULL)
            return;

        queue<BstNode *> pendingNodes;
        pendingNodes.push(root);
        pendingNodes.push(NULL);

        while (!pendingNodes.empty())
        {
            BstNode *front = pendingNodes.front();
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
};

BstNode *takeInputLevelWise()
{
    cout << "Enter tree : ";
    int rootData;
    cin >> rootData;

    BstNode *root = new BstNode(rootData);
    queue<BstNode *> pendingNodes;
    pendingNodes.push(root);

    while (!pendingNodes.empty())
    {
        BstNode *front = pendingNodes.front();
        pendingNodes.pop();

        int leftChild, rightChild;
        cin >> leftChild;
        cin >> rightChild;

        if (leftChild != -1)
        {
            BstNode *left = new BstNode(leftChild);
            front->left = left;
            pendingNodes.push(left);
        }

        if (rightChild != -1)
        {
            BstNode *right = new BstNode(rightChild);
            front->right = right;
            pendingNodes.push(right);
        }
    }

    return root;
}

void printLevelWise(BstNode *root)
{
    if (root == NULL)
        return;

    queue<BstNode *> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);

    while (!pendingNodes.empty())
    {
        BstNode *front = pendingNodes.front();
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

bool search(BstNode *root, int k)
{
    if (root == NULL)
        return false;

    if (root->data == k)
        return true;

    if (root->data < k)
        return search(root->right, k);

    return search(root->left, k);
}

void print_range(BstNode *root, int l, int h)
{
    if (root == NULL)
        return;

    print_range(root->left, l, h);
    if (root->data >= l && root->data <= h)
        cout << root->data << " ";
    print_range(root->right, l, h);
}

class bstReturn
{
public:
    int min;
    int max;
    bool isBst;
};

bstReturn isBst(BstNode *root)
{
    if (root == NULL)
    {
        bstReturn ans;
        ans.isBst = true;
        ans.min = INT_MAX;
        ans.max = INT_MIN;

        return ans;
    }

    bstReturn leftAns = isBst(root->left);
    bstReturn rightAns = isBst(root->right);
    int minimum = min(root->data, min(leftAns.min, rightAns.min));
    int maximum = max(root->data, max(leftAns.max, rightAns.max));

    bstReturn ans;
    ans.min = minimum;
    ans.max = maximum;
    ans.isBst = root->data > leftAns.max && root->data <= rightAns.min && leftAns.isBst && rightAns.isBst;

    return ans;
}

bool isBstSimple(BstNode *root, int l = INT_MIN, int h = INT_MAX)
{
    if (root == NULL)
        return true;

    if (root->data >= l && root->data < h)
        return isBstSimple(root->left, l, root->data) && isBstSimple(root->right, root->data, h);

    return false;
}

BstNode *constructBst(int a[], int i, int j)
{
    BstNode *root = NULL;

    if (i <= j)
    {
        int mid = (j - i) / 2 + i;
        root = new BstNode(a[mid]);
        root->left = constructBst(a, i, mid - 1);
        root->right = constructBst(a, mid + 1, j);
    }

    return root;
}

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

pair<Node *, Node *> bstToLL(BstNode *root)
{
    if (root == NULL)
        return {NULL, NULL};

    Node *head = NULL, *tail = NULL;

    pair<Node *, Node *> leftAns = bstToLL(root->left);
    pair<Node *, Node *> rightAns = bstToLL(root->right);

    head = leftAns.first;
    tail = leftAns.second;
    if (head == NULL)
    {
        head = new Node(root->data);
        tail = head;
    }
    else
    {
        tail->next = new Node(root->data);
        tail->next->next = rightAns.first;
        tail = rightAns.second;
    }
    return {head, tail};
}

void printLL(Node *head)
{
    if (head == NULL)
        return;

    cout << head->data << " ";
    printLL(head->next);
}

bool findPath(BstNode *root, queue<int> &path, int key)
{
    if (root == NULL)
        return false;

    path.push(root->data);

    if (root->data == key)
        return true;
    else if (root->data > key)
        return findPath(root->left, path, key);

    return findPath(root->right, path, key);
}

void printPath(BstNode *root, int key)
{
    queue<int> path;
    if (findPath(root, path, key))
    {
        while (!path.empty())
        {
            cout << path.front() << " ";
            path.pop();
        }
        cout << endl;
    }
}

void replaceGreaterSum(BstNode *root, int &sum)
{
    if (root == NULL)
        return;

    replaceGreaterSum(root->right, sum);
    sum += root->data;
    root->data = sum;
    replaceGreaterSum(root->left, sum);
}

class BstIterator
{
    stack<BstNode *> s;
    bool reverse;

    void pushAll(BstNode *root)
    {
        while (root != NULL)
        {
            s.push(root);
            if (reverse)
                root = root->right;
            else
                root = root->left;
        }
    }

public:
    BstIterator(BstNode *root, bool isReverse)
    {
        reverse = isReverse;
        pushAll(root);
    }

    int next()
    {
        BstNode *top = s.top();
        s.pop();
        if (reverse)
            pushAll(top->left);
        else
            pushAll(top->right);

        return top->data;
    }

    bool hasNext()
    {
        return !s.empty();
    }
};

void twoSum(BstNode *root, vector<pair<int, int>> &ans, int target)
{
    if (root == NULL)
        return;

    BstIterator l(root, false), h(root, true);

    int i = l.next(), j = h.next();

    while (i < j)
    {
        if (i + j == target)
        {
            ans.push_back({i, j});
            i = l.next();
            j = h.next();
        }
        else if (i + j < target)
            i = l.next();
        else
            j = h.next();
    }
}

// 5 3 8 1 4 6 9 -1 -1 -1 -1 -1 -1 -1 -1
// 5 3 8 1 10 6 9 -1 -1 -1 -1 -1 -1 -1 -1
int main()
{
    BstNode *root = takeInputLevelWise();
    printLevelWise(root);

    // cout << search(root, 10) << endl;
    // print_range(root, 2, 8);
    // cout << isBst(root).isBst << endl;
    // cout << isBstSimple(root) << endl;

    // int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    // BstNode *root = constructBst(a, 0, 7);
    // printLevelWise(root);

    // Node *head = bstToLL(root).first;
    // printLL(head);
    // printPath(root, 9);

    // BST tree;
    // tree.insert(10);
    // tree.insert(4);
    // tree.insert(6);
    // tree.insert(16);
    // tree.insert(12);
    // tree.insert(18);
    // tree.insert(12);
    // tree.insert(5);

    // tree.print();
    // cout << endl;
    // tree.deleteNode(12);
    // tree.print();
    // cout << endl;
    // tree.deleteNode(4);
    // tree.print();
    // cout << endl;
    // tree.deleteNode(10);
    // tree.print();
    // cout << endl;
    // cout << tree.hasData(10) << " " << tree.hasData(18) << endl;

    // int sum = 0;
    // replaceGreaterSum(root, sum);
    // cout << endl
    //      << endl;
    // printLevelWise(root);

    vector<pair<int, int>> ans;
    int target;
    cin >> target;
    twoSum(root, ans, target);
    for (auto it : ans)
    {
        cout << it.first << " " << it.second << endl;
    }

    return 0;
}