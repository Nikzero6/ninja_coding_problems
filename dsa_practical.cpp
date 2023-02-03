#include <iostream>
#include <climits>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

public:
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
    void insert(int data, Node **tail)
    {
        Node *newNode = new Node(data);
        (*tail)->next = newNode;
        newNode->prev = *tail;
        (*tail) = newNode;
    }
};

pair<int, int> ExtremeSwap(Node *&head, Node *&tail)
{
    Node *start = head;
    Node *end = tail;

    int largest = INT_MIN, secondLargest = INT_MIN;

    if (start->data > end->data)
        swap(start->data, end->data);

    largest = max(start->data, end->data);
    secondLargest = min(start->data, end->data);

    start = start->next;
    end = end->prev;

    while (start != NULL && end != NULL)
    {
        if (start->data > largest)
        {
            int temp = largest;
            largest = start->data;
            secondLargest = temp;
        }
        else if (start->data > secondLargest)
        {
            secondLargest = start->data;
        }

        if (end->data > largest)
        {
            largest = end->data;
            secondLargest = largest;
        }
        else if (end->data > secondLargest)
        {
            secondLargest = end->data;
        }

        if (start->data > end->data)
            swap(start->data, end->data);

        if (start == end || start->next == end)
            break;

        start = start->next;
        end = end->prev;
    }

    return {largest, secondLargest};
}

int main()
{
    int n;
    cout << "Enter the length of LL:";
    cin >> n;
    int x;
    cin >> x;
    Node *head = new Node(x);
    Node *tail = head;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> x;
        head->insert(x, &tail);
    }

    pair<int, int> ans = ExtremeSwap(head, tail);
    Node *temp = head;

    cout << "Final Linked List:";
    // Iterate until node is NOT NULL
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    cout << "Largest=" << ans.first << " Second largest=" << ans.second;
}