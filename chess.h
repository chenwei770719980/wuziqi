#ifndef __CHESS_H_
#define __CHESS_H_

#ifdef __cplusplus
extern "C" {
#endif

/*han shu sheng ming*/

#define BLACK 1
#define WHITE 2
#define NOTHING 0
#define WINNER 1
#define VALIDE(row,col) (((row)<15&&(row)>=0&&(col)<15&&(col)>=0)?1:0)
#define UP -1
#define DOWN 1
#define LETF -1
#define RIGHT 1
#define NOTMOVE 0

void print_board(char board[15][15]);
struct step1
	{
		char player ;
        char row ;
        char col ; 
    };

typedef struct step1 step; 


//电脑随机数，人键盘接收。
step get_computer_step(char a[15][15],char player);  
step get_input_step(char a[15][15],char player);
//判断2函数。
int pan_duan(char board[15][15],step* n); 
int func(char board[15][15],step*n,int*count,int panyi[2]);
//电脑智能化。
step ai(char board[15][15],int player,int comp[15][15],int user[15][15]);
step ten(int comp[15][15],int user[15][15]);
void run(char board[15][15],int s[15][15],int player);
void shuzu(char board[15][15],int player,int row,int col,int c[4]);
int pinfen(int c);
int sum(int c[4]);
int max(int a[15][15]);	

#ifdef __cplusplus
}
#endif
#endif /*__CHESS_H*/
