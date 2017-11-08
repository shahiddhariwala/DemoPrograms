#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <dos.h>

void midcircle(int xc,int yc,int r)
{
	int x,y,p;
	x=0;
	y=r;
	p=(5/4)-r;
	while(x<y)
	{
		putpixel(xc+x,yc+y,9);
		putpixel(xc+x,yc-y,9);
		putpixel(xc-x,yc+y,9);
		putpixel(xc-x,yc-y,9);
		putpixel(xc+y,yc+x,9);
		putpixel(xc+y,yc-x,9);
		putpixel(xc-y,yc+x,9);
		putpixel(xc-y,yc-x,9);
		if(p<0)
		{
			p=p+2*x+2;
			x=x+1;
		}
		else
		{
			p=p+2*(x-y)+5;
			x+=1;
			y-=1;

		}
	}

}

void main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C://Turboc3/BGI");
	clrscr();
	clearviewport();
	midcircle(300,300,60);
	getch();
	closegraph();
}
