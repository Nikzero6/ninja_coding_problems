#include <iostream>
using namespace std;
#include <string>
#include <stack>

class Node
{
public:
    int data;
    Node *next;
    static int length;

public:
    Node(int data)
    {
        this->data = data;
        next = NULL;
        length++;
    }
    void insert(int data, Node **tail)
    {
        Node *newNode = new Node(data);
        (*tail)->next = newNode;
        (*tail) = newNode;
    }
};

int Node::length = 0;

int list_length(Node *head)
{
    Node *temp = head;
    int length = 0;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    return length;
}

void print_i(int i, Node *head)
{
    Node *temp = head;
    while (i && temp != NULL)
    {
        temp = temp->next;
        i--;
    }
    if (temp != NULL)
        cout << temp->data << endl;
}

void insert_i(int i, Node *head, int data)
{
    Node *temp = head;
    while (i > 0 && temp != NULL)
    {
        temp = temp->next;
        i--;
    }
    if (temp != NULL)
    {
        Node *newNode = new Node(data);
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void takeInput(Node *head)
{
    Node *temp = head;

    int data = 0;
    cin >> data;
    temp->data = data;

    while (data != -1)
    {
        cin >> data;
        if (data != -1)
        {
            Node *newNode = new Node(data);
            temp->next = newNode;
            temp = temp->next;
        }
    }
}

void deleteNode(Node **head, int i)
{
    Node *temp = *head;
    if (i == 0)
    {
        *head = (*head)->next;
        delete temp;
        Node::length--;
        return;
    }
    while (i - 1 > 0 && temp != NULL)
    {
        temp = temp->next;
        i--;
    }
    if (temp != NULL)
    {
        Node *nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
        Node::length--;
    }
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int length_recursive(Node *head, int count)
{
    if (head == NULL)
        return count;

    return length_recursive(head->next, count + 1);
}

void insert_recursive(int i, int data, Node **head)
{
    if (*head == NULL)
        return;

    if (i - 1 == 0)
    {
        Node *newNode = new Node(data);
        newNode->next = (*head)->next;
        (*head)->next = newNode;
        return;
    }

    if (i == 0)
    {
        Node *newNode = new Node(data);
        newNode->next = (*head);
        *head = newNode;
        return;
    }

    return insert_recursive(i - 1, data, &(*head)->next);
}

void delete_recursive(int i, Node **head)
{
    if (*head == NULL)
        return;

    if (i - 1 == 0)
    {
        Node *nodeToDelete = (*head)->next;
        (*head)->next = nodeToDelete->next;
        delete nodeToDelete;
        Node::length--;
        return;
    }

    if (i == 0)
    {
        Node *nodeToDelete = *head;
        *head = (*head)->next;
        delete nodeToDelete;
        Node::length--;
        return;
    }

    return delete_recursive(i - 1, &(*head)->next);
}

int findNode(Node *head, int key, int index)
{
    if (head == NULL)
        return -1;

    if (head->data == key)
        return index;

    return findNode(head->next, key, index + 1);
}

Node *appendLastNToFirst(Node *head, int n)
{
    Node *curr = head;
    int size = list_length(head);
    int i = size - n - 1;
    while (i > 0)
    {
        curr = curr->next;
        i--;
    }

    Node *temp = curr->next;
    curr->next = NULL;
    curr = temp;
    Node *newHead = curr;

    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    curr->next = head;

    return newHead;
}

Node *remove_duplicates(Node *head)
{
    Node *curr = head;
    while (curr != NULL && curr->next != NULL)
    {
        if (curr->data == curr->next->data)
        {
            Node *temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
            Node::length--;
        }
        curr = curr->next;
    }

    return head;
}

void print_reverse(Node *head)
{
    if (head == NULL)
        return;

    print_reverse(head->next);
    cout << head->data << " ";
}

bool pallindrome(Node *head)
{
    int size = length_recursive(head, 0);
    int i = size / 2;

    string left = "", right = "";

    Node *curr = head;
    while (i)
    {
        left.push_back(curr->data);
        curr = curr->next;
        i--;
    }

    if (size % 2 != 0)
        curr = curr->next;

    while (curr != NULL)
    {
        right.push_back(curr->data);
        curr = curr->next;
    }

    reverse(right.begin(), right.end());

    if (left == right)
        return true;
    else
        return false;
}

bool pallindrome_optimized(Node *head)
{
    int size = list_length(head);
    int mid = size / 2 - 1;

    Node *curr = head;
    while (mid > 0)
    {
        curr = curr->next;
        mid--;
    }

    Node *temp = curr->next;
    curr->next = NULL;
    curr = temp;

    if (size % 2 != 0 && curr != NULL)
        curr = curr->next;

    Node *head2 = curr;

    while (curr != NULL && curr->next != NULL)
    {
        Node *temp = curr->next;
        curr->next = temp->next;
        temp->next = head2;
        head2 = temp;
    }

    while (head != NULL && head2 != NULL)
    {
        if (head->data != head2->data)
            return false;

        head = head->next;
        head2 = head2->next;
    }

    return true;
}

int mid_point(Node *head)
{
    Node *slow = head, *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        if (fast->next == NULL)
            fast = fast->next;
        else
            fast = fast->next->next;
    }

    return slow->data;
}

Node *merge_list(Node *head1, Node *head2)
{
    // save heads
    Node *head_1 = head1;
    Node *head_2 = head2;
    int flag = 0;

    Node *prev = NULL;
    // if 2nd list has smaller elems than 1st elem of 1st list
    while (head2->next != NULL && head1->data >= head2->data)
    {
        flag = 1;
        prev = head2;
        head2 = head2->next;
    }
    if (prev != NULL)
        prev->next = head_1;

    // traverse remaining list
    while (head1 != NULL && head2 != NULL)
    {

        if (head1->data >= head2->data)
        {
            // if larger or equal found, append 2 from front of current larger elem in 1
            Node *temp = head2->next;
            prev->next = head2;
            head2->next = head1;
            prev = head2;
            head2 = temp;
        }
        else
        {
            // if 2nd greater than 1 keep on traversing 1 until larger or null found
            prev = head1;
            head1 = head1->next;
        }
    }

    // if 2 has elems greater than last elem of 1;
    if (head1 == NULL && head2 != NULL)
        prev->next = head2;

    if (flag)
        return head_2;
    else
        return head_1;
}

Node *merge_better(Node *head1, Node *head2)
{
    Node *fH = NULL, *fT = NULL;

    if (head1->data <= head2->data)
    {
        fH = head1;
        fT = head1;
        head1 = head1->next;
    }
    else
    {
        fH = head2;
        fT = head2;
        head2 = head2->next;
    }

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data <= head2->data)
        {
            fT->next = head1;
            fT = head1;
            head1 = head1->next;
        }
        else
        {
            fT->next = head2;
            fT = head2;
            head2 = head2->next;
        }
    }

    if (head1 != NULL)
        fT->next = head1;

    if (head2 != NULL)
        fT->next = head2;

    return fH;
}

Node *merge_sort(Node *head, Node *slow, Node *fast)
{
    if (fast == NULL)
        return head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        if (fast->next != NULL)
            fast = fast->next->next;
    }

    Node *head1 = head, *head2 = slow->next;
    slow->next = NULL;

    head1 = merge_sort(head1, head1, head1->next);
    head2 = merge_sort(head2, head2, head2->next);
    return merge_better(head1, head2);
}

Node *reverse_ll_recursive(Node *head)
{
    if (head->next == NULL)
        return head;

    Node *newHead = reverse_ll_recursive(head->next);

    Node *curr = newHead;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = head;
    head->next = NULL;

    return newHead;
}

pair<Node *, Node *> reverse_optimized(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        pair<Node *, Node *> ans;
        ans.first = head;
        ans.second = head;
        return ans;
    }

    pair<Node *, Node *> smallAns = reverse_optimized(head->next);
    smallAns.second->next = head;
    head->next = NULL;

    return pair<Node *, Node *>(smallAns.first, head);
}

Node *reverse_best(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *newHead = reverse_best(head->next);
    Node *tail = head->next;
    tail->next = head;
    head->next = NULL;

    return newHead;
}

Node *reverse_iterative(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;

    while (curr != NULL)
    {
        Node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    return prev;
}

int find_node(Node *head, int key)
{
    int count = 0;
    int flag = 0;

    while (head != NULL)
    {
        if (head->data == key)
        {
            flag = 1;
            break;
        }

        count++;
        head = head->next;
    }

    if (flag)
        return count;
    else
        return -1;
}

Node *separate_odd_even(Node *head)
{
    Node *oddHead = NULL, *evenHead = NULL, *oddTail = NULL, *evenTail = NULL;

    Node *curr = head;
    while (curr != NULL && curr->data % 2 == 0)
    {
        curr = curr->next;
    }

    if (curr == NULL)
    {
        return head;
    }
    else
    {
        oddHead = curr;
        oddTail = curr;
    }

    curr = head;
    while (curr != NULL && curr->data % 2 != 0)
    {
        curr = curr->next;
    }

    if (curr == NULL)
    {
        return head;
    }
    else
    {
        evenHead = curr;
        evenTail = curr;
    }

    curr = head;
    while (curr != NULL)
    {
        if (curr->data % 2 == 0 && curr != evenHead)
        {
            evenTail->next = curr;
            evenTail = curr;
        }
        else if (curr->data % 2 != 0 && curr != oddHead)
        {
            oddTail->next = curr;
            oddTail = curr;
        }
        curr = curr->next;
    }

    oddTail->next = evenHead;
    evenTail->next = NULL;

    return oddHead;
}

void delete_m_n(Node *&head, int m, int n)
{
    Node *curr = head;
    Node *prev = NULL;
    while (curr != NULL)
    {
        int x = m;
        while (x && curr != NULL)
        {
            prev = curr;
            curr = curr->next;
            x--;
        }

        int y = n;
        while (y && curr != NULL)
        {
            Node *temp = curr->next;
            delete curr;
            curr = temp;
            y--;
        }
        if (prev != NULL)
            prev->next = curr;
    }

    if (prev == NULL)
        head = NULL;
}

void swap(Node *&head, int i, int j)
{
    int minNum = min(i, j);
    int maxNum = max(i, j);

    Node *p1 = NULL, *c1 = NULL, *p2 = NULL, *c2 = NULL;

    Node *curr = head;
    int x = minNum;
    while (x > 0 && curr != NULL)
    {
        p1 = curr;
        curr = curr->next;
        x--;
    }
    c1 = curr;

    int y = maxNum - minNum;
    while (y > 0 && curr != NULL)
    {
        p2 = curr;
        curr = curr->next;
        y--;
    }
    c2 = curr;

    if (maxNum - minNum == 1 && minNum == 0)
    {
        c1->next = c2->next;
        c2->next = c1;
        head = c2;
    }
    else if (maxNum - minNum == 1)
    {
        p1->next = c2;
        c1->next = c2->next;
        c2->next = c1;
    }
    else if (minNum == 0)
    {
        p2->next = c1;
        Node *temp = c1->next;
        c1->next = c2->next;
        c2->next = temp;
        head = c2;
    }
    else
    {
        p1->next = c2;
        p2->next = c1;
        Node *temp = c1->next;
        c1->next = c2->next;
        c2->next = temp;
    }
}

Node *reverse_k(Node *head, int k)
{
    if (k == 0 || k == 1)
        return head;

    if (head == NULL || head->next == NULL)
        return head;

    Node *curr = head;
    int x = k - 1;
    while (x && curr->next != NULL)
    {
        curr = curr->next;
        x--;
    }

    Node *nextHead = reverse_k(curr->next, k);
    curr->next = NULL;
    Node *prev = NULL;

    curr = head;
    while (curr != NULL)
    {
        Node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    head->next = nextHead;

    return prev;
}

Node *bubble_sort(Node *head)
{
    int size = list_length(head);

    while (size - 1)
    {
        Node *p0 = NULL, *p1 = head, *p2 = head->next;
        int flag = 0;

        while (p2 != NULL)
        {
            if (p1->data > p2->data)
            {
                if (p0 == NULL)
                {
                    p1->next = p2->next;
                    p2->next = p1;
                    head = p2;
                }
                else
                {
                    p0->next = p2;
                    p1->next = p2->next;
                    p2->next = p1;
                }
                p0 = p2;
                p2 = p1->next;
                flag = 1;
            }
            else
            {
                p0 = p1;
                p1 = p2;
                p2 = p2->next;
            }
        }
        size--;
        if (!flag)
            break;
    }

    return head;
}

Node *next_number(Node *head)
{
    int num = 0;
    Node *curr = head;

    while (curr != NULL)
    {
        num = num * 10 + curr->data;
        curr = curr->next;
    }

    num++;
    stack<int> s;

    while (num != 0)
    {
        s.push(num % 10);
        num /= 10;
    }

    curr = head;
    Node *tail = NULL;

    while (curr != NULL)
    {
        curr->data = s.top();
        s.pop();
        tail = curr;
        curr = curr->next;
    }

    while (!s.empty())
    {
        Node *newNode = new Node(s.top());
        s.pop();
        tail->next = newNode;
        tail = newNode;
    }

    return head;
}

void delete_alternate(Node *head)
{
    if (head == NULL || head->next == NULL)
        return;

    Node *curr = head;

    while (curr != NULL && curr->next != NULL)
    {
        Node *prev = curr;
        curr = curr->next;
        prev->next = curr->next;
        delete curr;
        curr = prev->next;
    }
}

int main()
{
    Node *head = new Node(10);
    Node *tail = head;

    // takeInput(head);

    // cout << length_recursive(head, 0) << endl;
    // cout << Node::length << endl;

    // print(head);
    // insert_recursive(0, 50, &head);
    // print(head);
    // cout << Node::length << endl;
    // delete_recursive(0, &head);
    // print(head);
    // cout << Node::length << endl;
    // cout << findNode(head, 40, 0) << endl;
    // head = appendLastNToFirst(head, 2);
    // head = remove_duplicates(head);
    // print(head);
    // cout << Node::length << endl;
    // print_reverse(head);
    // cout << pallindrome_optimized(head) << endl;
    // cout << mid_point(head) << endl;

    // merge
    // Node *head1 = new Node(10);
    // Node *head2 = new Node(10);

    // takeInput(head1);
    // takeInput(head2);
    // print(head1);
    // print(head2);
    // head = merge_better(head1, head2);
    // print(head);

    // merge sort
    // takeInput(head);
    // head = merge_sort(head, head, head->next);
    // print(head);

    // reverse recursive
    // takeInput(head);
    // head = reverse_best(head);
    // print(head);

    // reverse iterative
    // takeInput(head);
    // head = reverse_iterative(head);
    // print(head);

    // find node
    // takeInput(head);
    // cout << find_node(head, 10) << endl;

    // separate odd and even
    // takeInput(head);
    // head = separate_odd_even(head);
    // print(head);

    // delete n nodes after m
    // takeInput(head);
    // delete_m_n(head, 0, 1);
    // print(head);

    // swap nodes
    // takeInput(head);
    // swap(head, 0, 1);
    // print(head);

    // reverse k
    // takeInput(head);
    // head = reverse_k(head, 4);
    // print(head);

    // bubble sort
    // takeInput(head);
    // head = bubble_sort(head);
    // print(head);

    // next number
    // takeInput(head);
    // head = next_number(head);
    // print(head);

    // delete alternate
    takeInput(head);
    delete_alternate(head);
    print(head);

    return 0;
}