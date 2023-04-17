#include <stdio.h>
int main(){
    int val = 0;
    switch(val){
        default :
        val++;
        case 1:
        printf("Hi\n");
        case 2:
        printf("Hello\n");
    }
    printf("%d",val);
}