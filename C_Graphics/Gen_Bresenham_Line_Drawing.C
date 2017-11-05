//Shahid Dhariwala Generalised Bresenham Line Clipping Algorithm
#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <dos.h>
void gbresenham(int x1,int y1,int x2,int y2)
{
	int ch,dx,dy,x,y,s1,s2,temp,ex=0,p,i;
	dx=abs(x2-x1);
	dy=abs(y2-y1);
	x=x1;
	y=y1;
	s1=x2-x1;
	s2=y2-y1;
	if(s1<0)
		s1=-1;
	else if(s1>0)
		s1=1;
	if(s2<0)
		s2=-1;
	else if(s2>0)
		s2=1;
	if(dy>dx)
	{
		temp=dx;
		dx=dy;
		dy=temp;
		ex=1;
	}
	else  
	{
		ex=0;  
	}
	p=(2*dy)-dx;
	putpixel(x,y,WHITE);
	for(i=1;i<=dx;i++)
	{
		while(p>=0)
		{
			if(ex==1)
				x+=s1;
			else
				y+=s2;
			p-=(2*dx);
		}
		if(ex==1)
			y+=s2;
		else
			x+=s1;
		p+=(2*dy);
		putpixel(x,y,WHITE);
	}


}

void main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C://Turboc3/BGI");
	clrscr();
	clearviewport();
	//boat
	gbresenham(20,80,80,80);
	gbresenham(00,40,100,40);
	gbresenham(00,40,20,80);
	gbresenham(100,40,80,80);
	gbresenham(80,40,100,10);
	gbresenham(100,10,100,40);
	gbresenham(100,10,100,40);
	
	getch();
	closegraph();
}
