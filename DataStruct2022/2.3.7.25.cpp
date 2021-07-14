#include<bits/stdc++.h>
using namespace std;
typedef struct node{
    int data;
    struct node* next;
}LNode,*Linklist;
void print(Linklist L1){
    LNode *p = L1->next;
    while(p){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}
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
int getlen(Linklist L1){
    int len = 0;
    while(L1->next){
        len++;
        L1=L1->next;
    }
    return len;
}
void reverseLinkListFromHeadToP(Linklist head,Linklist p){
    LNode *s = head->next;
    head->next = nullptr;
    LNode *e = p->next;
    while(s!=e){
        LNode *tmp = s->next;
        s->next = head->next;
        head->next = s;
        s = tmp;
    }
}
Linklist getItem(Linklist L,int index){
    while(index--){
        L=L->next;
    }
    return L;
}
Linklist insertNode(Linklist L,Linklist p){
    LNode *tmp = p->next;
    p->next=L->next;
    L->next=p;
    return tmp;
}
void repermutationLinkList(Linklist L1){
    int len = getlen(L1);
    LNode *m = getItem(L1,len/2);
    LNode *t = getItem(L1,len);
    reverseLinkListFromHeadToP(m,t);
    print(L1);
    LNode *head = L1->next;
    LNode *mid = getItem(L1,len/2)->next;
    LNode *p = L1;
    L1->next = nullptr;
    while(head&&mid){
        head = insertNode(p,head);
        p = p->next;
        mid = insertNode(p,mid);
        p=p->next;
    }
    if(mid)insertNode(p,mid);
}
int main(){
    Linklist L1 = new LNode();
    initLinkList(L1);
    print(L1);
    repermutationLinkList(L1);
    print(L1);

}
/*
 * 1 2 3 4 5 6 9999
 *
 * */

