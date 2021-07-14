#include<bits/stdc++.h>
using namespace std;
int s1[1000];
int s2[1000];
int getMiddle(int *a,int *b,int L){
    int index = 0;
    int aindex = 0;
    int bindex = 0;
    while(index < L){
        if(bindex<L&&a[aindex]>=b[bindex]){
            bindex++;
        }else{
            aindex++;
        }
        index++;
        if(index+1==L){
            return min(a[aindex],b[bindex]);
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    srand(time(0));
    for(int i=0;i<n;i++){
        s1[i]=rand()%10000;
        s2[i]=rand()%10000;
    }
    sort(s1,s1+n);
    sort(s2,s2+n);
    for(int i=0;i<n;i++){
        printf("%d ",s1[i]);
    }
    puts("");
    for(int i=0;i<n;i++){
        printf("%d ",s2[i]);
    }
    printf("\n%d",getMiddle(s1,s2,n));
}