#include<bits/stdc++.h>
using namespace std;
typedef struct node{
    char data;
    struct node* next;
}LNode,*Linklist;
Linklist initLinkList(Linklist L){
    string str;
    LNode *p = L;
    cin>>str;
    for(int i=0;i<str.size();i++){
        LNode *s = new node();
        s->data = str[i];
        p->next = s;
        p = p->next;
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
Linklist getsuffix(Linklist L1,Linklist L2){
    int len1 = getlen(L1);
    int len2 = getlen(L2);
    if(len1>=len2){
        int dis = len1-len2;
        while(dis){
            L1=L1->next;
            dis--;
        }
        while(L1->next&&L2->next){
            if(L1->next==L2->next){
                return L1->next;
            }else{
                L1=L1->next;
                L2=L2->next;
            }
        }
    }else{
        int dis = len2-len1;
        while(dis){
            L2=L2->next;
            dis--;
        }
        while(L1->next&&L2->next){
            if(L1->next==L2->next){
                return L1->next;
            }else{
                L1=L1->next;
                L2=L2->next;
            }
        }
    }
    return nullptr;
}
int main(){
//样例比较难造，不写了
}