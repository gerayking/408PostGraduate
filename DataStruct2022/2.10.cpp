#include<bits/stdc++.h>
using namespace std;
int r[1000];
void reverse(int left,int right){
    int i = left, j = right;
    while(i<j){
        swap(r[i],r[j]);
        i++;
        j--;
    }
}
int main(){
    int n,p;
    scanf("%d %d",&n,&p);
    for(int i=0;i<n;i++)r[i]=i;
    reverse(0,n-1);
    reverse(0,n-p-1);
    reverse(n-p,n-1);
    for(int i=0;i<n;i++)printf("%d ",r[i]);
}