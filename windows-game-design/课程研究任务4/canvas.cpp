
#include "stdafx.h"

//�������λ�ýṹ
struct dragon
{
	int x,y;
	int dir;
};

const int draNum = 2;

HINSTANCE hInst;
HBITMAP draPic[2],dra1,bg[3];//Ϊ3������ѭ������׼��
HDC		hdc,mdc,bufdc;
HWND	hWnd;
DWORD	tPre,tNow;
int		picNum,x0=0,x1=0,x2=0,x3,num=0;
dragon  dra[draNum];

ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
void				MyPaint(HDC hdc);

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	MSG msg;

	MyRegisterClass(hInstance);


	if (!InitInstance (hInstance, nCmdShow)) 
	{
		return FALSE;
	}

    while( msg.message!=WM_QUIT )
    {
        if( PeekMessage( &msg, NULL, 0,0 ,PM_REMOVE) )
        {
            TranslateMessage( &msg );
            DispatchMessage( &msg );
        }
		else
		{
			tNow = GetTickCount();
			if(tNow-tPre >= 100)
				MyPaint(hdc);
		}
    }

	return msg.wParam;
}


ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX); 
	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= (WNDPROC)WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= NULL;
	wcex.hCursor		= NULL;
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= NULL;
	wcex.lpszClassName	= "canvas";
	wcex.hIconSm		= NULL;

	return RegisterClassEx(&wcex);
}

// ���ظ�λͼ��������λͼ��ѡ��mdc��
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HBITMAP bmp;
	hInst = hInstance;
	int i;

	hWnd = CreateWindow("canvas", "��ͼ����" , WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

	if (!hWnd)
	{
		return FALSE;
	}

	MoveWindow(hWnd,10,10,640,520,true);
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	hdc = GetDC(hWnd);
	mdc = CreateCompatibleDC(hdc);
	bufdc = CreateCompatibleDC(hdc);

	bmp = CreateCompatibleBitmap(hdc,640,520);
	SelectObject(mdc,bmp);

	bg[0] = (HBITMAP)LoadImage(NULL,"bg0.bmp",IMAGE_BITMAP,640,480,LR_LOADFROMFILE);
	bg[1] = (HBITMAP)LoadImage(NULL,"bg1.bmp",IMAGE_BITMAP,640,600,LR_LOADFROMFILE);
	bg[2] = (HBITMAP)LoadImage(NULL,"bg2.bmp",IMAGE_BITMAP,640,600,LR_LOADFROMFILE);
	dra1 = (HBITMAP)LoadImage(NULL,"dra0.bmp",IMAGE_BITMAP,760,198,LR_LOADFROMFILE);
	draPic[0] = (HBITMAP)LoadImage(NULL,"dra0.bmp",IMAGE_BITMAP,760,198,LR_LOADFROMFILE);
	draPic[1] = (HBITMAP)LoadImage(NULL,"dra1.bmp",IMAGE_BITMAP,760,198,LR_LOADFROMFILE);


	for(i=0;i<draNum;i++)
	{
		dra[i].dir = 3;    //��ʼ����
		dra[i].x = 300;	   //X����
		dra[i].y = 380;    //Y����
	}

	x3=100;
	MyPaint(hdc);

	return TRUE;
}

//����������
void BubSort(int n)
{
	int i,j;
	bool f;
	dragon tmp;

	for(i=0;i<n-1;i++)
	{
		f = false;
		for(j=0;j<n-i-1;j++)
		{
			if(dra[j+1].y < dra[j].y)
			{
				tmp = dra[j+1];
				dra[j+1] = dra[j];
				dra[j] = tmp;
				f = true;
			}
		}
		if(!f)
			break;
	}
}

// 1.��������Զ���������ѭ��������ͼ
// 2.����ǰ��������͸����ͼ
// 3.���������ͼ���и������ܶ�������ͼ��
void MyPaint(HDC hdc)
{
	//�����
	SelectObject(bufdc,bg[0]);
	BitBlt(mdc,0,0,x0,300,bufdc,640-x0,0,SRCCOPY);
	BitBlt(mdc,x0,0,640-x0,300,bufdc,0,0,SRCCOPY);

	//���ݵأ���ͬһλͼ���²�
	BitBlt(mdc,0,300,x2,180,bufdc,640-x2,300,SRCCOPY);
	BitBlt(mdc,x2,300,640-x2,180,bufdc,0,300,SRCCOPY);

	//͸����ɽ��
	SelectObject(bufdc,bg[1]);
	BitBlt(mdc,0,0,x1,300,bufdc,640-x1,300,SRCAND);
	BitBlt(mdc,x1,0,640-x1,300,bufdc,0,300,SRCAND);
	BitBlt(mdc,0,0,x1,300,bufdc,640-x1,0,SRCPAINT);
	BitBlt(mdc,x1,0,640-x1,300,bufdc,0,0,SRCPAINT);

	//͸��������
	SelectObject(bufdc,bg[2]);
	BitBlt(mdc,0,250,x2,300,bufdc,640-x2,300,SRCAND);
	BitBlt(mdc,x2,250,640-x2,300,bufdc,0,300,SRCAND);
	BitBlt(mdc,0,250,x2,300,bufdc,640-x2,0,SRCPAINT);
	BitBlt(mdc,x2,250,640-x2,300,bufdc,0,0,SRCPAINT);

	//͸��������----�ɼ��̲���
	SelectObject(bufdc,dra1);
	if(num==3||num==4)
	{//��������
	BitBlt(mdc,x3,360,95,99,bufdc,num*95,99,SRCAND);
	BitBlt(mdc,x3,360,95,99,bufdc,num*95,0,SRCPAINT);
	}else
	{
	BitBlt(mdc,x3,350,95,99,bufdc,num*95,99,SRCAND);
	BitBlt(mdc,x3,350,95,99,bufdc,num*95,0,SRCPAINT);
	}

	x0 += 2;		//��������и���
	if(x0==640)
		x0 = 0;

	x1 += 5;		//����ɽ���и���
	if(x1==640)
		x1 = 0;

	x2 += 8;		//����ݵغͷ����и���
	if(x2==640)
		x2 = 0;

	num++;			//��������ܶ�ͼ��
	if(num == 8)
		num = 0;

	//����Զ��ܵ���ֻС����
	int w,h,i;
	w = 95;
	h = 99;

	if(picNum == 8)
		picNum = 0;

	BubSort(draNum);

	for(i=0;i<draNum;i++)
	{
		SelectObject(bufdc,draPic[dra[i].dir]);//ѡ�뷽��λͼ
		switch(dra[i].dir)//���ݲ�ͬ����ȷ����ͬ����
		{
			case 0:
				w = 95;
				h = 99;
				break;
			case 1:
				w = 95;
				h = 99;
				break;
		}
		BitBlt(mdc,dra[i].x,dra[i].y,w,h,bufdc,picNum*w,h,SRCAND);
		BitBlt(mdc,dra[i].x,dra[i].y,w,h,bufdc,picNum*w,0,SRCPAINT);
	}

	//��ʾ������ 
	BitBlt(hdc,0,0,640,480,mdc,0,0,SRCCOPY);

	tPre = GetTickCount();         //��¼ʱ��
	picNum++;

	for(i=0;i<draNum;i++)
	{
		switch(rand()%4)          //��������´��ƶ�����V
		{
			case 0:				    	//��
				switch(dra[i].dir)
				{
					case 0:
						dra[i].x -= 10;
						break;
					case 1:
						dra[i].x -= 10;
						//dra[i].y -= 9;
						break;
					case 2:
						dra[i].x -= 10;
						break;
					case 3:
						dra[i].x -= 10;
						break;
				}
				if(dra[i].x < 0)
					dra[i].x = 0;
				dra[i].dir = 0;
				break;
			case 1:				    	//�k��
				switch(dra[i].dir)
				{
					case 0:
						dra[i].x += 10;
						break;
					case 1:
						dra[i].x +=10;
						//dra[i].y -= 10;
						break;
					case 2:
						dra[i].x += 10;
						break;
					case 3:
						dra[i].x += 10;
						break;
				}
				if(dra[i].x > 535)
					dra[i].x = 535;
				dra[i].dir = 1;
				break;
		}
	}
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int i;
	switch (message)
	{
		case WM_KEYDOWN:			     //���¼�����Ϣ
			switch (wParam) 
			{
				case VK_LEFT:			 //���ͷ
					x3 -= 5;
					if(x3 < 0)
						x3 = 0;
					break;
				case VK_RIGHT:			 //�Ҽ�ͷ
					x3 += 5;
					if(x3 > 545)
						x3 = 545;
					break;
			}
			break;
		case WM_DESTROY:
			DeleteDC(mdc);
			DeleteDC(bufdc);
			DeleteObject(bg[0]);
			DeleteObject(bg[1]);
			DeleteObject(bg[2]);
			DeleteObject(dra1);
			for(i=0;i<2;i++)
				DeleteObject(draPic[i]);
			ReleaseDC(hWnd,hdc);
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
   }
   return 0;
}

