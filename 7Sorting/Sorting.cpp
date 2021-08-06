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
int main(){
    int array[MAX_NUM];
    int length = 20;
    GetArray(array,length);
    StraightInsertionSorting(array,length);
    Print(array);
    return 0;
}