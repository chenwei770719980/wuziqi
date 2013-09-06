#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "chess.h"

step get_input_step(char a[15][15],char player)
{
	step s;
    int irow,icol;
	char zuobiao[10]={'\0'};
	char crow[3]={'\0'};
    do
	{
		printf("qing jian pan shu ru.\n");
		fgets(zuobiao,9,stdin);
	
		icol =  zuobiao[0]-'a';
		memset(crow,'\0',3);
		strncpy(crow,zuobiao+1,2);
		irow = atoi(crow)-1;

	}while(a[irow][icol]>0);
    s.row=irow;
    s.col=icol;
    s.player=player; 
	return s;
}
