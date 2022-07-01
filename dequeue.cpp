#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

class dequeue
{
    Node *head;
    Node *tail;

    int size;
    int capacity;

public:
    dequeue()
    {
        head = NULL;
        tail = NULL;
        size = 0;
        capacity = 10;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void insertFront(int data)
    {
        if (head == NULL)
        {
            Node *newNode = new Node(data);
            head = newNode;
            tail = newNode;
        }
        else
        {
            Node *newNode = new Node(data);
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    int deleteFront()
    {
        if (isEmpty())
        {
            cout << "dequeue is empty" << endl;
            return -1;
        }

        int ans = head->data;
        Node *temp = head->next;
        delete head;
        head = temp;
        head->prev = NULL;
        size--;
        return ans;
    }

    void insertRear(int data)
    {
        if (tail == NULL)
        {
            Node *newNode = new Node(data);
            head = newNode;
            tail = newNode;
        }
        else
        {
            Node *newNode = new Node(data);
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    int deleteRear()
    {
        if (isEmpty())
        {
            cout << "dequeue is empty" << endl;
            return -1;
        }

        int ans = tail->data;
        Node *temp = tail->prev;
        delete tail;
        tail = temp;
        tail->next = NULL;
        size--;
        return ans;
    }

    int front()
    {
        if (isEmpty())
        {
            cout << "dequeue is empty" << endl;
            return -1;
        }

        return head->data;
    }

    int rear()
    {
        if (isEmpty())
        {
            cout << "dequeue is empty" << endl;
            return -1;
        }

        return tail->data;
    }
};

int main()
{
    dequeue dq;

    cout << dq.getSize() << endl;

    dq.insertFront(10);
    dq.insertFront(20);

    dq.insertRear(30);
    dq.insertRear(40);

    cout << dq.front() << endl;
    cout << dq.rear() << endl;

    dq.deleteFront();
    dq.deleteRear();

    cout << dq.front() << endl;
    cout << dq.rear() << endl;

    return 0;
}