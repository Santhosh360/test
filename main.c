#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void funcA(){
    char *p = malloc(30*sizeof(char));
    strcpy(p,"Apple");
    printf("%s\n",p);
    free(p);
}

void funcB(){
    char *p = malloc(20*sizeof(char));
    char *q = calloc(10,sizeof(char));
    strcpy(p,"Ape");
    printf("%s\n",p);
    free(q);
}

int main(){
    int **p = (int **)calloc(5,sizeof(int*));
    for(int i=0;i<5;i++){
        *(p+i) = (int*)calloc(5,sizeof(int));	
    }
    *(p+0) = realloc(*(p+0),5*sizeof(int));
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            *(*(p+i)+j)=i;
        }
    }
    funcA();
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            printf("%d\t",*(*(p+i)+j));
        }
        printf("\n");
    }
    for(int i=0;i<5;i++){
        free(*(p+i));
    }
    free(p);
    funcB();
    funcA();
    return 0;
}
