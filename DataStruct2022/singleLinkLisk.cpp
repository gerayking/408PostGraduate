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
}//
// Created by Geray on 2021/7/14.
//

