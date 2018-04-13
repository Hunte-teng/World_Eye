
#include "stdafx.h"
#include <stdio.h>

HINSTANCE hInst;
HBITMAP fullmap;
HDC		hdc,mdc,bufdc;
DWORD	tPre,tNow;

HBITMAP map[4],scene[4];

const int rows1 = 8,cols1 = 13;
const int rows2 = 21,cols2 = 21;


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
			if(tNow-tPre >= 40)
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
	HWND hWnd;
	//HDC bufdc;

	hInst = hInstance;

	hWnd = CreateWindow("canvas", "绘图窗口" , WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

	if (!hWnd)
	{
		return FALSE;
	}

	MoveWindow(hWnd,10,10,640,400,true);
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	        int mapIndex[rows2*cols2] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,  //1
								0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,  //2
								0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,  //3
								0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,  //4
								0,0,3,3,1,1,1,1,1,1,1,1,1,1,1,1,1,3,3,0,0,  //5
								0,0,3,3,1,0,0,0,0,0,1,0,0,0,0,0,1,3,3,0,0,  //6
								0,0,3,3,1,0,0,2,2,0,1,0,2,2,0,0,1,3,3,0,0,  //7
								0,0,3,3,1,0,0,2,2,0,1,0,2,2,0,0,1,3,3,0,0,  //8
								0,0,3,3,1,0,0,2,2,0,1,0,2,2,0,0,1,3,3,0,0,  //9
								0,0,3,3,1,0,0,2,2,0,1,0,2,2,0,0,1,3,3,0,0,
								0,0,3,3,1,0,0,2,2,0,1,0,2,2,0,0,1,3,3,0,0,
								0,0,3,3,1,0,0,2,2,0,1,0,2,2,0,0,1,3,3,0,0,
								0,0,3,3,1,0,0,2,2,0,1,0,2,2,0,0,1,3,3,0,0,
								0,0,3,3,1,0,0,2,2,0,1,0,2,2,0,0,1,3,3,0,0,
								0,0,3,3,1,0,0,2,2,0,1,0,2,2,0,0,1,3,3,0,0,
								0,0,3,3,1,0,0,0,0,0,1,0,0,0,0,0,1,3,3,0,0,
								0,0,3,3,1,1,1,1,1,1,1,1,1,1,1,1,1,3,3,0,0,
								0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,
								0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,
								0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
								0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};//10

	        int sceneIndex[rows2*cols2] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
								  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
								  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	                              0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
								  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
								  0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,  //1
								  0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,2,0,0,0,0,0,  //2
								  0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,  //3
								  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,  //4
								  0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,  //5
								  0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,3,0,0,0,0,0,  //6
								  0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,  //7
								  0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,3,0,0,0,0,0,  //8
								  0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,  //9
								  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
								  0,0,0,0,0,0,2,0,0,1,0,1,0,0,0,2,0,0,0,0,0,
								  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
								  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	                              0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
								  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};//10

	        hdc = GetDC(hWnd);
	        mdc = CreateCompatibleDC(hdc);
	        bufdc = CreateCompatibleDC(hdc);
	        fullmap = CreateCompatibleBitmap(hdc,cols2*50,rows2*50);

	        char filename[20] = "";
	        int rowNum,colNum;
	        int i,x,y;
	        int xstart,ystart;
	
	        xstart = 280;//32 * (rows-1-10-1);
	        ystart = -155;
 

	        SelectObject(mdc,fullmap);

	        //加载各块地图位图
	        for(i=0;i<4;i++)
			{
		         sprintf(filename,"map%d.bmp",i);
		         map[i] = (HBITMAP)LoadImage(NULL,filename,IMAGE_BITMAP,128,32,LR_LOADFROMFILE);
			}

	        //加载各场景位图
	        for(i=0;i<4;i++)
			{
		        sprintf(filename,"scene%d.bmp",i+1);
		        scene[i] = (HBITMAP)LoadImage(NULL,filename,IMAGE_BITMAP,100,60,LR_LOADFROMFILE);
			}

	        //按mapIndex数组取出图块拼地图 
	        for (i=0;i<rows2*cols2;i++)
			{
		         SelectObject(bufdc,map[mapIndex[i]]);

		         rowNum = i / cols2;     //求行编号
		         colNum = i % cols2;     //求列编号
		         x = xstart + colNum * 32 + rowNum * (-32);  //贴图X坐标 
		         y = ystart + rowNum * 16 + colNum * 16;     //贴图Y坐标 
		
		         BitBlt(mdc,x,y,64,32,bufdc,64,0,SRCAND);
		         BitBlt(mdc,x,y,64,32,bufdc,0,0,SRCPAINT);

		         switch(sceneIndex[i])
				 {
			     case 1:
				      SelectObject(bufdc,scene[0]);
				      BitBlt(mdc,x+7,y-44,50,60,bufdc,50,0,SRCAND);
				      BitBlt(mdc,x+7,y-44,50,60,bufdc,0,0,SRCPAINT);
					  break;
			     case 2:
				      SelectObject(bufdc,scene[1]);
				      BitBlt(mdc,x+7,y-40,50,60,bufdc,50,0,SRCAND);
				      BitBlt(mdc,x+7,y-40,50,60,bufdc,0,0,SRCPAINT);
				      break;
			     case 3:
				      SelectObject(bufdc,scene[3]);
				      BitBlt(mdc,x+7,y-44,50,60,bufdc,50,0,SRCAND);
				      BitBlt(mdc,x+7,y-44,50,60,bufdc,0,0,SRCPAINT);
				      break;
				 }
			}

	MyPaint(hdc);

	ReleaseDC(hWnd,hdc);
	DeleteDC(bufdc);

	return TRUE;
}

void MyPaint(HDC hdc)
{

	BitBlt(hdc,0,0,640,480,mdc,0,0,SRCCOPY);
    tPre = GetTickCount();
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;

	char filename[20] = "";
	        int rowNum,colNum;
	        int i,x,y;
			//HINSTANCE hInstance;
			int nCmdShow;

	int mapIndex[rows1*cols1] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,   //第1行
								1,0,0,0,0,0,0,0,0,0,0,1,1,   //第2行
								1,0,2,2,2,2,2,2,2,2,0,1,1,   //第3行
								1,0,2,2,2,2,2,2,2,2,0,1,1,   //第4行
								1,0,2,2,2,2,2,2,2,2,0,1,1,   //第5行
								1,0,0,0,0,0,0,0,0,0,0,1,1,   //第6行
								1,1,1,1,1,1,1,1,1,1,1,1,1,
								1,1,1,1,1,1,1,1,1,1,1,1,1};   //第7行

	switch (message)
	{
		case WM_PAINT:
			hdc = BeginPaint(hWnd, &ps);
			MyPaint(hdc);
			EndPaint(hWnd, &ps);
			break;


			case WM_LBUTTONDOWN:
				

			MoveWindow(hWnd,10,10,640,400,true);
	        ShowWindow(hWnd, nCmdShow);
	        UpdateWindow(hWnd);

			
								 
	        hdc = GetDC(hWnd);
	        mdc = CreateCompatibleDC(hdc);
	        bufdc = CreateCompatibleDC(hdc);
	        fullmap = CreateCompatibleBitmap(hdc,cols1*50,rows1*50);

	        SelectObject(mdc,fullmap);

	        
	        //加载各图块位图
	        for(i=0;i<3;i++)
			{
		        sprintf(filename,"map%d.bmp",i+4);
		        map[i] = (HBITMAP)LoadImage(NULL,filename,IMAGE_BITMAP,50,50,LR_LOADFROMFILE);
			}

	        //按mapIndex数组中的定义取出对应图块，进行地图拼接 
	        for (i=0;i<rows1*cols1;i++)
			{
		        SelectObject(bufdc,map[mapIndex[i]]);

		        rowNum = i / cols1;   //求行编号
		        colNum = i % cols1;   //求列编号
		        x = colNum * 50;     //求贴图X坐标 
		        y = rowNum * 50;     //求贴图Y坐标

		        BitBlt(mdc,x,y,50,50,bufdc,0,0,SRCCOPY);
			}
			BitBlt(hdc,0,0,640,480,mdc,0,0,SRCCOPY);
		    break;

		case WM_DESTROY:
			DeleteDC(mdc);
			DeleteObject(fullmap);
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
   }
   return 0;
}

