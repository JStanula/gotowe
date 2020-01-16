#include <stdio.h>
#include "days.h"

int days(struct DAY X, struct DAY Y){
        long int n1=X.day + X.year*365;
        long int n2=Y.day + Y.year*365;

        int miesiace[12]={31,28,31,30,31,30,31,31,30,31,30,31};
        int lprzestepne(int y,int m,int d){
                if(m<=2){
                        y--;
                        }
                return(y/ 4-y/ 100+y/ 400);
                }

        int sumaDni(int a){
                int suma=0;
                for(int i=0;i<a-1;i++){
                        suma+=miesiace[i];
                }
                return(suma);
        }

        n1+=sumaDni(X.month)+lprzestepne(X.year,X.month,X.day);
        n2+=sumaDni(Y.month)+lprzestepne(Y.year,Y.month,Y.day);

        if(n2-n1<0){
                    return(n1-n2);
                   }
        return (n2-n1);
}
