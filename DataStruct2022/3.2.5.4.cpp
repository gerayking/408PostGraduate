#include<bits/stdc++.h>
using namespace std;
template<class ElementType> class Node{
public:
    ElementType data;
    Node *next;
    Node() {
        next = nullptr;
    }
    Node(ElementType data, Node *next) : data(data), next(next) {}

};

template<class ElementType> class Queue{
private:
    Node<ElementType> *front,*rear;
    bool fulltag;
public:
    Queue() {
        front = new Node<ElementType>();
        front->next = rear;
        rear = front;
    }
    bool Enqueue(ElementType data){
        if(is_empty()){
            // 队空
            Node<ElementType>* p = new Node<ElementType>(data, nullptr);
            front->next = p;
            p->next = front;
            rear = p;
        }
        else if(is_full()){
            // 队满
            Node<ElementType>* p = new Node<ElementType>(data, nullptr);
            rear->next = p;
            p->next = front;
            rear = p;
        }else{
            rear=rear->next;
            rear->data = data;
        }
    }
    ElementType Dequeue(){
        if(is_empty())return NULL;
        ElementType r = front->next->data;
        front = front->next;
        if(front==rear->next)fulltag=1;
        return r;

    }
    bool is_empty(){
        return front == rear;
    }
    bool is_full(){
        return rear->next = front;
    }
};
int main(){
    Queue<int>q;
    for(int i=10;i<20;i++)q.Enqueue(i);
    for(int i=10;i<20;i++)printf("%d\n",q.Dequeue());
}