#include <stdio.h>
#include "chess.h"

int pan_duan(char board[15][15],step* n)
{
	int count=1;
	int a[8][2]={{UP,NOTMOVE},{DOWN,NOTMOVE}
		,{NOTMOVE,LETF},{NOTMOVE,RIGHT}
		,{UP,LETF},{DOWN,RIGHT}
		,{UP,RIGHT},{DOWN,LETF}};
		int i;
		for(i=0;i<4;i++)
		{
			count=1;
			func(board,n,&count,a[2*i]);
			func(board,n,&count,a[2*i+1]);
			if(count>=5)
			 return WINNER;

		}
		return 0;
}
 int func(char board[15][15],step* n,int*count,int panyi[2])
{
	int player,col,row;
	row=n->row;
	col=n->col;
	player=n->player;
	while(1)
	{
		row=row+panyi[0];
		col=col+panyi[1];
		if(VALIDE(row,col)&&board[row][col]==player)
			(*count)++;
		else
			break;
	}

}
