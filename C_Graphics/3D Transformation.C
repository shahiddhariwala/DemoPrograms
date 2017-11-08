#include<stdio.h>
#include<math.h>
#include<graphics.h>
#include<conio.h>

void axis();
void Translation();
void Scaling();
void Rotation();

int x,y;
int x1=10,y1=10,x2=30,y2=30,dif=(20/4);

void main()
{
	int choice;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\turboc3\\bgi");
	printf("Enter Your Choice:\n");
	printf("1.Translation\n2.Scaling\n3.Rotation\n");
	scanf("%d",&choice);

	switch(choice)
	{
		case 1: Translation();
		break;
		case 2: Scaling();
		break;
		case 3: Rotation();
		break;
	}
	getch();
	closegraph();
}
void axis()
{
	x=getmaxx();
	y=getmaxy();
	line(0,y/2,x,y/2);
	line(x/2,0,x/2,y);
	x=x/2;
	y=y/2;
}

void Translation()
{
	int tx,ty;
	axis();
	bar3d(x+x1,y-y1,x+x2,y-y2,dif,1);
	printf("Enter the Translation Factor:\n");
	scanf("%d %d",&tx,&ty);
	bar3d(x+(x1+tx),y-(y1+ty),x+(x2+tx),y-(y2+ty),dif,1);
}

void Scaling()
{
	int sx,sy,sz;
 /*printf("Enter the scaling factor:\n");
 scanf("%d%d%d",&sx,&sy&sz); */
	axis();
	bar3d(x+x1,y-y1,x+x2,y-y2,dif,1);
	printf("Enter the scaling factor:\n");
	scanf("%d%d%d",&sx,&sy,&sz);
	bar3d(x+(x1*sx),y-(y1*sy),x+(x2*sx),y-(y2*sy),dif*sz,1);
}

void Rotation()
{
	float t,x11,y11,x22,y22;
	int r,choice;
	axis();
	bar3d(x+x1,y-y1,x+x2,y-y2,dif,1);
	printf("Enter the angle of Rotaion:\n");
	scanf("%d",&r);
	t=3.14*r/180;
	x11=x1*cos(t)-y1*sin(t);
	y11=x1*sin(t)+y1*cos(t);
	x22=x2*cos(t)-y2*sin(t);
	y22=x2*sin(t)+y2*cos(t);
	printf("Select the Rotaton about:\n1.X-axis\n2.Y-axis\n3.Z-axis");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:bar3d(x+x1,y-x11,x+x2,y-x22,dif,1);
		break;
		case 2:bar3d(x+x11,y-y1,x+x22,y-y2,dif,1);
		break;
		case 3:bar3d(x+x11,y-y11,x+x22,y-y22,dif,1);
		break;
	}

}