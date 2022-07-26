#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class priorityQueue
{
    vector<int> pq;
    bool isMax;

    void swap(int i, int j)
    {
        int temp = pq[i];
        pq[i] = pq[j];
        pq[j] = temp;
    }

public:
    priorityQueue(bool isMax = false)
    {
        this->isMax = isMax;
    }

    bool empty()
    {
        return !pq.size();
    }

    int size()
    {
        return pq.size();
    }

    int front()
    {
        if (empty())
            return -1;

        return pq[0];
    }

    void push(int data)
    {
        pq.push_back(data);

        int childInd = pq.size() - 1;

        while (childInd > 0)
        {
            int parentInd = (childInd - 1) / 2;

            if (!isMax && pq[parentInd] > pq[childInd])
                swap(parentInd, childInd);
            else if (isMax && pq[parentInd] < pq[childInd])
                swap(parentInd, childInd);
            else
                break;

            childInd = parentInd;
        }
    }

    int pop()
    {
        if (empty())
            return -1;

        int popped = pq[0];
        int lastInd = pq.size() - 1;
        pq[0] = pq[lastInd];
        pq.pop_back();

        int currInd = 0, leftInd = 1, rightInd = 2;

        while (leftInd < lastInd)
        {
            int minInd = leftInd;
            if (!isMax && rightInd < lastInd && pq[leftInd] > pq[rightInd])
                minInd = rightInd;
            else if (isMax && rightInd < lastInd && pq[leftInd] < pq[rightInd])
                minInd = rightInd;

            if (!isMax && pq[currInd] > pq[minInd])
                swap(currInd, minInd);
            else if (isMax && pq[currInd] < pq[minInd])
                swap(currInd, minInd);
            else
                break;

            currInd = minInd;
            leftInd = 2 * currInd + 1;
            rightInd = 2 * currInd + 2;
        }

        return popped;
    }
};

void swap(int i, int j, vector<int> &a)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void build_heap(vector<int> &a)
{
    int i = 1;

    while (i < a.size())
    {
        int j = i;
        while (j > 0)
        {
            int parentInd = (j - 1) / 2;
            if (a[parentInd] > a[j])
                swap(parentInd, j, a);
            else
                break;

            j = parentInd;
        }
        i++;
    }
}

void remove_heap(vector<int> &a)
{
    int size = a.size();

    while (size)
    {
        int lastInd = size - 1;
        swap(0, lastInd, a);
        size--;

        int currInd = 0, leftInd = 1, rightInd = 2;

        while (leftInd < lastInd)
        {
            int minInd = leftInd;
            if (rightInd < lastInd && a[leftInd] > a[rightInd])
                minInd = rightInd;

            if (a[minInd] < a[currInd])
                swap(minInd, currInd, a);
            else
                break;

            currInd = minInd;
            leftInd = 2 * currInd + 1;
            rightInd = 2 * currInd + 2;
        }
    }
}

void heap_sort(vector<int> &a)
{
    build_heap(a);
    remove_heap(a);
}

void KsortedArr(vector<int> &a, int k)
{
    priority_queue<int> pq;

    for (int i = 0; i < k; i++)
        pq.push(a[i]);

    int j = 0;
    for (int i = k; i < a.size(); i++)
    {
        a[j] = pq.top();
        pq.pop();
        pq.push(a[i]);
        j++;
    }

    while (!pq.empty())
    {
        a[j] = pq.top();
        pq.pop();
        j++;
    }
}

vector<int> KSmallest(vector<int> a, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
        pq.push(a[i]);

    for (int i = k; i < a.size(); i++)
    {
        pq.push(a[i]);
        pq.pop();
    }

    vector<int> ans;
    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }

    return ans;
}

vector<int> Klargest(vector<int> a, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < k; i++)
        pq.push(a[i]);

    for (int i = k; i < a.size(); i++)
    {
        pq.push(a[i]);
        pq.pop();
    }

    vector<int> ans;
    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}

int KLargestElem(vector<int> a, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < k; i++)
        pq.push(a[i]);

    for (int i = k; i < a.size(); i++)
    {
        pq.push(a[i]);
        pq.pop();
    }

    return pq.top();
}

bool check_max_heap(vector<int> a)
{
    int currInd = 0, leftInd = 1, rightInd = 2;
    int lastInd = a.size();

    while (leftInd < lastInd)
    {
        int maxInd = leftInd;

        if (rightInd < lastInd && a[rightInd] > a[leftInd])
            maxInd = rightInd;

        if (a[currInd] < a[maxInd])
            return false;

        currInd = maxInd;
        leftInd = 2 * currInd + 1;
        rightInd = 2 * currInd + 2;
    }

    return true;
}

class Triplet
{
public:
    int elem, aInd, elemInd;
    Triplet(int elem, int aInd, int elemInd)
    {
        this->elem = elem;
        this->aInd = aInd;
        this->elemInd = elemInd;
    }
};

class Compare
{
public:
    bool operator()(Triplet t1, Triplet t2)
    {
        return t1.elem > t2.elem;
    }
};

vector<int> mergeKsorted(vector<vector<int>> a)
{
    priority_queue<Triplet, vector<Triplet>, Compare> pq;
    for (int i = 0; i < a.size(); i++)
    {
        pq.push(Triplet(a[i][0], i, 0));
    }

    vector<int> ans;
    while (!pq.empty())
    {
        Triplet min = pq.top();
        pq.pop();
        ans.push_back(min.elem);
        if (a[min.aInd].size() - 1 > min.elemInd)
            pq.push(Triplet(a[min.aInd][min.elemInd + 1], min.aInd, min.elemInd + 1));
    }

    return ans;
}

vector<int> running_median(vector<int> a)
{
    priority_queue<int, vector<int>, greater<int>> min;
    priority_queue<int> max;
    vector<int> ans;

    // max: 3 2 1
    // min: 5 6 7
    // ans: 6 4 2 2 3 4
    for (int i = 0; i < a.size(); i++)
    {
        if (max.empty() || a[i] < max.top())
        {
            max.push(a[i]);
            if (max.size() - min.size() == 2)
            {
                min.push(max.top());
                max.pop();
            }
        }
        else
        {
            min.push(a[i]);
            if (min.size() - max.size() == 2)
            {
                max.push(min.top());
                min.pop();
            }
        }

        if (max.size() == min.size())
            ans.push_back((max.top() + min.top()) / 2);
        else if (max.size() > min.size())
            ans.push_back(max.top());
        else
            ans.push_back(min.top());
    }

    return ans;
}

int buy_ticket(vector<int> a, int k)
{
    priority_queue<int> pq;

    for (int i = 0; i < a.size(); i++)
        pq.push(a[i]);

    // 2' 3' 2' 2' 4
    // 2'
    // pq: 2'
    // time: 4
    int time = 0;
    for (int i = 0; i <= k; i++)
    {
        if (a[i] <= pq.top())
        {
            time++;
            pq.pop();
        }
    }

    return time;
}

int main()
{
    // priorityQueue p(true);

    // cout << p.empty() << endl;
    // cout << p.front() << endl;
    // cout << p.size() << endl;

    // p.push(100);
    // p.push(10);
    // p.push(14);
    // p.push(28);
    // p.push(4);

    // cout << p.size() << endl;
    // cout << p.front() << endl;

    // while (!p.empty())
    // {
    //     cout << p.pop() << " ";
    // }

    // int n;
    // cin >> n;
    // vector<int> a(n);
    // for (int i = 0; i < n; i++)
    //     cin >> a[i];

    // heap_sort(a);
    // KsortedArr(a, 3);
    // cout << check_max_heap(a) << endl;
    // cout << KLargestElem(a, 4) << endl;

    // vector<int> ans = Klargest(a, 4);

    // for (auto it : ans)
    // {
    //     cout << it << " ";
    // }
    // cout << endl;

    // int n;
    // cin >> n;
    // vector<vector<int>> a;

    // for (int i = 0; i < n; i++)
    // {
    //     int m;
    //     cin >> m;
    //     vector<int> b(m);
    //     for (int j = 0; j < m; j++)
    //         cin >> b[j];

    //     a.push_back(b);
    // }

    // vector<int> ans = mergeKsorted(a);
    // for (auto it : ans)
    // {
    //     cout << it << " ";
    // }
    // cout << endl;

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // vector<int> ans = running_median(a);
    // for (auto it : ans)
    // {
    //     cout << it << " ";
    // }
    // cout << endl;

    int i;
    cin >> i;
    cout << buy_ticket(a, i) << endl;

    return 0;
}