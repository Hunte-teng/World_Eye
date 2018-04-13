#include<iostream>
using namespace std;
#include <stdlib.h>
class CGobang		//������
{
private:
			char chSort;					//���ӵ����
			int nWin;						//Ӯ��Ĵ���
			int nLose;					    //����Ĵ���
			static int nDraw;				//ƽ�ִ���
            static char achBoard[5][5];		//����
			static int nSize;				//���̵ĳߴ�nSize��nSize
			static int sum;                 //ͳ�����˶��ٲ���
public:
			CGobang(char chsort);			//���캯��������һ�����ӵ����
			void PlayTurn(void);			//��һ����
			int Judge();					//�ж��Ƿ�����һ�ߣ��Ƿ���1���񷵻�0
			void Win(void);				    //Ӯ��
			void Lose(void);				//����
			static void Draw(void);			//ƽ��
			void PrintInfo(void);			//��ӡ�������
			static void PrintBoard(void);	//��ӡ����
			static int GetFull(void);		//�ж������Ƿ��Ѳ�������
			static void InitialBoard(void);	//��ʼ������
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
	cout<<endl<<endl<<"\t\t   "<<chSort<<"��ʤ��"<<endl;
	nWin++;
}

void CGobang::Lose(void)
{
	cout<<endl<<endl<<"\t\t   "<<chSort<<"��ʤ��"<<endl;
	nLose++;
}

void CGobang::Draw()
{
	cout<<endl<<endl<<"\t\t   "<<"ƽ��"<<endl;
	nDraw++;
}

void CGobang::InitialBoard(void)//��ʼ������
{
	for(int i=0;i<nSize;i++)
		for(int j=0;j<nSize;j++)
			achBoard[i][j]=' ';
}

void CGobang::PrintBoard(void)//��ӡ����
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
		cout<<"\t�ֵ�"<<chSort<<"����"<<endl;
		cout << "\tRow: ";
	    cin  >> x;
	    cout << "\tColumn: ";
	    cin  >> y;
	    if(x>nSize||y>nSize)
			cout<<"\tԽ�磡���������룺"<<endl;
		else if(achBoard[x-1][y-1]!=' ')
			cout<<"\t�õ�����ֵ�����������룺"<<endl;
		else
		{
			achBoard[x-1][y-1]=chSort;
			break;
		}
	}while(1);
	sum++;
}

void CGobang::PrintInfo(void)//��ӡ�������
{
	cout <<"\t"<<chSort<<"����Ӯ"<<nWin<<" �֣��� "<<nLose <<" �֣�ƽ "<<nDraw<<" �֡�"<<endl; 
}

int CGobang::Judge(void)//�ж��Ƿ�����һ�ߣ��Ƿ���1���񷵻�0
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
		cout<<endl<<endl<<"\t\t"<<"����������ƽ�֣�"<<endl;
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
		cout<<endl<<endl<<"----------��ӭʹ������������Ϸ��----------"<<endl;
		CGobang::InitialBoard();				
		CGobang::PrintBoard();
		do
		{		
	        a.PlayTurn();
			system("cls");
			cout<<endl<<endl<<"----------��ӭʹ������������Ϸ��----------"<<endl;
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
			cout<<endl<<endl<<"----------��ӭʹ������������Ϸ��----------"<<endl;
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
	    cout<<endl<<endl<<"\t�Ƿ������Ϸ��Y�ǣ�N��"<<endl<<"\t������Y��N��";
	    cin>>ch;
	}while(ch=='Y');
}