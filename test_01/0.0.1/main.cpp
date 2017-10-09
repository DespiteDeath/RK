#include <iostream>
#include <cstdlib>

struct Node
{
    int data;
    Node* next;
};

Node * reverse(Node * head)
{
    if(head == nullptr)
        return head;

    Node * phead = nullptr;

    while(head != nullptr)
    {
        Node * p = head -> next;
        head -> next = phead;
        phead = head;
        head = p;
    }

    return phead;
}

int main()
{
    return 0;
}