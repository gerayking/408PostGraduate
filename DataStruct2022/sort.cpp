//
// Created by Geray on 2021/8/8.
//
#include <bits/stdc++.h>
using namespace std;
template <class ElementType> class SortAlgorithm{
public:
    // 插入排序
    void InsertSort(ElementType A[], int n){
        int i,j;
        for(i=2;i<=n;i++){
            if(A[i]<A[i-1])A[0] = A[i];
            for(j = i - 1;A[0]<A[j];j--)A[j+1]=A[j];
            A[j+1]=A[0];
        }
    }
    // 折半插入排序
    void InsertSortB(ElementType A[],int n){
        int i,j,low,high,mid;
        for(i=2;i<=n;i++){
            A[0] = A[i];
            low = 1, high = i - 1;
            while (low <= high){
                mid = (low+high)/2;
                if(A[mid]<A[0])low = mid + 1;
                else high = mid - 1;
            }
            for(j = i - 1;j>=high + 1;--j)A[j+1]=A[j];
            A[high+1] = A[0];
        }
    }
    // 希尔排序
    void SheelSort(ElementType A[],int n){
        int dk,i,j;
        for(dk = n/2;dk>=1;dk=dk/2){
            for(i = dk+1;i<=n;i++){
                if(A[i]<A[i-dk]){
                    A[0] = A[i];
                    for(j = i-dk;j>0&&A[0]<A[j];j-=dk)A[j+dk]=A[j];
                    A[j+dk]=A[0];
                }
            }
        }
    }
    // 冒泡排序[0,n-1]
    void BubbleSort(ElementType A[], int n){
        int i,j;
        bool flag;
        for(i=0;i<n-1;i++){
            flag = false;
            for(j = n - 1;j>i;j--){
                if(A[j-1]>A[j]){
                    swap(A[j-1],A[j]);
                    flag = true;
                }
            }
            if(!flag)return;
        }
    }
    // 快速排序
    void QuickSort(ElementType A[],int low,int high){
        if (low < high){
            int mid = Partition(A,low,high);
            QuickSort(A,low,mid-1);
            QuickSort(A,mid+1,high);
        }
    }
    int Partition(ElementType A[],int low,int high){
        ElementType pivot = A[low];
        while (low < high){
            while(low<high&&A[high]>=pivot)--high;
            A[low] = A[high];
            while (low<high&&A[low]<=pivot)++low;
            A[high]=A[low];
        }
        A[low]=pivot;
        return low;
    }
    void BuildMaxHeap(ElementType A[], int len){
        for(int i = len/2;i>=0;i--){
            HeapAdjust(A,i,len);
        }
    }
    void HeapAdjust(ElementType A[],int k,int len){
        int i;
        A[0] = A[k];
        for(i=2*k;i<=len;i<<=1){
            if(i<len && A[i] > A[i+1])i++;
            // 取左右子树最大的节点
            if(A[0]<=A[i])break;
            // 如果根节点大于左右子树最大的节点则不管
            else{
                //否则交换
                A[k] = A[i];
                k = i;
            }
        }
        A[k]=A[0];
    }
    void HeapSort(ElementType A[], int len){
        BuildMaxHeap(A,len);
        for(int i=len;i>1;i--){
            swap(A[i],A[1]);
            for(int j = 1; j <= len ; j++){
                printf("%d ",A[j]);
            }
            printf("\n");
            //不断把A[1]最大的出堆
            HeapAdjust(A,1,i-1);
        }

    }
    void Merge(ElementType A[],int low,int mid,int high,int len){
        ElementType *B = (ElementType *)malloc((len+1)*sizeof(ElementType));
        for(int k = low;k<=high;k++){
            B[k]=A[k];
        }
        int i, j,k;
        for(i = low,j = mid +1,k=i;i<=mid&&j<=high;k++){
            if(B[i]<=B[j])A[k]=B[i++];
            else A[k]=B[j++];
        }
        while (i<=mid)A[k++]=B[i++];
        while (j<=high)A[k++]=B[j++];
        delete B;
    }
    void mergeSort(ElementType A[], int low,int high,int len){
        if(low < high){
            int mid = (low + high)/2;
            mergeSort(A,low,mid,len);
            mergeSort(A,mid+1,high,len);
            Merge(A,low,mid,high,len);
        }
    }


};
int main(){
    SortAlgorithm<int>s;
    int v[] = {-1,23,17,72,60,25,8,68,71,52};
    s.mergeSort(v,1,8,8);
    for(int i=1;i<=8;i++){
        printf("%d ", v[i]);
    }
}
