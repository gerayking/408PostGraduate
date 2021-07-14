#include<bits/stdc++.h>
using namespace std;
typedef struct node{
    int data;
    struct node* next;
}LNode,*Linklist;
Linklist initLinkList(Linklist L){
    int x;
    LNode *p = L;
    scanf("%d",&x);
    while(x!=9999){
        LNode *s = new node();
        s->data = x;
        p->next = s;
        p = p->next;
        scanf("%d",&x);
    }
    return L;
}
bool iscircle(Linklist L1){
    LNode *fast,*low;
    fast=L1->next;
    low = L1->next;
    while(fast->next->next!= nullptr&&fast!=low){
        fast = fast->next->next;
        low = low->next;
    }
    LNode *p1 = L1->next;
    LNode *p2 = low;
    while(p1!=p2){
        p1=p1->next;
        p2=p2->next;
    }
}
int main(){

}

