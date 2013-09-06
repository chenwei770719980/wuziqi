#include <stdio.h>
#include "chess.h"



int main()
{
		int iwinner;
		char board[15][15]={0};
		int comp[15][15]={0};
		int user[15][15]={0};

		step p1,p2,n;

		print_board(board);


		int count = 0;
		while(1)
		{

				if(count>=225)
				{
						break;
				}

				p1=get_input_step(board,WHITE);
				printf(">>>>>>>>>>>>>>>>>>>>>>>>>>\n");
				//p1=ten(board,BLACK);	
				board[p1.row][p1.col]=p1.player;
				print_board(board);
				count++;
				iwinner=pan_duan(board,&p1);
				if(1==iwinner)
				{
						printf("computer winner!\n");
						break;

				}
				if(count>=225)
				{
						break;
				}
				p2=ai(board,BLACK,comp,user);
				board[p2.row][p2.col]=p2.player;
				count++;
				iwinner=pan_duan(board,&p2);
				print_board(board);
				if(1==iwinner)
				{
						printf("you winner!\n");
						break;

				}
				printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
				printf("step.player.conputer=%d\n",(int)p2.player);
				printf("step.row=%d\n",(int)p2.row);
				printf("step.col=%d\n",(int)p2.col);

				printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
				printf("step.player.user=%d\n",(int)p1.player);
				printf("step.row=%d\n",(int)p1.row);
				printf("step.col=%d\n",(int)p1.col);

				
		}

		return 0;
}
