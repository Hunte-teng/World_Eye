
#include "stdafx.h"
#include <stdio.h>

//定义恐龙位置结构
struct dragon
{
	int x,y;
	int dir;
};

const int draNum = 3;

HINSTANCE hInst;
HBITMAP draPic[4],map;
HDC		hdc,mdc,bufdc;
HWND	hWnd;
DWORD	tPre,tNow;
int		picNum,x=0,y=0;
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

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HBITMAP bmp;
	hInst = hInstance;
	int i;

	hWnd = CreateWindow("canvas", "绘图窗口" , WS_OVERLAPPEDWINDOW,
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

	draPic[0] = (HBITMAP)LoadImage(NULL,"dra0.bmp",IMAGE_BITMAP,528,188,LR_LOADFROMFILE);
	draPic[1] = (HBITMAP)LoadImage(NULL,"dra1.bmp",IMAGE_BITMAP,544,164,LR_LOADFROMFILE);
	draPic[2] = (HBITMAP)LoadImage(NULL,"dra2.bmp",IMAGE_BITMAP,760,198,LR_LOADFROMFILE);
	draPic[3] = (HBITMAP)LoadImage(NULL,"dra3.bmp",IMAGE_BITMAP,760,198,LR_LOADFROMFILE);
	map = (HBITMAP)LoadImage(NULL,"map.bmp",IMAGE_BITMAP,1548,1129,LR_LOADFROMFILE);

	for(i=0;i<draNum;i++)
	{
		dra[i].dir = 3;    //起始方向
		dra[i].x = 600;	   //X坐标
		dra[i].y = 400;    //Y坐标
	}

	MyPaint(hdc);

	return TRUE;
}

//气泡排序
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

// 1.对跑动的恐龙进行排序贴图
// 2.恐龙贴图坐标修正
void MyPaint(HDC hdc)
{
	int w,h,i;

	if(picNum == 8)
		picNum = 0;

	//在mdc上贴背景
	SelectObject(bufdc,map);
	BitBlt(mdc,0,0,640,480,bufdc,x,y,SRCCOPY);

	BubSort(draNum);

	for(i=0;i<draNum;i++)
	{
		SelectObject(bufdc,draPic[dra[i].dir]);//选入方向位图
		switch(dra[i].dir)//根据不同方向确定不同宽、高
		{
			case 0:
				w = 66;
				h = 94;
				break;
			case 1:
				w = 68;
				h = 82;
				break;
			case 2:
				w = 95;
				h = 99;
				break;
			case 3:
				w = 95;
				h = 99;
				break;
		}
		BitBlt(mdc,dra[i].x-x,dra[i].y-y,w,h,bufdc,picNum*w,h,SRCAND);
		BitBlt(mdc,dra[i].x-x,dra[i].y-y,w,h,bufdc,picNum*w,0,SRCPAINT);
	}

	//显示到窗口 
	BitBlt(hdc,0,0,640,480,mdc,0,0,SRCCOPY);

	tPre = GetTickCount();         //记录时间
	picNum++;

	for(i=0;i<draNum;i++)
	{
		switch(rand()%4)          //随机决定下次移动方向
		{
			case 0:					     //上
				switch(dra[i].dir)
				{
					case 0:	
						dra[i].y -= 10;
						break;
					case 1:
						//dra[i].x += 2;
						dra[i].y -= 10;
						break;
					case 2:	
						//dra[i].x += 14;
						dra[i].y -= 10;
						break;
					case 3:
						//dra[i].x += 14;
						dra[i].y -= 10;
						break;
				}
				if(dra[i].y < 235)
					dra[i].y = 235;
				dra[i].dir = 0;
				break;
			case 1:				     	//下
				switch(dra[i].dir)
				{
					case 0:
						//dra[i].x -= 2;
						dra[i].y += 10;
						break;
					case 1:
						dra[i].y += 10;
						break;
					case 2:
						//dra[i].x += 15;
						dra[i].y += 10;
						break;
					case 3:
						//dra[i].x += 15;
						dra[i].y += 10;
						break;
				}

				if(dra[i].y > 564)
					dra[i].y = 564;
				dra[i].dir = 1;
				break;
			case 2:				    	//左
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
				if(dra[i].x < 430)
					dra[i].x = 430;
				dra[i].dir = 2;
				break;
			case 3:				    	//右
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
				if(dra[i].x > 774)
					dra[i].x = 774;
				dra[i].dir = 3;
				break;
		}
	}
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		int i;

		case WM_KEYDOWN:			     //按下键盘消息
			switch (wParam) 
			{
				case VK_UP:				 //上箭头
					y -= 20;
					if(y < 0)
						y = 0;
					break;
				case VK_DOWN:			 //下箭头
					y += 20;
					if(y > 660)
						y = 660;
					break;
				case VK_LEFT:			 //左箭头
					x -= 20;
					if(x < 0)
						x = 0;
					break;
				case VK_RIGHT:			 //右箭头
					x += 20;
					if(x > 910)
						x = 910;
					break;
			}
			break;

		case WM_DESTROY:					//
			DeleteDC(mdc);
			DeleteDC(bufdc);
			for(i=0;i<4;i++)
				DeleteObject(draPic[i]);
			DeleteObject(map);
			ReleaseDC(hWnd,hdc);
			PostQuitMessage(0);
			break;
		default:							//
			return DefWindowProc(hWnd, message, wParam, lParam);
   }
   return 0;
}

