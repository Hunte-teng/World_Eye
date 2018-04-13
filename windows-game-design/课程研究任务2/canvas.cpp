
#include "stdafx.h"

HINSTANCE hInst;
HBITMAP bg,dra0,dra1;
HDC		hdc,mdc,bufdc;
HWND	hWnd;
DWORD	tPre,tNow;
int		num0,num1,x,y,s;

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

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	char filename[20] = "";
	HBITMAP bmp;
	hInst = hInstance;

	hWnd = CreateWindow("canvas", "��ͼ����" , WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

	if (!hWnd)
	{
		return FALSE;
	}

	MoveWindow(hWnd,10,10,640,480,true);
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	hdc = GetDC(hWnd);
	mdc = CreateCompatibleDC(hdc);
	bufdc = CreateCompatibleDC(hdc);
	bmp = CreateCompatibleBitmap(hdc,640,480);

	SelectObject(mdc,bmp);

	dra0 = (HBITMAP)LoadImage(NULL,"dra0.bmp",IMAGE_BITMAP,760,198,LR_LOADFROMFILE);
	dra1 = (HBITMAP)LoadImage(NULL,"dra1.bmp",IMAGE_BITMAP,760,198,LR_LOADFROMFILE);
	bg = (HBITMAP)LoadImage(NULL,"bg.bmp",IMAGE_BITMAP,640,480,LR_LOADFROMFILE);

	num0 = 0;    //ͼ��
	num1 = 0;
	s=640+95;
	x = 640;	//��ͼ��ʼX����
	y = 300;    //��ͼ��ʼY����

	MyPaint(hdc);

	return TRUE;
}

// 1.�������ܶ�ͼ��͸��
// 2.�������ͼ����
void MyPaint(HDC hdc)
{
	if(num0 == 8)
		num0 = 0;
	
	if(x>=-95 && s>0)
	{
    //����mdc��������ͼ
	    SelectObject(bufdc,bg);
	    BitBlt(mdc,0,0,640,480,bufdc,0,0,SRCCOPY);

	    //����mdc�Ͻ���͸������
	    SelectObject(bufdc,dra0);
	    BitBlt(mdc,x,y,95,99,bufdc,num0*95,99,SRCAND);
    	BitBlt(mdc,x,y,95,99,bufdc,num0*95,0,SRCPAINT);

	    //��������ʾ�ڴ���
	    BitBlt(hdc,0,0,640,480,mdc,0,0,SRCCOPY);

	    tPre = GetTickCount();     //��¼�˴λ�ͼʱ��
	    num0++;
        
		if(x>480)                 //�����´���ͼ����
			y+=6;
		if(x>=480 && x<380)
			y=450;
		if(x<=380 && x>=90)
			y-=7;
		if(x<90)
			y+=2;
		x-=20;
	    s-=20;
	}		
	else
	{
		if(num1 == 8)
		    num1 = 0;
		//����mdc��������ͼ
	    SelectObject(bufdc,bg);
	    BitBlt(mdc,0,0,640,480,bufdc,0,0,SRCCOPY);

	    //����mdc�Ͻ���͸������
	    SelectObject(bufdc,dra1);
	    BitBlt(mdc,x,y,95,99,bufdc,num1*95,99,SRCAND);
	    BitBlt(mdc,x,y,95,99,bufdc,num1*95,0,SRCPAINT);

	    //��������ʾ�ڴ���
	    BitBlt(hdc,0,0,640,480,mdc,0,0,SRCCOPY);

	    tPre = GetTickCount();     //��¼�˴λ�ͼʱ��
	    num1++;
        if(x>450)
			y=y;
		if(x<=450 && x>250)                  //�����´���ͼ����
			y-=6;
		if(x<=250 && x>=90)
			y+=7;
		if(x<90)
			y-=2;
	    x+=20;					   //�����´���ͼ����
		
	}
}

//************************************
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case WM_DESTROY:					//
			DeleteDC(mdc);
			DeleteDC(bufdc);
			DeleteObject(dra0);
			DeleteObject(dra1);
			DeleteObject(bg);
			ReleaseDC(hWnd,hdc);
			PostQuitMessage(0);
			break;
		default:							//
			return DefWindowProc(hWnd, message, wParam, lParam);
   }
   return 0;
}

