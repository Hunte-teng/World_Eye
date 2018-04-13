#include<iostream>
using namespace std;
#include <stdlib.h>
class CGobang		//棋子类
{
private:
			char chSort;					//棋子的类别
			int nWin;						//赢棋的次数
			int nLose;					    //输棋的次数
			static int nDraw;				//平局次数
            static char achBoard[5][5];		//棋盘
			static int nSize;				//棋盘的尺寸nSize×nSize
			static int sum;                 //统计走了多少步棋
public:
			CGobang(char chsort);			//构造函数，决定一方棋子的类别
			void PlayTurn(void);			//走一步棋
			int Judge();					//判断是否连成一线，是返回1，否返回0
			void Win(void);				    //赢棋
			void Lose(void);				//输棋
			static void Draw(void);			//平局
			void PrintInfo(void);			//打印总体情况
			static void PrintBoard(void);	//打印棋盘
			static int GetFull(void);		//判断棋盘是否已布满棋子
			static void InitialBoard(void);	//初始化棋盘
};
char CGobang::achBoard[5][5];
int CGobang::nSize=5;
int CGobang::nDraw=0;
int CGobang::sum=0;

CGobang::CGobang(char chsort)
{
	chSort=chsort;
	nWin=0;
	nLose=0;
}

void CGobang::Win(void)
{
	cout<<endl<<endl<<"\t\t   "<<chSort<<"获胜！"<<endl;
	nWin++;
}

void CGobang::Lose(void)
{
	cout<<endl<<endl<<"\t\t   "<<chSort<<"获胜！"<<endl;
	nLose++;
}

void CGobang::Draw()
{
	cout<<endl<<endl<<"\t\t   "<<"平局"<<endl;
	nDraw++;
}

void CGobang::InitialBoard(void)//初始化棋盘
{
	for(int i=0;i<nSize;i++)
		for(int j=0;j<nSize;j++)
			achBoard[i][j]=' ';
}

void CGobang::PrintBoard(void)//打印棋盘
{
	cout << endl;
	cout << "\t  1   2   3   4   5 " << endl;
	cout << "\t1 " << achBoard[0][0] << " | " << achBoard[0][1]<<" | "<< achBoard[0][2]<<" | "<< achBoard[0][3]<<" | "<< achBoard[0][4]<< endl;
	cout << "\t ---|---|---|---|---" << endl;;
	cout << "\t2 " << achBoard[1][0]<< " | " << achBoard[1][1]<< " | " << achBoard[1][2]<<" | "<< achBoard[1][3]<<" | "<< achBoard[1][4]<< endl;
	cout << "\t ---|---|---|---|---" << endl;
	cout << "\t3 " << achBoard[2][0]<< " | " << achBoard[2][1]<< " | " << achBoard[2][2]<<" | "<< achBoard[2][3]<<" | "<< achBoard[2][4]<< endl;
	cout << "\t ---|---|---|---|---" << endl;
	cout << "\t4 " << achBoard[3][0]<< " | " << achBoard[3][1]<< " | " << achBoard[3][2]<<" | "<< achBoard[3][3]<<" | "<< achBoard[3][4]<< endl;
	cout << "\t ---|---|---|---|---" << endl;
	cout << "\t5 " << achBoard[4][0]<< " | " << achBoard[4][1]<< " | " << achBoard[4][2]<<" | "<< achBoard[4][3]<<" | "<< achBoard[4][4]<< endl;
	cout << endl;
	cout << endl;
}

void CGobang::PlayTurn(void)
{
	int x,y;
	do
	{
		cout<<"\t轮到"<<chSort<<"出棋"<<endl;
		cout << "\tRow: ";
	    cin  >> x;
	    cout << "\tColumn: ";
	    cin  >> y;
	    if(x>nSize||y>nSize)
			cout<<"\t越界！请重新输入："<<endl;
		else if(achBoard[x-1][y-1]!=' ')
			cout<<"\t该点已有值！请重新输入："<<endl;
		else
		{
			achBoard[x-1][y-1]=chSort;
			break;
		}
	}while(1);
	sum++;
}

void CGobang::PrintInfo(void)//打印总体情况
{
	cout <<"\t"<<chSort<<"方：赢"<<nWin<<" 局，输 "<<nLose <<" 局，平 "<<nDraw<<" 局。"<<endl; 
}

int CGobang::Judge(void)//判断是否连成一线，是返回1，否返回0
{
	if ((achBoard[0][0]== chSort && achBoard[0][1]== chSort && achBoard[0][2]== chSort)||
		(achBoard[0][1]== chSort && achBoard[0][2]== chSort && achBoard[0][3]== chSort)||
		(achBoard[0][2]== chSort && achBoard[0][3]== chSort && achBoard[0][4]== chSort)||
        (achBoard[1][0]== chSort && achBoard[1][1]== chSort && achBoard[1][2]== chSort)||
		(achBoard[1][1]== chSort && achBoard[1][2]== chSort && achBoard[1][3]== chSort)||
		(achBoard[1][2]== chSort && achBoard[1][3]== chSort && achBoard[1][4]== chSort)||
		(achBoard[2][0]== chSort && achBoard[2][1]== chSort && achBoard[2][2]== chSort)||
		(achBoard[2][1]== chSort && achBoard[2][2]== chSort && achBoard[2][3]== chSort)||
		(achBoard[2][2]== chSort && achBoard[2][3]== chSort && achBoard[2][4]== chSort)||
		(achBoard[3][0]== chSort && achBoard[3][1]== chSort && achBoard[3][2]== chSort)||
		(achBoard[3][1]== chSort && achBoard[3][2]== chSort && achBoard[3][3]== chSort)||
		(achBoard[3][2]== chSort && achBoard[3][3]== chSort && achBoard[3][4]== chSort)||
		(achBoard[4][0]== chSort && achBoard[4][1]== chSort && achBoard[4][2]== chSort)||
		(achBoard[4][1]== chSort && achBoard[4][2]== chSort && achBoard[4][3]== chSort)||
		(achBoard[4][2]== chSort && achBoard[4][3]== chSort && achBoard[4][4]== chSort)||

		(achBoard[0][0]== chSort && achBoard[1][0]== chSort && achBoard[2][0]== chSort)||
		(achBoard[1][0]== chSort && achBoard[2][0]== chSort && achBoard[3][0]== chSort)||
		(achBoard[2][0]== chSort && achBoard[3][0]== chSort && achBoard[4][0]== chSort)||
        (achBoard[0][1]== chSort && achBoard[1][1]== chSort && achBoard[2][1]== chSort)||
        (achBoard[1][1]== chSort && achBoard[2][1]== chSort && achBoard[3][1]== chSort)||
		(achBoard[2][1]== chSort && achBoard[3][1]== chSort && achBoard[4][1]== chSort)||
        (achBoard[0][2]== chSort && achBoard[1][2]== chSort && achBoard[2][2]== chSort)||
		(achBoard[1][2]== chSort && achBoard[2][2]== chSort && achBoard[3][2]== chSort)||
		(achBoard[2][2]== chSort && achBoard[3][2]== chSort && achBoard[4][2]== chSort)||
		(achBoard[0][3]== chSort && achBoard[1][3]== chSort && achBoard[2][3]== chSort)||
		(achBoard[1][3]== chSort && achBoard[2][3]== chSort && achBoard[3][3]== chSort)||
		(achBoard[2][3]== chSort && achBoard[3][3]== chSort && achBoard[4][3]== chSort)||
		(achBoard[0][4]== chSort && achBoard[1][4]== chSort && achBoard[2][4]== chSort)||
		(achBoard[1][4]== chSort && achBoard[2][4]== chSort && achBoard[3][4]== chSort)||
		(achBoard[2][4]== chSort && achBoard[3][4]== chSort && achBoard[4][4]== chSort)||

        (achBoard[0][0]== chSort && achBoard[1][1]== chSort && achBoard[2][2]== chSort)||
        (achBoard[1][1]== chSort && achBoard[2][2]== chSort && achBoard[3][3]== chSort)||
		(achBoard[2][2]== chSort && achBoard[3][3]== chSort && achBoard[4][4]== chSort)||
        (achBoard[1][0]== chSort && achBoard[2][1]== chSort && achBoard[3][2]== chSort)||
        (achBoard[2][1]== chSort && achBoard[3][2]== chSort && achBoard[4][3]== chSort)||
        (achBoard[2][0]== chSort && achBoard[3][1]== chSort && achBoard[4][2]== chSort)||
        (achBoard[0][1]== chSort && achBoard[1][2]== chSort && achBoard[2][3]== chSort)||
		(achBoard[1][2]== chSort && achBoard[2][3]== chSort && achBoard[3][4]== chSort)||
		(achBoard[0][2]== chSort && achBoard[1][3]== chSort && achBoard[2][4]== chSort)||
        
        (achBoard[0][4]== chSort && achBoard[1][3]== chSort && achBoard[2][2]== chSort)||
        (achBoard[1][3]== chSort && achBoard[2][2]== chSort && achBoard[3][1]== chSort)||
		(achBoard[2][2]== chSort && achBoard[3][1]== chSort && achBoard[4][0]== chSort)||
		(achBoard[1][4]== chSort && achBoard[2][3]== chSort && achBoard[3][2]== chSort)||
		(achBoard[2][3]== chSort && achBoard[3][2]== chSort && achBoard[4][1]== chSort)||
		(achBoard[0][3]== chSort && achBoard[1][2]== chSort && achBoard[2][1]== chSort)||
		(achBoard[1][2]== chSort && achBoard[2][1]== chSort && achBoard[3][0]== chSort)||
		(achBoard[2][4]== chSort && achBoard[3][3]== chSort && achBoard[4][3]== chSort)||
		(achBoard[0][2]== chSort && achBoard[1][1]== chSort && achBoard[2][0]== chSort))
		return 1;
	else 
		return 0;
}
int CGobang::GetFull(void)
{
    if(sum>25)
	{
		cout<<endl<<endl<<"\t\t"<<"棋盘已满！平局！"<<endl;
	    nDraw++;
		return 1;
	}
	else return 0;
}
			
void main()
{
	CGobang a('O'),b('X');	
	char ch;
	do
	{
		system("cls");
		cout<<endl<<endl<<"----------欢迎使用三子连珠游戏！----------"<<endl;
		CGobang::InitialBoard();				
		CGobang::PrintBoard();
		do
		{		
	        a.PlayTurn();
			system("cls");
			cout<<endl<<endl<<"----------欢迎使用三子连珠游戏！----------"<<endl;
	        a.PrintBoard();
	        if(a.Judge()==1)
			{
				a.Win();
				b.Lose();
		        break;
			}
	        if(a.GetFull()==1)
		        break;
	        b.PlayTurn();
			system("cls");
			cout<<endl<<endl<<"----------欢迎使用三子连珠游戏！----------"<<endl;
	        b.PrintBoard();
        	if(b.Judge()==1)
			{
		        b.Win();
				a.Lose();
		        break;
			}
	        if(b.GetFull()==1)
	        	break;	
			
		}while(1);
	    a.PrintInfo();
	    b.PrintInfo();
	    cout<<endl<<endl<<"\t是否继续游戏：Y是，N否"<<endl<<"\t请输入Y或N：";
	    cin>>ch;
	}while(ch=='Y');
}