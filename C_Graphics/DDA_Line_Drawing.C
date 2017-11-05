//Shahid Dhariwala CG Program1
#include <stdio.h>
#include <graphics.h>
#include <dos.h>
#include <math.h>
int abs(int x)
{
if(x<0)
	x = x * (-1);
return x;
}

void dda(int x1,int y1,int x2,int y2)
{
	int i=0,l,dx,dy;
	float xn,yn,xnew,ynew;
	dx=x2-x1;
	dy=y2-y1;
	if(abs(dx) > abs(dy))
		l=abs(dx);
	else
		l=abs(dy);
	xn=(float) (x2-x1)/l;
	yn=(float) (y2-y1)/l;
	xnew=x1;
	ynew=y1;
	putpixel(x1,y1,WHITE);
	while(i<=l)
	{
		xnew=xnew+xn;
		ynew=ynew+yn;
		putpixel(ceil(xnew),ceil(ynew),WHITE);
		i++;
	}

}
void main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C://Turboc3/BGI");
	clrscr();
	dda(100,100,200,100);
	dda(100,100,200,200);
	dda(200,200,200,100);
	getch();
	closegraph();
}