#include <cstdio>
#include <algorithm>
#define MAX_SIZE 255
typedef struct {
    char ch[MAX_SIZE];
    int length;
}SString;

void Init_String(SString &s){
    s.length = 0;
}
void Insert_String(SString &s,int a){
    s.ch[++s.length] = a;
}
void get_next(SString T,int next[]){
    int i = 1,j=0;
    next[1] = 0;
    while (i<T.length){
        if (j==0||T.ch[i] == T.ch[j]){
            i++;j++;
            next[i] = j;
        } else{
            j = next[i];
        }
    }
}

void get_nextval(SString T){
    int i = 1,j=0;
    int nextval[T.length+1];
    nextval[1] = 0;
    while (i<T.length){
        if (j==0||T.ch[i] == T.ch[j]){
            i++;j++;
            if (T.ch[i]!=T.ch[j])
                nextval[i] = j;
            else
                nextval[i] = nextval[j];
        } else{
            j = nextval[j];
        }
    }
    for (int k = 0; k < T.length; ++k) {
        printf("%d\t",nextval[k]);
    }
}
int get_index(SString S,SString T,int next[]){
    int i = 1 ,j = 1;
    while (i<=S.length&&j<=T.length){
        if (S.ch[i] == T.ch[j]){
            i++;
            j++;
        } else{
            j = next[j];
        }
    }
    if (j > T.length)
        return i-T.length;
    else return 0;
}
int main(){
    SString S = *(SString*)malloc(sizeof (SString));
    SString T = *(SString*)malloc(sizeof (SString));
    Init_String(S);
    Init_String(T);
    Insert_String(T,'a');
    Insert_String(T,'b');
    Insert_String(T,'a');
    Insert_String(T,'a');
    Insert_String(T,'b');
    Insert_String(T,'c');
    printf("%d",T.length);
    get_nextval(T);
    return 0;
}
