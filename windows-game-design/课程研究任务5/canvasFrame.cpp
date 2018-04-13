// canvasFrame.cpp : implementation file
//

#include "stdafx.h"
#include "canvasr.h"
#include "canvasFrame.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

struct snow
{
	int x;
	int y;
	BOOL exist;
};

struct ball
{
	int x;
	int y;
};

struct fireball
{
	int x;       //
	int y;       //
	int vx;      //
	int vy;      //、
	int lasted;  //持续时间
	BOOL exist;  //
};
/////////////////////////////////////////////////////////////////////////////
// canvasFrame

IMPLEMENT_DYNCREATE(canvasFrame, CFrameWnd)

int i,j,count,mark=0;
int v[3]={5,-5,-5};
int x,y;
snow drop[50];
ball dra[3];
fireball fireball[20];
canvasFrame::canvasFrame()
{
	Create(NULL,"无序赛车游戏");
	CClientDC dc(this);
	int width = dc.GetDeviceCaps(HORZRES);
	int height = dc.GetDeviceCaps(VERTRES);
	GetWindowRect( &rect );
	width = ( width - ( rect.right - rect.left ))/2 ;
	height = (height - (rect.bottom - rect.top ))/2 ;
	//MoveWindow( width , height , (rect.right - rect.left ) , (rect.bottom - rect.top ) ,true);
	MoveWindow( width , height , 640 , 480 ,true);
	GetClientRect(&rect);
	mdc = new CDC;
	mdc1 = new CDC;
	mdc->CreateCompatibleDC(&dc); 
	mdc1->CreateCompatibleDC(&dc);
	bgbmp = new CBitmap;
	snow = new CBitmap;
	mask = new CBitmap;

	ball[0] = new CBitmap;
	ball[1] = new CBitmap;
	ball[2] = new CBitmap;
	black = new CBitmap;
	fire = new CBitmap;
	firemask = new CBitmap;

	temp = new CBitmap;
	bgbmp->m_hObject = (HBITMAP)::LoadImage(NULL,"bground.bmp",IMAGE_BITMAP,rect.right,rect.bottom,LR_LOADFROMFILE); //
	snow->m_hObject = (HBITMAP)::LoadImage(NULL,"snow.bmp",IMAGE_BITMAP,20,20,LR_LOADFROMFILE); //
	mask->m_hObject = (HBITMAP)::LoadImage(NULL,"mask.bmp",IMAGE_BITMAP,20,20,LR_LOADFROMFILE); //

	ball[0]->m_hObject = (HBITMAP)::LoadImage(NULL,"red.bmp",IMAGE_BITMAP,20,20,LR_LOADFROMFILE); //
	ball[1]->m_hObject = (HBITMAP)::LoadImage(NULL,"green.bmp",IMAGE_BITMAP,20,20,LR_LOADFROMFILE); //
	ball[2]->m_hObject = (HBITMAP)::LoadImage(NULL,"yellow.bmp",IMAGE_BITMAP,20,20,LR_LOADFROMFILE); //
	black->m_hObject = (HBITMAP)::LoadImage(NULL,"ballmask.bmp",IMAGE_BITMAP,20,20,LR_LOADFROMFILE); //
	fire->m_hObject = (HBITMAP)::LoadImage(NULL,"fire.bmp",IMAGE_BITMAP,10,10,LR_LOADFROMFILE);
	firemask->m_hObject = (HBITMAP)::LoadImage(NULL,"firemask.bmp",IMAGE_BITMAP,10,10,LR_LOADFROMFILE);

	temp->CreateCompatibleBitmap(&dc,rect.right,rect.bottom);
	mdc->SelectObject(temp);

	dra[0].x = 200;	   //X坐标
	dra[0].y = 300;    //Y坐标
	dra[1].x = 300;	   //X坐标
	dra[1].y = 300;    //Y坐标
	dra[2].x = 500;	   //X坐标
	dra[2].y = 300;    //Y坐标

}

canvasFrame::~canvasFrame()
{
	delete bgbmp;
	delete snow;
	delete mask;
	for(i=0;i<3;i++)
		delete ball[i];
	delete black;
	delete fire;
	delete firemask;
	delete temp;
	delete mdc;
	delete mdc1;
	KillTimer(1); 
}


BEGIN_MESSAGE_MAP(canvasFrame, CFrameWnd)
	//{{AFX_MSG_MAP(canvasFrame)
	ON_WM_TIMER()
	ON_WM_CREATE()
	ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// canvasFrame message handlers

void canvasFrame::OnTimer(UINT nIDEvent) 
{
	CClientDC dc(this);
	mdc1->SelectObject(bgbmp);
	mdc->BitBlt(0,0,rect.right,rect.bottom,mdc1,0,0,SRCCOPY);

	for(i=0;i<3;i++)
	{
		mdc1->SelectObject(black);
		mdc->BitBlt(dra[i].x,dra[i].y,20,20,mdc1,0,0,SRCAND);
		mdc1->SelectObject(ball[i]);
		mdc->BitBlt(dra[i].x,dra[i].y,20,20,mdc1,0,0,SRCPAINT);
    }

	for(i=0;i<3;i++)//碰撞检测
	{
		if(abs(dra[i+1].x-dra[i].x)<20)
		{
			v[i]=-v[i];
		    v[i+1]=-v[i+1];
			mark=1;	
		}
		if(dra[i].x>600)
		{
			dra[i].x=600;
			v[i]=-v[i];
		}
		if(dra[i].x<0)
		{
			dra[i].x=0;
			v[i]=-v[i];
		}
		if(mark==1)
		{	
		    if(count == 0)              //10个小火球都不存在--熄灭或飞出窗口，创建一个烟花的50个小火球
			{
		        x=dra[i].x;//中心在窗口内随机设定
		        y=dra[i].y;
		        for(j=0;j<10;j++)       
				{
			        fireball[j].x = x;
			        fireball[j].y = y;
			        fireball[j].lasted = 0;
			        if(j%4==0)//分4个象限
					{
				        fireball[j].vx =  -rand()%10;//速度和方向同时随机确定
				        fireball[j].vy =  -rand()%10;
					}
			        if(j%4==1)
					{
				        fireball[j].vx = rand()%10;
				        fireball[i].vy = rand()%10;
					}
			        if(j%4==2)
					{
				        fireball[j].vx = -rand()%10;
				        fireball[j].vy = rand()%10;
					}
			        if(j%4==3)
					{
				        fireball[j].vx = rand()%10;
				        fireball[j].vy = -rand()%10;
					}
			        fireball[j].exist = true;
				}
		        count = 10;
			}
			for(j=0;j<10;j++)
			{
		        if(fireball[j].exist)
				{
			        mdc1->SelectObject(mask);
			        mdc->BitBlt(fireball[j].x,fireball[j].y,10,10,mdc1,0,0,SRCAND);
			        mdc1->SelectObject(fire);
			        mdc->BitBlt(fireball[j].x,fireball[j].y,10,10,mdc1,0,0,SRCPAINT);
			        fireball[j].x+=fireball[j].vx;
			        fireball[j].y+=fireball[j].vy;
			        fireball[j].lasted++;
			        if(fireball[j].x<=-10 || fireball[j].x>rect.right || fireball[j].y<=200 || fireball[j].y>400 || fireball[j].lasted>10)
					{
				        fireball[j].exist = false;   //出界或超时处理
				        count--;                    
					}
				}
			}
		}
		mark=0;
		dra[i].x+=v[i];
	    dra[i].y+=0;
	}

	/*for(i=0;i<3;i++)//随机决定下次方向
	{
		switch(rand()%4)
		{
		case 0:dra[i].x+=40;dra[i].y+=0;break;//右
		case 1:dra[i].x-=40;dra[i].y+=0;break;//左
		//case 2:dra[i].y+=10;dra[i].x+=0;break;//上
		//case 3:dra[i].y-=10;dra[i].x+=0;break;//下
		}
		if(dra[i].x>640)
			dra[i].x=640;
		if(dra[i].x<0)
			dra[i].x=0;
		if(dra[i].y>400)
			dra[i].y=400;
		if(dra[i].y<160)
			dra[i].y=160;			
	}*/
	if(count<50)
		{
		    drop[count].x = rand()%rect.right;//在窗口宽度范围内随机确定下落点
		    drop[count].y = 0;
		    drop[count].exist = true;
		    count++;
		}
	    for(i=0;i<50;i++)
		{
		    if(drop[i].exist)
			{
			    mdc1->SelectObject(mask);
			    mdc->BitBlt(drop[i].x,drop[i].y,20,20,mdc1,0,0,SRCAND);
			    mdc1->SelectObject(snow);
			    mdc->BitBlt(drop[i].x,drop[i].y,20,20,mdc1,0,0,SRCPAINT);
			    if(rand()%2==0)//随机设置雪花左右摆动
				    drop[i].x+=3;
			    else 
				    drop[i].x-=3;
			    drop[i].y+=10;
			    if(drop[i].y > rect.bottom)
				{
				    drop[i].x = rand()%rect.right;//到底后，重新随机设定下落位置
				    drop[i].y = 0;
				}
			}
		}
	
	dc.BitBlt(0,0,rect.right,rect.bottom,mdc,0,0,SRCCOPY);

	
//	CFrameWnd::OnTimer(nIDEvent);
}

int canvasFrame::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	SetTimer(1,100,NULL);
	return 0;
}
void canvasFrame::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	if(nChar==VK_ESCAPE)
		canvasFrame::~canvasFrame();
	if(nChar==VK_RETURN)
	{
	    if(count<50)
		{
		    drop[count].x = rand()%rect.right;//在窗口宽度范围内随机确定下落点
		    drop[count].y = 0;
		    drop[count].exist = true;
		    count++;
		}
	    CClientDC dc(this);
	    mdc1->SelectObject(bgbmp);
	    mdc->BitBlt(0,0,rect.right,rect.bottom,mdc1,0,0,SRCCOPY);
	    for(i=0;i<50;i++)
		{
		    if(drop[i].exist)
			{
			    mdc1->SelectObject(mask);
			    mdc->BitBlt(drop[i].x,drop[i].y,20,20,mdc1,0,0,SRCAND);
			    mdc1->SelectObject(snow);
			    mdc->BitBlt(drop[i].x,drop[i].y,20,20,mdc1,0,0,SRCPAINT);
			    if(rand()%2==0)//随机设置雪花左右摆动
				    drop[i].x+=3;
			    else 
				    drop[i].x-=3;
			    drop[i].y+=10;
			    if(drop[i].y > rect.bottom)
				{
				    drop[i].x = rand()%rect.right;//到底后，重新随机设定下落位置
				    drop[i].y = 0;
				}
			}
		}

	for(i=0;i<3;i++)
	{
		dra[i].x+=v[i];
	    dra[i].y+=0;
		mdc1->SelectObject(black);
		mdc->BitBlt(dra[i].x,dra[i].y,20,20,mdc1,0,0,SRCAND);
		mdc1->SelectObject(ball[i]);
		mdc->BitBlt(dra[i].x,dra[i].y,20,20,mdc1,0,0,SRCPAINT);
    }

	for(i=0;i<3;i++)//碰撞检测
	{
		if(abs(dra[i+1].x-dra[i].x)<20)
		{
			v[i]=-v[i];
		    v[i+1]=-v[i+1];
			mark=1;	
		}
		if(dra[i].x>600)
		{
			dra[i].x=600;
			v[i]=-v[i];
		}
		if(dra[i].x<0)
		{
			dra[i].x=0;
			v[i]=-v[i];
		}
		if(mark==1)
		{	
		    if(count == 0)              //10个小火球都不存在--熄灭或飞出窗口，创建一个烟花的50个小火球
			{
		        x=dra[i].x;//中心在窗口内随机设定
		        y=dra[i].y;
		        for(j=0;j<10;j++)       
				{
			        fireball[j].x = x;
			        fireball[j].y = y;
			        fireball[j].lasted = 0;
			        if(j%4==0)//分4个象限
					{
				        fireball[j].vx =  -rand()%10;//速度和方向同时随机确定
				        fireball[j].vy =  -rand()%10;
					}
			        if(j%4==1)
					{
				        fireball[j].vx = rand()%10;
				        fireball[i].vy = rand()%10;
					}
			        if(j%4==2)
					{
				        fireball[j].vx = -rand()%10;
				        fireball[j].vy = rand()%10;
					}
			        if(j%4==3)
					{
				        fireball[j].vx = rand()%10;
				        fireball[j].vy = -rand()%10;
					}
			        fireball[j].exist = true;
				}
		        count = 10;
			}
			for(j=0;j<10;j++)
			{
		        if(fireball[j].exist)
				{
			        mdc1->SelectObject(mask);
			        mdc->BitBlt(fireball[j].x,fireball[j].y,10,10,mdc1,0,0,SRCAND);
			        mdc1->SelectObject(fire);
			        mdc->BitBlt(fireball[j].x,fireball[j].y,10,10,mdc1,0,0,SRCPAINT);
			        fireball[j].x+=fireball[j].vx;
			        fireball[j].y+=fireball[j].vy;
			        fireball[j].lasted++;
			        if(fireball[j].x<=-10 || fireball[j].x>rect.right || fireball[j].y<=200 || fireball[j].y>400 || fireball[j].lasted>10)
					{
				        fireball[j].exist = false;   //出界或超时处理
				        count--;                    
					}
				}
			}
		}
		mark=0;
	}

	dc.BitBlt(0,0,rect.right,rect.bottom,mdc,0,0,SRCCOPY);
	}
	//CFrameWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}