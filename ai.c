#include <stdio.h>
#include "chess.h"

int tag=0;
step ai(char board[15][15],int player,int comp[15][15],int user[15][15])
{						//设2个数组存电脑人的比分情况，判断谁先下。		
		int i=0;int j=0;
		int row,col;
		int maxcomputer=0;
		int maxuser=0;
		step n;
		col=n.col;
		row=n.row;
		player=n.player;
		
		
		int c[4]={0};
		step p;
		

		run(board,comp,BLACK);
		printf("is computer\n");
		
		for(row=0;row<15;row++)
		{
				for(col=0;col<15;col++)
				{
					printf("%3d",comp[row][col]);
						
				}
			printf("\n");
		}
		
printf(">>>>>>>>>>>>>>>>>>>>>>>>>>\n");
		printf("is user\n");
		run(board,user,WHITE);
			
		for(row=0;row<15;row++)
		{
				for(col=0;col<15;col++)
				{
					printf("%3d",user[row][col]);
						
				}
			printf("\n");
		}
		
	
		p=ten(comp,user);
		return p;	
}	
step ten(int comp[15][15],int user[15][15])
{		
		step one;					//判断了谁先下，进行落子。
		int row,col,player;
		int i,j,k;
		int count1,count2,count3,count4;
		
		
		int max,max1;
		max=0;max1=0;
		for(i=0;i<15;i++)
		{
			for(j=0;j<15;j++)
			{
				
				if(comp[i][j]>max)
				{
					max=comp[i][j];	
					count1=i;
					count2=j;
				}        		
			}		
		}	
		for(row=0;row<15;row++)
		{
			for(col=0;col<15;col++)
			{
				
				if(user[row][col]>max1)
				{
					max1=user[row][col];
					count3=row;	
					count4=col;			
				}
			}		
		}	
		if(max>=max1)
		{
			one.row=count1;
			one.col=count2;
			one.player=BLACK;	
		}
		else
		{
			one.row=count3;
			one.col=count4;
			one.player=BLACK;
		}			
				
		return one;
}
void run(char board[15][15],int s[15][15],int player)
{				//遍历棋盘没子的点4个方向的打分情况，到数组中。
		int col,col1;
		int row,row1,max;
		int i,j,l,k;
		int c[4]={0};
		int count1,count2,count3,count4;
	//	step n;
	//	col=n.col;
	//	row=n.row;
	//	player=n.player;
		for(row=0;row<15;row++)
		{
			for(col=0;col<15;col++)
			{
				s[row][col]=0;	
			}
		}
		
		for(row=0;row<15;row++)
		{  
			for(col=0;col<15;col++)
			{
				if(NOTHING==board[row][col])
				{	//printf("row=%d, col=%d,player=%d",)
					row1=row;col1=col;
					i=0;j=1;count1=0;
					while(player==board[row+i][col+j])//向右边走
					{	
						if((col+j)>14)
							break;
						  j++; count1++;  
					}
					row=row1;col=col1;
					i=0;j=-1;
					while(player==board[row+i][col+j])//向左边走
					{	
						if((col+j)<0)
							break;
						 j--; count1++;  //count1累加2次
					}
					row=row1;col=col1;
					i=-1;j=0;count2=0;
					while(player==board[row+i][col+j])//向上走
					{	
						if((row+i)<0)
							break;
						i--;count2++;    
					}
					row=row1;col=col1;
					i=1;j=0;
					while(player==board[row+i][col+j])//向下走
					{	
						if((row+i)>14)
							break;
						  i++; count2++; //count2累加2次 
					}
					row=row1;col=col1;
					i=-1;j=1;count3=0;
					while(player==board[row+i][col+j])//向右上走
					{	
						if( ((col+j)>14)||((row+i)<0) )
							break;
						  i--;j++; count3++;  
					}
					row=row1;col=col1;
					i=1;j=-1;
					while(player==board[row+i][col+j])//向左下走
					{	
						if( ((col+j)<0)||((row+i)>14) )
							break;
						  i++;j--; count3++;  //count3累加2次
					}
					row=row1;col=col1;
					i=1;j=1;count4=0;
					while(player==board[row+i][col+j])
					{	
						if( ((col+j)>14)||((row+i)>14) )
							break;
						  i++;j++; count4++;  
					}
					row=row1;col=col1;
					i=-1;j=-1;
					while(player==board[row+i][col+j])
					{	
						if( ((col+j)<0)||((row+i)<0) )
							break;
						  i--;j--; count4++;  
					}
#if 0	
					max = count1;
				if(max < count2)
					max = count2;
				if(max < count3)
					max = count3;
				if(max < count4)
					max = count4;
				//	printf("\n");
				//printf("%d",max);
				//printf("\n");
#endif
				count1=pinfen(count1);
				count2=pinfen(count2);
				count3=pinfen(count3);
				count4=pinfen(count4); 
				max=count1+count2+count3+count4;
				s[row][col] = max; 
				count1 = 0;count2 = 0;count3 = 0;count4 = 0;
				max = 0;

						

					
				}
			}
		}	
			
}

int pinfen(int c)
{				//打分赋值。
		int score0=0;
		int score1=10;
		int score2=30;
		int score3=60;
		int score4=100;
		int score5=1000;
			
		
		
		
				if(c==0)				
						c=score0;//没子0分
				else if(c==1)
						c=score1;//1个子10分
				else if(c==2)
						c=score2;//2个子30分
				else if(c==3)
						c=score3;//3个子60分
				else if(c==4)
						c=score4;//4个子100分
				else if(c==5)
					
						c=score5;//5个子1000分
				else
				return 0;
				
				
}

int sum(int c[4])
{				//对一唯数组求和。
		int i=0;int sum=0;
		for(i=0;i<4;i++)
		{
				sum+=c[i];
		}
		return sum;	
}
#if 0
int max(int a[15][15])
{				//对二唯数组求最大值。
		int i,j;
		int temp;
		int max=0;
		for(i=0;i<15;i++)
		{
				for(j=0;j<15;j++)
						if(max<a[i][j])
						{
								temp=max;
								max=a[i][j];
								a[i][j]=temp;
						}
		}		
		return max;
}
#endif
