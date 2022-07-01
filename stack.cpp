#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    static int length;
    Node(int data)
    {
        this->data = data;
        next = NULL;
        length++;
    }
};

int Node::length = 0;

class Stack
{
    Node *head;
    Node *tail;
    int curr_size;

public:
    Stack()
    {
        head = NULL;
        tail = NULL;
        curr_size = 0;
    }

    void push(int data)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
        curr_size++;
    }

    int pop()
    {
        if (curr_size == 0)
            return -1;

        int popped = head->data;
        Node *temp = head->next;
        delete head;
        head = temp;
        curr_size--;
        return popped;
    }

    bool isEmpty()
    {
        return curr_size == 0;
    }

    int top()
    {
        if (isEmpty())
            return -1;

        return head->data;
    }

    int size()
    {
        return curr_size;
    }
};

int main()
{
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.top() << endl;
    cout << s.size() << endl;

    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;

    cout << s.top() << endl;
    cout << s.size() << endl;

    return 0;
}