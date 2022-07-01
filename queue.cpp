#include <iostream>
using namespace std;

template <typename T>

class Node
{
public:
    T data;
    Node *next;

    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};

template <typename T>

class Queue
{
    Node<T> *head;
    Node<T> *tail;
    int size;
    int capacity;

public:
    Queue(int capacity)
    {
        this->capacity = capacity;
        head = NULL;
        tail = NULL;
        size = 0;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    int getSize()
    {
        return size;
    }

    void enqueue(T data)
    {
        if (size == capacity)
        {
            cout << "queue is full" << endl;
            return;
        }

        Node<T> *newNode = new Node<T>(data);

        if (head == NULL && tail == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        size++;
    }

    T dequeue()
    {
        if (isEmpty())
        {
            cout << "queue is empty" << endl;
            return -1;
        }

        Node<T> *temp = head->next;
        T popped = head->data;
        delete head;
        head = temp;
        size--;
        return popped;
    }

    T front()
    {
        if (isEmpty())
        {
            cout << "queue is empty" << endl;
            return -1;
        }
        return head->data;
    }
};

int main()
{
    Queue<int> q(5);

    cout << q.getSize() << endl;
    cout << q.front() << endl;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);

    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    cout << q.getSize() << endl;
    cout << q.front() << endl;

    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    return 0;
}