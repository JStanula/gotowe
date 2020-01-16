#include<stdio.h>
#include<stdlib.h>
#include"sortstr.h"

int main(int argc, char **argv){
        char **ar;
        int y;
        printf("how many words do you want in your array?:\n");
        scanf("%d", &y);
        ar=malloc(y*sizeof(char*));
        for(int i=0; i<y; i++)
                *(ar+i)=malloc(sizeof(char));
        printf("\nfill the array\n");
        for(int z=0; z<y; z++)
                scanf("%s", *(ar+z));
        printf("\nthere are your words\n");
        for(int k=0; k<y; k++)
                printf("%s\n", *(ar+k));
        sortstr(ar, y);
        printf("\n array after sorting:\n");
        for(int l=0; l<y; l++)
                printf("%s\n", *(ar+l));
        for(int u=0; u<y; u++)
                free(*(ar+u));
        free(ar);
        return 0;
}
