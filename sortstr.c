void sortstr(char **x, int size){
        char *tmp2;
        int i,j;
        for(i=1; i<size; i++){
                tmp2=*(x+i);
                j=i-1;
                while(j>=0&&strcmp(x[j], tmp2)>0){
                        *(x+j+1)=*(x+j);
                        j=j-1;
                }
                *(x+j+1)=tmp2;
        }
}
