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
int kreverse(Linklist L,int k){
    int cal = 0;
    LNode *ans,*p;
    p = L;
    while(p->next!= nullptr){
        cal++;
        p=p->next;
        if(cal==k){
            ans=L->next;
        }else if(cal>k){
            ans=ans->next;
        }
    }
    if(ans)return ans->data;
    return 0;
}
int main(){
    Linklist L;
    L = new node();
    initLinkList(L);
    printf("\n");
    int k;
    scanf("%d",&k);
    printf("%d\n",kreverse(L,k));
}
