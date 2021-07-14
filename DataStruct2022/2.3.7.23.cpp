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
const int N = 1e5+10;
bool vis[N];
void dele_X_abs(Linklist L){
    LNode *p = L->next,*pre = L;
    while(p){
        if((p->data<0&&vis[-(p->data)])||(p->data>=0&&vis[p->data])){
            pre->next = p->next;
            free(p);
            p=pre->next;
        }else{
            if(p->data>0)vis[p->data]=1;
            else vis[-(p->data)]=1;
            pre = p;
            p=p->next;
        }
    }
}
void print(Linklist L1){
    LNode *p = L1->next;
    while(p){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}
int main(){
    Linklist L1 = new LNode();
    initLinkList(L1);
    print(L1);
    dele_X_abs(L1);
    print(L1);
}

/*
 *  data
 *  21 -15 -15 -7 15 9999
 * */
