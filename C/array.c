#include<stdio.h>
int main(){
    int i,j, a[3][3];
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("[+]Enter value at [%d][%d] >>> ",i,j);
            scanf("%d",&a[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%d  ", a[i][j]);
        }
        printf("\n");
    }
}
