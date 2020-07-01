#include<stdlib.h>
#include"Prerequisites.h"

LL* Insert(LL* head, string N, double A, double T, int M)
{
    LL * node = new LL;
    node->name = N;
    node->acc = A;
    node->time = T;
    node->menu = M;
    node->next = NULL;
    if(head == NULL) node->next = NULL;
    else
    {
        node->next = head;
    }
    head = node;
    return head;
}

LL * Delete(LL* head, string N)
{
    LL * node = new LL;
    node = Search(head, N);
    if(node == NULL)
    {
        cout<<"Record not found";
        return head;
    }
    LL * temp1 = node->next;
    temp1->next = node->next;
    delete temp1;
    return head;
}

LL * Search(LL* head, string N)
{
    LL* p = NULL;
    p = head;
    while(p != NULL)
    {
        if((p->next)->name == N)
            return p;
        p = p->next;
    }
    return NULL;
}
