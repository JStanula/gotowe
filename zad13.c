#include <stdio.h>
#include "days.h"
#include "days.c"

int main(){

printf("Podaj pierwsza date w formacie dd mm yyyy:\n");
scanf("%d%d%d",&X.day,&X.month,&X.year);
printf("Podaj druga date w formacie dd mm yyyy:\n");
scanf("%d%d%d",&Y.day,&Y.month,&Y.year);
printf("Liczba dni pomiedzy nimi=%d\n",days(X,Y));

return 0;
}
