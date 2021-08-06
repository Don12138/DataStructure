
#include <cstdio>
#include <cstdlib>

void PrintData1(char* a){
    while (*a){
        printf("%c\t",*a);
        a++;
    }
}

void PrintData2(char a[]){
    for (int i = 0; i < 100 && a[i]; ++i) {
        printf("%c\t",a[i]);
    }
}

int main() {
    char s[100];
    s[0] = '1';
    s[1] = 59;
    s[2] = NULL;
    PrintData1(s);
    printf("\n");
    PrintData2(s);
    return 0;
}
