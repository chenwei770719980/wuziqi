#include <stdio.h>
#include "chess.h"

void print_board(char p[15][15])
{
		int i,j=0;
		printf("  "); 
		for(i=0;i<15;i++)
				printf("%2c",i+'A'); 
		printf("\n");
		for(i=0;i<15;i++)
		{
				printf("%2d",i+1);
			
				for(j=0;j<15;j++)
				{
						if( BLACK == p[i][j])
								printf("%2c",'x');
						else if( WHITE == p[i][j])
								printf("%2c",'o');
						else
								printf("%2c",'.');	
				}
				printf("%2d",i+1);
				printf("\n");
		} 
		printf("  "); 
		for(i=0;i<15;i++)
				printf("%2c",i+'A'); 
		printf("\n");
		
} 

