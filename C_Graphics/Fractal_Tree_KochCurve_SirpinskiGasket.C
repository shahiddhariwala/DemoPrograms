// Fractal Tree ,Koch Curve ,Serpenski Gasket
#include <conio.h>
#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include <dos.h>

void tree(int x,int y,int n,int l,float angle)
{
	int x1=x+l*cos(angle+(20*M_PI/180));
	int y1=y-l*sin(angle+(20*M_PI/180));
	int x2=x+l*cos(angle-(20*M_PI/180));
	int y2=y-l*sin(angle-(20*M_PI/180));

	if(n>0)
	{
		tree(x1,y1,n-1,l*0.8,angle+(20*M_PI/180));
		tree(x2,y2,n-1,l*0.8,angle-(20*M_PI/180));
		line(x,y,x1,y1);
		line(x,y,x2,y2);
	}
}

void koch(int x1,int y1,int x2,int y2,int n)
{
	float angle=60*M_PI/180;
	int x3=(2*x1+x2)/3;
	int y3=(2*y1+y2)/3;

	int x4=(x1+2*x2)/3;
	int y4=(y1+2*y2)/3;

	int x=x3+(x4-x3)*cos(angle)+(y4-y3)*sin(angle);
	int y=y3-(x4-x3)*sin(angle)+(y4-y3)*cos(angle);

	if(n>0)
	{
		koch(x1,y1,x3,y3,n-1);
		koch(x3,y3,x,y,n-1);
		koch(x,y,x4,y4,n-1);
		koch(x4,y4,x2,y2,n-1);
	}
	else
	{
		line(x1,y1,x3,y3);
		line(x3,y3,x,y);
		line(x,y,x4,y4);
		line(x4,y4,x2,y2);
	}
}

void Sierpinski(int x1,int y1,int x2,int y2,int x3,int y3,int n)
{
	int xa,xb,xc,ya,yb,yc;
	xa=(x1+x2)/2;
	ya=(y1+y2)/2;
	xb=(x1+x3)/2;
	yb=(y1+y3)/2;
	xc=(x3+x2)/2;
	yc=(y3+y2)/2;
	if(n>0)
	{
		Sierpinski(x1,y1,xa,ya,xb,yb,n-1);
		Sierpinski(xa,ya,x2,y2,xc,yc,n-1);
		Sierpinski(xc,yc,xb,yb,x3,y3,n-1);
		line(x1,y1,x2,y2);
		line(x2,y2,x3,y3);
		line(x3,y3,x1,y1);
	}
}

void main()
{
	int op,gd=DETECT,gm,bran,x1,y1,x2,y2,degree;
	float angle = 90*M_PI/180;
	initgraph(&gd,&gm,"C://Turboc3/BGI");
	clrscr();
	clearviewport();
	printf("Enter the Option \n1 Fractal Tree \n2 Koch Curve \n3 Sierpinski Gasket \n");
	scanf("%d",&op);

	switch(op)
	{
		case 1:
		//Fractal Tree
		clearviewport();
		printf("Enter the Cordinates of Trunk\n");
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		printf("Enter the Number of Branches:\n");
		scanf("%d",&bran);
		line(x1,y1,x2,y2);
		tree(x1,y1,bran,y2-y1,angle);
		break;
		case 2:
		clearviewport();
		//Koch Curve
		printf("Enter the Coordinates of Line \n");
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		printf("Enter the Degree:\n");
		scanf("%d",&degree);
		koch(x1,y1,x2,y2,degree);
		break;
		case 3:
		printf("Enter the Degree \n");
		scanf("%d",&degree);
		Sierpinski(300,300,500,300,400,150,degree);
		break;

	}
	getch();
	closegraph();
}