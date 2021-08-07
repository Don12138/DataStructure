#include <cstdio>
#include <cstdlib>
#define MAX_NUM 100

void GetArray(int* array,int length){
    int cur[MAX_NUM] = {13,6,3,19,15,1,7,5,18,2,14,11,17,20,4,16,8,12,10,9};
    for (int i = 0; i <= length; ++i) {
        *(++array) = *(cur+i);
    }
}
void Print(int* a){
    a++;
    while (*a){
        printf("%d\t",*a);
        a++;
    }
    printf("\n");
}
void StraightInsertionSorting(int* a,int length){
    for (int i = 2; i <= length; ++i) {
        if (*(a+i)<*(a+i-1)){
            *a = *(a+i);
            int j;
            for (j = i; *a < *(a+j-1) ; --j)
                *(a+j) = *(a+j-1);
            *(a+j) = *a;
        }
    }
}
void BinaryInsertionSorting(int *a,int length){
    for (int i = 2; i <= length; ++i) {
        if (*(a+i)<*(a+i-1)){
            int low = 1,high = i-1;
            *a = *(a+i);
            while (low <= high){
                int mid = (low+high)/2;
                if (*a < *(a+mid))
                    high = mid-1;
                else low = mid+1;
            }
            for (int j = i; j >= high+2; --j)
                *(a+j) = *(a+j-1);
            *(a+high+1) = *a;
        }
    }
}
void ShellInsert(int* a,int length,int dk){
    for (int i = 1+dk; i <= length; ++i) {
        if (*(a+i)<*(a+i-dk)){
            *a = *(a+i);
            int j;
            for (j = i; j > dk && *(a)<*(a+j-dk); j-=dk)
                *(a+j) = *(a+j-dk);
            *(a+j) = *a;
        }
    }
}
void ShellSorting(int* a,int length,int* dt,int t){
    for (int i = 0; i < t; ++i) {
        ShellInsert(a,length,*(dt+i));
    }
}
void BubbleSort(int* a,int length){
    bool isDone = false;
    int count = 0;
    while (!isDone){
        count++;
        isDone = true;
        for (int i = length; i >count ; --i) {
            if (*(a+i)<*(a+i-1)){
                isDone = false;
                int cur = *(a+i);
                *(a+i) = *(a+i-1);
                *(a+i-1) = cur;
            }
        }
    }
}
void Partition(int *a,int low,int high){
    *a = *(a+low);
    int oriLow = low,oriHigh = high;
    if (low > high)return;
    while (low<high){
        if (low<high&&*(a+high)>=*a)high--;
        *(a+low) = *(a+high);
        if (low<high&&*(a+low)<=*a)low++;
        *(a+high) = *(a+low);
    }
    *(a+low) = *a;
    Partition(a,oriLow,low-1);
    Partition(a,low+1,oriHigh);
}
void QuickSorting(int* a,int length){
    Partition(a,1,length);
}
void SimpleSelectionSorting(int *a,int length){
    for (int i = 1; i <= length; ++i) {
        int minIndex = i;
        for (int j = i; j <= length; ++j) {
            if (*(a+j)<*(a+minIndex))
                minIndex = j;
        }
        *a = *(a+minIndex);
        *(a+minIndex) = *(a+i);
        *(a+i) = *a;
    }
}
void AdjustHeap(int *a,int start,int end){
    *a = *(a+start);
    for (int i = 2*start; i <= end ; i*=2) {
        if (i<end&&*(a+i+1)>*(a+i))i++;
        if (*(a+i)<=*a)break;
        *(a+start) = *(a+i);
        start = i;
    }
    *(a+start) = *a;
}
void CreatHeap(int *a,int length){
    for (int i = length/2; i >=1 ; --i)
        AdjustHeap(a,i,length);
}
void HeapSorting(int *a,int length){
    CreatHeap(a,length);
    for (int i = length; i > 1; --i) {
        *a = *(a+i);
        *(a+i) = *(a+1);
        *(a+1) = *a;
        AdjustHeap(a,1,i-1);
    }
}
void Merge(int* a,int low,int mid,int high,int length){
    int* b = (int*)malloc(sizeof (int)*length);
    for (int i = low; i <= high; ++i)
        *(b+i) = *(a+i);
    int i, j, k;
    for (i = low,j = mid+1 ,k = low; i <= mid && j<=high ; k++) {
        if (*(b+i)<=*(b+j))
            *(a+k) = *(b+i++);
        else
            *(a+k) = *(b+j++);
    }
    while (i<=mid)*(a+k++) = *(b+i++);
    while (j<=high)*(a+k++) = *(b+j++);
}
void MergeSort(int *a,int length,int low,int high){
    if (low<high){
        int mid = (low+high)/2;
        MergeSort(a,length,low,mid);
        MergeSort(a,length,mid+1,high);
        Merge(a,low,mid,high,length);
    }
}
int main(){
    int array[MAX_NUM];
    int length = 20;
    GetArray(array,length);
    Print(array);
    StraightInsertionSorting(array,length);
    Print(array);

    GetArray(array,length);
    BinaryInsertionSorting(array,length);
    Print(array);

    GetArray(array,length);
    int dt[4] = {7,5,3,1};
    ShellSorting(array,length,dt,4);
    Print(array);

    GetArray(array,length);
    BubbleSort(array,length);
    Print(array);

    GetArray(array,length);
    QuickSorting(array,length);
    Print(array);

    GetArray(array,length);
    SimpleSelectionSorting(array,length);
    Print(array);

    GetArray(array,length);
    HeapSorting(array,length);
    Print(array);

    GetArray(array,length);
    MergeSort(array,length,1,length);
    Print(array);
    return 0;
}