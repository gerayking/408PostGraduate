#include<bits/stdc++.h>
using namespace std;
typedef struct node{
    int Element;
    node* next;
    node(){}
}*LinkList;
void p(LinkList &a){
    printf("a->next : %p\n",a->next);
    printf("a:%p\n",a);
    node *p = a;
    printf("p:%p\n",p);
    a = a->next;
    free(p);
    printf("a:%p\n",a);

}
int main(){
    LinkList first,second,third;
    first = new node();
    second = new node();
    third = new node();
    first->Element=10;
    first->next=second;
    second->Element=9;
    second->next=third;
    third->Element=8;
    third->next=NULL;
    printf("%p %p %p\n",&first,&second,&third);
    p(second);
    printf("%p %p %p\n",&first,first->next,first->next->next);
    printf("%d\n",third->Element);
}