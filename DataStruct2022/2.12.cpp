#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[1000];
int findMainElenment(int *A,int n){
    int cur=-1, cal = 0;
    for(int i=0;i<n;i++){
        if(cur==-1){
            cur = A[i];
            cal = 1;
        }else{
            if(cur == A[i])cal++;
            else{
                cal--;
                if(cal==0){
                    cur = A[i];
                    cal = 1;
                }
            }
        }
    }
    if(cal>1)return cur;
    else return -1;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("%d\n",findMainElenment(a,n));
}