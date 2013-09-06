#include <stdio.h>
#include "chess.h"
#include <time.h>

step get_computer_step(char a[15][15],char player)
{	
	step p;
	srandom(time(NULL));
    int row,col;  
    do
	{
			row=random()%15;
        	col=random()%15;
		
	
    
	}while(a[row][col]>0); 
   
    p.row=row;
	p.col=col;
	p.player=player;

    return p;
}




