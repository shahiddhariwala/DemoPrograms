//Region Fill & Boundary Fill
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <math.h>
#include <graphics.h>
void BoundaryFill(int x,int y,int fill,int bound)
{
	//filling color fill
	//boundary color bound
	int current;
	current = getpixel(x,y);
	if(current != bound && current != fill)
	{
		putpixel(x,y,fill);
		BoundaryFill(x,y+1,fill,bound);
		BoundaryFill(x+1,y,fill,bound);
		BoundaryFill(x-1,y,fill,bound);
		BoundaryFill(x,y-1,fill,bound);

	}
}
void FloodFill(int x,int y,int fill,int oldcolor)
{
	//filling color fill
	//background color oldcolor
	int current;
	current = getpixel(x,y);
	if(current == oldcolor)
	{
		putpixel(x,y,fill);
		FloodFill(x,y+1,fill,oldcolor);
		FloodFill(x,y-1,fill,oldcolor);
		FloodFill(x+1,y,fill,oldcolor);
		FloodFill(x-1,y,fill,oldcolor);

	}
}
void main()
{
	int gd=DETECT,gm,op;
	initgraph(&gd,&gm,"C://Turboc3/BGI");
	clrscr();
	clearviewport();
	printf("Enter the option \n1)floodfill \n2)BoundaryFill \n");
	circle(300,300,20);
	scanf("%d",&op);
	switch(op)
	{
		case 1:
		FloodFill(300,300,12,0);
		break;
		case 2:
		BoundaryFill(300,300,3,15);
		break;
		default:
		printf("Invaid Input");
		break;
	}
	getch();
	closegraph();
}