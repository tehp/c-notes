#include<stdio.h>

int main(void){
    int i, j, p;
    int n = 1000000;
    for(i = 2; i <= n; i++){
        p = 0;
        for(j = 2; j <= i/2; j++){
             if(i % j == 0){
                 p = 1;
                 break;
             }
        }
        if(p==0) {
          printf("\n%d ",i);
        } else {
          printf(".");
        }
    }
   return 0;
}
